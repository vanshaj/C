#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]){
  for(int i=1; i<argc; i++){
    pid_t pid = fork();
    if (pid == -1) { // when forked the parent process gets pid value as 0
      fprintf(stderr, "Can't fork process due to %s\n", strerror(errno));
      return 1;
    }
    if (pid == 0){
      if(execlp("cat", "cat", argv[i], NULL) == -1){
        fprintf(stderr, "Can't run script to print file due to %s\n", strerror(errno));
        return 1;
      }
    }
  }
}
