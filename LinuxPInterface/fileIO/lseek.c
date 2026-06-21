#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

/**
  * rlength - Read length bytes from the file, starting at the current file offset, and display them in text form
  * Rlength - Read length bytes from the file, starting at the current file offset, and display them in hexadecimal.
**/
int main(int argc, char *argv[]){
  if (argc < 2) {
    exit(EXIT_SUCCESS);
  }
  int openFlags = O_RDONLY;
  off_t curr;
  ssize_t numRead;
  int fd = open(argv[1], openFlags);
  if (fd == -1){
    printf("Unable to open file due to %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  /**
  * Then will update the location of the file to the start bytes before the END
  * lseek third parameter whence has 3 option
  * SEEK_SET - start of the file
  * SEEK_CUR = current loc of the seek pointer
  * SEEK_END - end loc of the file
  **/ curr = lseek(fd, -10, SEEK_END);
  curr = lseek(fd, 0, SEEK_SET);
  if (curr == -1) {
    printf("Unable to seek file due to %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  char *buf;
  // allocate the size to buffer depending on how much you want to read
  buf = malloc(10);
  // Read bytes from the position that is 10 bytes after the seek
  numRead = read(fd, buf, 10);
  if (numRead == -1){
    printf("Unable to read the file due to %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  puts(buf);
  free(buf);

  return 0;
}
