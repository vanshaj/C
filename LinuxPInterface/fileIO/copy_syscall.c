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
  ssize_t numRead;
  size_t BUFFER_SIZE = 1024;
  if (argc != 3) {
    puts("Invalid number of arguments");
    exit(EXIT_FAILURE);
  }

  char buf[BUFFER_SIZE];

  openFlags = O_CREAT | O_WRONLY | O_TRUNC;
  filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;


  inputFd = open(argv[1], O_RDONLY);
  if (inputFd == -1){
    printf("Failed to open file due to %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  /*outputFd = open(argv[2], openFlags, filePerms);*/
  outputFd = open(argv[2], openFlags, 0644);
  if (outputFd == -1) {
        perror("Failed to open destination file");
        close(outputFd);
        exit(EXIT_FAILURE);
    }

  while((numRead = read(inputFd, buf, BUFFER_SIZE)) > 0){
    printf("Bytes read are %ld\n", (long) numRead);
    if(write(outputFd, buf, numRead) != numRead){
      printf("Unable to write whole buffer\n");
    }
  }
  if (numRead == -1) {
    printf("Unable to read from input due to %s", strerror(errno));
  }
  if (close(inputFd) == -1){
    printf("Unable to close file %s due to %s\n", argv[1], strerror(errno));
    exit(EXIT_FAILURE);
  }
  if (close(outputFd) == -1){
    printf("Unable to close file %s due to %s\n", argv[2], strerror(errno));
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}
