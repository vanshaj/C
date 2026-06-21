#include <arpa/inet.h>
#include <asm-generic/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define ANSWER_LEN 10

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
  // A socket is a fundamental concept in network programming that provides a mechanism for communication between two machines over a network
  // The socket function creates a socket and returns its file descriptor.
  // SOCK_STREAM -> TCP SOCKETS
  int listener_d = socket(PF_INET, SOCK_STREAM, 0);
  if (listener_d == -1){
    puts("can't open socket");
    return -1;
  }

  /*
  Structure to specify and endpoint address to which socket is bound
  struct sockaddr_in {
    sa_family_t    sin_family;  // Address family (AF_INET for IPv4)
    in_port_t      sin_port;    // Port number (must be in network byte order) so use htons
    struct in_addr sin_addr;    // Internet address (in_addr structure)
    char           sin_zero[8]; // Padding to make the structure the same size as sockaddr
  };
  This structure is defined in the <netinet/in.h> header file and is used for IPv4 addresses.
   */
  struct sockaddr_in name;
  name.sin_family = PF_INET;
  // htons (host to network short)
  name.sin_port = (in_port_t)htons(30000);
  // sind_addr contains IP address it has one field s_addr that container IPv4 address should also be in network byte order htonl(host to network long)
  name.sin_addr.s_addr = htonl(INADDR_ANY);
  /* reuse socket if restart 
   * The SO_REUSEADDR option allows a socket to bind to a port that is in a TIME_WAIT state, meaning it was recently used by another socket but is still in the process of closing
   SO_REUSEADDR means Reuse address that is already bind to a socket
   SOL_SOCKET: This indicates that the option is a socket-level option. The SOL_SOCKET level applies to options that are protocol-independent.
  */
  int reuse = 1;
  if (setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int))){
    puts("can't set to reuse");
    close(listener_d);
    return -1;
  }
  // bind assosciates a socket with the specific IP and port
  int c = bind(listener_d, (struct sockaddr *)&name, sizeof(name));
  if (c == -1){
    puts("can't bind socket");
    close(listener_d);
    return -1;
  }

  // For TCP server sockets, the listen() system call marks the socket as a passive socket, which means it will be used to accept incoming connection requests.
  if (listen(listener_d, 10) == -1){
    puts("can't listen");
    close(listener_d);
    return -1;
  }
    /* The accept() system call is used to accept an incoming connection request, returning a new socket file descriptor for the connection.
    * sockaddr_storage is a structure in C that is designed to be large enough to hold any type of socket address.
    * It is typically used to handle socket addresses in a protocol-independent manner, making it possible to write code that can work with different address families (such as IPv4 and IPv6) without knowing the specific details of each one.
    */

  struct sockaddr_storage client_addr;
  unsigned int address_size = sizeof(client_addr);
  while(1){
    // Send message to the server you want to send
    int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
    if (connect_d == -1){
      puts("can't open secondary socket");
      return -1;
    }

    if(!fork()) {
      // child will have no use of this, child will only use connect_d socket to talk to client
      close(listener_d);

      char *message = "What is your name?\n";
      int status = sendData(connect_d, message, strlen(message));
      if (status == -1) {
        puts("Can't send data to socket");
        close(connect_d);
        return -1;
      }
      char name[ANSWER_LEN];
      int status_read = read_in(connect_d, name, ANSWER_LEN);
      if (status_read == -1) {
        puts("Can't read data to socket");
        close(connect_d);
        return -1;
      }
      char *expectedName = "Bharat";
      if (strcmp(name, expectedName) == 0){
        char greet[30];
        sprintf(greet, "Hello %s\n", name);
        int status = sendData(connect_d, greet, strlen(greet));
        if (status == -1) {
          puts("Can't send data to socket");
          close(connect_d);
          return -1;
        }
      } else {
        char *bye = "Bye not allowed\n";
        int status = sendData(connect_d, bye, strlen(bye));
        if (status == -1){
          puts("Can't send data to socket");
          close(connect_d);
          return -1;
        }
      }
      // Once the conversation is done, client will close the secondary socket created by accept call
      close(connect_d);
      return 0;
    }
      // Parent will not need connect_d socket as it is not talking to client
      close(connect_d);
  }
  return 0;
}
