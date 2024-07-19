#include <wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char *argv[]){
  FILE *fd = fopen("error.log", "w");
 // fileno will give the stream number of the file and dup2 will copy it to stderr so everything written to stderr will be redirected
  dup2(fileno(fd), 2);
  for(int i=0; i<argc; i++) {
    pid_t pid = fork();
    if (pid == -1) {
      fprintf(stderr, "Can't fork the process due to error %s", strerror(errno));
      return 1;
    }
    // The below code block will be executed when the process is child process i.e pid == 0
    if (pid == 0){
      // For example there is one exec that will take some time
      // The process created for that will not wait, it will run in background
      if (i==0){
        if(execlp("sleep", "sleep", "5", NULL) == 0) {
          fprintf(stderr, "Process didnot complete due to %s", strerror(errno));
          return 1;
        }
      }
      if (execlp("cat", "cat", argv[i], NULL) == 0){
        fprintf(stderr, "Can't print file due to error %s", strerror(errno));
        return 1;
      }
    }
    // Here we are writing code to wait for the child process created via fork that is executing long running task
    // This code will be executed in the parent process
    else if (pid > 0) {
      int pid_status;
      if (waitpid(pid, &pid_status, 0) == -1) {
          fprintf(stderr, "Can't wait due to error %s", strerror(errno));
          return 1;
      }
    }
  }
}
