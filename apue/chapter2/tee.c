#include<fcntl.h>

#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>


#define BUFSIZE 4096

int main(int argc, char *argv[])
{
  char buf[BUFSIZE];
  char *outfilename = argv[2];
  char *filename = argv[1];
  int save_termfd = dup(STDOUT_FILENO);
  if (save_termfd == -1) { perror(strerror(errno));
    exit(EXIT_FAILURE);
  }
  int f_fd = open(filename, O_RDONLY);
  if (f_fd == -1) {
    perror(strerror(errno));
    exit(EXIT_FAILURE);
  }
  int n = read(f_fd, buf, BUFSIZE);
  (void)close(f_fd);
  if (n == -1) {
    perror(strerror(errno));
    exit(EXIT_FAILURE);
  }
  int tee_fd = open(outfilename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
  if (tee_fd == -1) {
    perror(strerror(errno));
    exit(EXIT_FAILURE);
  }
  if (dup2(tee_fd, STDOUT_FILENO) == -1) {
    perror(strerror(errno));
    (void)close(tee_fd);
    exit(EXIT_FAILURE);
  }
  if (write(tee_fd, buf, BUFSIZE) != n) {
    printf("Unable to write all content\n");
  }
  if (write(save_termfd, buf, BUFSIZE) != n) {
    printf("Unable to write all content\n");
  }
  (void)close(tee_fd);
  return EXIT_SUCCESS;
}
