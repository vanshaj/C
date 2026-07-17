/*
 * Stripped down version of 'cat', using unbuffered I/O.
 * ./simple-cat < simple-cat.c
 *
 * Guess what, this is also a primitive version of 'cp':
 * ./simple-cat <simple-cat.c >simple-cat.copy
 */
#include<unistd.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>

#ifndef BUFSIZE
#define BUFSIZE 32768
#endif

int main(int argc, char **argv) {
    int n;
    char buf[BUFSIZE];
    while((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0) {
        if(write(STDOUT_FILENO, buf, n) != n) {
            fprintf(stderr, "Unable to write : %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
    if (n < 0) {
        fprintf(stderr, "Unable to read complete file : %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return(EXIT_SUCCESS);
}
