# Multi-Client TCP Server (Edge-Triggered epoll) — Project Reference

Goal: Build a scalable multi-client TCP server in C using edge-triggered epoll,
then extend it into an HTTP server with route handling.

---

## Phase 1 — Multi-client TCP Server (epoll, ET)

### Step 1 — Basic listening socket setup
1. `socket(AF_INET, SOCK_STREAM, 0)`
2. Set `SO_REUSEADDR` (and optionally `SO_REUSEPORT`) via `setsockopt()`
3. `bind()` to address/port
4. `listen()` with a backlog
5. Set the listening socket **non-blocking**: `fcntl(fd, F_SETFL, O_NONBLOCK)`
   — required for ET correctness

### Step 2 — Create the epoll instance
6. `epoll_create1(0)`
7. Register listening socket: `epoll_ctl(EPOLL_CTL_ADD)`
8. Confirmed choice: **Edge-Triggered (ET)** — `EPOLLIN | EPOLLET`

### Step 3 — Event loop
9. `epoll_wait()` in a loop
10. Listening fd ready → `accept()` in a `while(1)` loop until `EAGAIN`/`EWOULDBLOCK`
    (ET only signals once — must drain all pending connections)
11. Set each new client fd non-blocking, add to epoll with `EPOLLIN | EPOLLET`
12. Client fd ready for read → `recv()` **in a loop** until `EAGAIN`
13. `recv() == 0` → client disconnected → `epoll_ctl(EPOLL_CTL_DEL)` + `close()` + free struct
14. `recv() < 0` with `EAGAIN`/`EWOULDBLOCK` → not an error, just stop reading for now

### Step 4 — Per-client state (struct design — DECIDED)

```c
#define READ_BUF_SIZE   4096

typedef enum {
    CONN_STATE_ACTIVE,
    CONN_STATE_CLOSING   // draining writes before close
} conn_state_t;

typedef struct client_conn {
    int fd;

    // --- read side ---
    char read_buf[READ_BUF_SIZE];
    size_t read_len;        // bytes currently valid in read_buf

    // --- write side (for backpressure / EPOLLOUT) ---
    char *write_buf;        // dynamically allocated, grows via realloc
    size_t write_len;       // total bytes queued
    size_t write_sent;      // bytes already sent from write_buf
    size_t write_cap;       // allocated capacity of write_buf

    conn_state_t state;

    struct sockaddr_in addr;   // peer address, for logging

    struct client_conn *next;  // intrusive linked list (chosen storage model)
} client_conn_t;
```

**Design notes:**
- Use `epoll_event.data.ptr = client_conn` (not `data.fd`) — gives direct
  access to full connection state on every event, no fd→struct lookup needed.
- `write_buf` is a pointer, not fixed array, because writes can queue up
  while a client is slow to drain (backpressure).
- `write_sent` vs `write_len`: tracks partial sends separately from total
  queued, since ET writes can also be partial.
- Client storage: **linked list** (simpler to get right than dynamic array
  for a learning project; revisit later if broadcast performance matters).

### Step 5 — Handling writes (backpressure)
15. If `send()` can't write everything → `EAGAIN` → buffer remaining data
    in `write_buf`
16. Register `EPOLLOUT` on that fd; keep it registered until buffer fully
    flushed (`write_sent == write_len`)
17. On `EPOLLOUT` event → drain in a loop until `EAGAIN` or buffer empty,
    same ET looping discipline as reads
18. Once drained → unregister `EPOLLOUT` (avoid busy-looping on writable fd)

### Step 6 — Message framing (pick ONE to start)
19. Raw byte stream has no message boundaries — decide framing before
    building real protocol logic
    - **Delimiter-based (`\n`)** — easiest to test manually with `nc`/`telnet` (recommended first)
    - Length-prefixed (4-byte header + payload) — more robust, use later
    - Fixed-size messages — simplest but rigid
20. Since ET drains the socket fully per event, you may read multiple
    messages (or partial messages) in one `recv` loop — framing logic must
    handle both cases

### Step 7 — Cleanup & signals
21. Ignore `SIGPIPE`: `signal(SIGPIPE, SIG_IGN)` — otherwise writing to a
    closed socket kills the process
22. Graceful shutdown on `SIGINT` — close all client fds, free all structs,
    close epoll fd and listening fd
23. **fd reuse bug**: after `close()`, OS may reuse that fd number
    immediately. Always remove from epoll (`EPOLL_CTL_DEL`) and fully
    free/reset per-client state atomically on disconnect — never leave a
    stale struct associated with a live fd number

### Step 8 — Testing
24. Multiple concurrent `nc`/`telnet` clients
25. Rapid connect/disconnect cycles
26. Slow client simulation to validate `EPOLLOUT` backpressure path
27. Load test — small C client spawning many concurrent connections

---

## Suggested build order (concrete milestones)
1. Listening socket + `epoll_create1` + accept loop skeleton (just log new connections)
2. Non-blocking client fds + `EPOLLIN|EPOLLET` registration
3. Read-until-EAGAIN loop, raw echo back (no framing yet) — test with `nc`
4. Disconnect handling (`recv == 0`) + cleanup
5. Message framing — start with `\n` delimiter
6. Write buffering + `EPOLLOUT` toggle for slow clients
7. Signal handling (`SIGINT`, `SIGPIPE`) + graceful shutdown
8. Stress test

---

## ET-specific rules (never break these)
- Every fd must be non-blocking, always
- Always loop `accept()`/`recv()`/`send()` until `EAGAIN` — one shot per
  event is not enough with ET
- `EAGAIN`/`EWOULDBLOCK` is not an error — just "nothing more right now"
- Never assume a full message == one `recv()` call

---

## Phase 2 — HTTP Server with Route Handling (after Phase 1 is solid)

*(To be detailed once Phase 1 multi-client server is working — will build on
the same epoll/ET foundation, adding HTTP parsing and routing on top.)*

Rough shape for later:
- Reuse the epoll ET event loop and client_conn struct from Phase 1
- Replace `\n`-delimiter framing with HTTP request parsing (request line,
  headers, `\r\n\r\n` terminator, `Content-Length` for body)
- Build a simple router: method + path → handler function
- Generate proper HTTP responses (status line, headers, body)
- Handle keep-alive vs connection-close
- Basic error responses (400, 404, 500)

---

## How to use this file
- Work through milestones in order, writing code yourself
- Come back with specific questions when stuck (compiler errors, logic
  bugs, "why does X happen", design tradeoffs)
- Update this file yourself as you make new decisions (e.g., framing choice,
  storage model changes)