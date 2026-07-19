#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<sys/socket.h>
#include <netinet/in.h>
#include<stdlib.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CON_QUEUE 128


int main(int argc, char const *argv[])
{
    char data_buf[BUFFER_SIZE];
    int enable = 1;
    struct sockaddr_in addr;


    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Unable to create socket fd");
        exit(EXIT_FAILURE);
    }
    int flags = fcntl(sock_fd, F_GETFL, 0);
    if (flags < 0) {
        perror("Unable to get socket flags");
        exit(EXIT_FAILURE);
    }
    if (fcntl(sock_fd, F_SETFL, flags | O_NONBLOCK) < 0) {
        perror("Unable to set non block for listening socket");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    int addrlen = sizeof(addr);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if (bind(sock_fd, (struct sockaddr *) &addr, addrlen) < 0) {
        perror("Unable to bind socket");
        exit(EXIT_FAILURE);
    }

    if (listen(sock_fd, MAX_CON_QUEUE) < 0) {
        perror("Unable to listen on socket");
        exit(EXIT_FAILURE);
    }
    printf("Server is listening on port %d...\n", PORT);

    int new_sock_fd;
    while (1) {
        new_sock_fd = accept(sock_fd, (struct sockaddr *) &addr, (socklen_t*) &addrlen);
        if (new_sock_fd < 0) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                usleep(10000);
                continue;
            }
            perror("Unable to accept connection on socket");
            exit(EXIT_FAILURE);
        }
        break;
    }


    int n = read(new_sock_fd, data_buf, BUFFER_SIZE);
    if (n < 0) {
        perror("Unable to read data from the socket");
        exit(EXIT_FAILURE);
    }
    if (write(STDOUT_FILENO, data_buf, n) != n) {
        perror("Unable to write data to the stdout");
        exit(EXIT_FAILURE);
    }
    char response[30] = "Get Lost don't try to connect\n";
    if (send(new_sock_fd, response, 30, 0) != 30) {
        perror("Unable to send response back to the socket");
        exit(EXIT_FAILURE);
    }
    close(new_sock_fd);
    close(sock_fd);

    return 0;
}
