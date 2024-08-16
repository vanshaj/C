#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>  /* Type definitions used by many programs */
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  int inputFd, outputFd, openFlags;
  mode_t filePerms;
  /*ssize_t numRead;*/
  size_t numRead;
  size_t BUFFER_SIZE = 1024;
  if (argc != 3) {
    puts("Invalid number of arguments");
    exit(EXIT_FAILURE);
  }

  char buf[BUFFER_SIZE];
  FILE *inFd = fopen(argv[1], "rb");
  FILE *outFd = fopen(argv[2], "wb");
  while((numRead = fread(buf, sizeof(buf[0]), BUFFER_SIZE, inFd)) > 0){
    fwrite(buf, sizeof(buf[0]), numRead, outFd);
  }
  if (numRead == -1) {
    printf("Unable to read from input due to %s", strerror(errno));
  }
  if (fclose(inFd) == -1){
    printf("Unable to close file %s due to %s\n", argv[1], strerror(errno));
    exit(EXIT_FAILURE);
  }
  if (fclose(outFd) == -1){
    printf("Unable to close file %s due to %s\n", argv[2], strerror(errno));
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}
