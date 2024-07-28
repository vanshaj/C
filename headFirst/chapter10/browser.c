#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

void open_url(char *url) {
    char launch[255];
    sprintf(launch, "x-www-browser '%s' &", url);
    system(launch);
}

int main()
{
    int fd[2];
    /*
     fd[0] read end of the pipe
     fd[1] write end of the pipe
    */
    if (pipe(fd) == -1){
        fprintf(stderr, "Can't fork process due to %s", strerror(errno));
        return 1;
    }
    pid_t pid = fork();
    if (pid == -1){
        fprintf(stderr, "Can't fork process due to %s", strerror(errno));
        return 1;
    }
    /*
    child process will deal with write end of the pipe
    child process will close the read end of the pipe
    */
    if (!pid){
        dup2(fd[1], 1);
        close(fd[0]);
        if (execlp("cat", "cat", "/home/vanshaj/delete/urls.txt", NULL) != -1){
            fprintf(stderr, "Process didnot complete due to %s", strerror(errno));
        }
    }
    /*
    parent process will deal with read end of the pipe
    parent process wil close the write end of the pipe
    */
    else if (pid>0){
        dup2(fd[0], 0);
        close(fd[1]);
        char line[255];
        while (fgets(line, sizeof(line), stdin)) {
            open_url(line);
        }
        return 0;
    }
}
