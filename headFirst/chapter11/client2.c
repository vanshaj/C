#include <string.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define MSG_LENGTH 80

int sendData(int socket, const char *msg, int bufLen) {
    if (send(socket, msg, bufLen, 0) == -1) {
        perror("send failed");
        close(socket);
        return -1;
    }
    return 0;
}

int read_in(int socket, char *buf, int len) {
    char *s = buf;
    int slen = len;
    int c;

    while (slen > 0) {
        c = recv(socket, s, slen, 0);
        if (c <= 0) {
            if (c < 0) perror("recv failed");
            return (c < 0) ? c : 0;
        }
        
        // Adjust the buffer and remaining length
        s += c;
        slen -= c;

        // Check for newline character to end the loop
        if (strchr(buf, '\n')) break;
    }

    // Ensure null termination
    if (slen > 0) {
        *s = '\0';
    } else {
        buf[len - 1] = '\0';  // In case of buffer overflow, ensure null termination
    }

    return len - slen;
}

int main() {
    struct addrinfo *res;
    struct addrinfo hints;

    // Initialize hints to 0
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    // Resolve address
    if (getaddrinfo("127.0.0.1", "30000", &hints, &res) != 0) {
        perror("getaddrinfo failed");
        return 1;
    }

    // Create socket
    int s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (s == -1) {
        perror("socket creation failed");
        freeaddrinfo(res);
        return 1;
    }

    // Connect to server
    if (connect(s, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect failed");
        close(s);
        freeaddrinfo(res);
        return 1;
    }

    char msg[MSG_LENGTH];
    if (read_in(s, msg, MSG_LENGTH) < 0) {
        close(s);
        freeaddrinfo(res);
        return 1;
    }

    // Print message
    puts(msg);

    // Send data
    const char *name = "akhil";
    if (sendData(s, name, strlen(name)) == -1) {
        close(s);
        freeaddrinfo(res);
        return 1;
    }

    // Read data
    if (read_in(s, msg, MSG_LENGTH) < 0) {
        close(s);
        freeaddrinfo(res);
        return 1;
    }

    // Print message
    puts(msg);

    // Clean up
    close(s);
    freeaddrinfo(res);

    return 0;
}

