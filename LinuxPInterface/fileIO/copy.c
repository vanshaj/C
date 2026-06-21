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
  FILE *inFStream = fopen(argv[1], "rb");
  FILE *outFStream = fopen(argv[2], "wb");
  while((numRead = fread(buf, sizeof(buf[0]), BUFFER_SIZE, inFStream)) > 0){
    fwrite(buf, sizeof(buf[0]), numRead, outFStream);
  }
  if (numRead == -1) {
    printf("Unable to read from input because of error %s", strerror(errno));
  }
  if (fclose(inFStream) == -1){
    printf("Unable to close file %s due to %s\n", argv[1], strerror(errno));
    exit(EXIT_FAILURE);
  }
  if (fclose(outFStream) == -1){
    printf("Unable to close file %s due to %s\n", argv[2], strerror(errno));
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}
