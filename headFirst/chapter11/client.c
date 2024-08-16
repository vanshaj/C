#include <string.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#define MSG_LENGTH 80

int sendData(int socket, char *msg, int bufLen){
    if (send(socket, msg, bufLen, 0) == -1) {
      puts("Can't send message");
      close(socket);
      return -1;
    }
  return 0;
}

int read_in(int socket, char *buf, int len)
{
    char *s = buf;
    int slen = len;
    int c = recv(socket, s, slen, 0);
    slen -= c;
    // The telnet string received ends in \r\n
    while ((c > 0) && (s[c - 1] != '\n'))
    {
        // Take on account the part of the buffer written
        s += c;
        c = recv(socket, s, slen, 0);
        slen -= c;
    }
    if (c < 0)
        return  c; // There is an error
    else if (c == 0)
        buf[0] = '\0'; // Send back an empty string
    else
        s[c - 2] = '\0'; // Replace the '\r' character with a '\0'
    return len - slen; // Return the bytes read
}

int main(){
  struct addrinfo *res;
  struct addrinfo hints;
  // Will initialize memore of hints with 0
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = PF_INET;
  hints.ai_socktype = SOCK_STREAM;
  getaddrinfo("127.0.0.1", "30000", &hints, &res);
  int s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  int d_sock = connect(s, res->ai_addr, res->ai_addrlen);
  char *name = "akhil";
  char msg[MSG_LENGTH];
  read_in(d_sock, msg, MSG_LENGTH);
  puts(msg);
  sendData(d_sock, name, strlen(name));
  read_in(d_sock, msg, MSG_LENGTH);
  close(d_sock);
  puts(msg);
  freeaddrinfo(res);
}
