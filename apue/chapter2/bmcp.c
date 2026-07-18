#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define BUFSIZE 4096


int main(int argc, char *argv[])
{
  char buf[BUFSIZE];
  char *src_file = argv[1];
  char *dst_file_or_dir = argv[2];

  // Read data from source file to buffer
  int src_fd = open(src_file, O_RDONLY);
  if (src_fd == -1) {
    printf("Unable to open src file");
    perror(strerror(errno));
    exit(EXIT_FAILURE);
  }
  int n_r = read(src_fd, buf, BUFSIZE);
  if (n_r < 0) {
    printf("unable to read from src file");
    perror(strerror(errno));
    exit(EXIT_FAILURE);
  }
  
  struct stat statbuf;
  if (stat(dst_file_or_dir, &statbuf) == -1) {
    printf("Unable to stat destination file");
    perror(strerror(errno));
    exit(EXIT_FAILURE);
  }
  
  // Check if destination is a directory
  if (S_ISDIR(statbuf.st_mode)) {
    // Open directory
    int dir_fd = open(dst_file_or_dir, O_RDONLY | O_DIRECTORY);
    if (dir_fd == -1) {
      printf("Unable to open directory");
      (void)close(src_fd);
      perror(strerror(errno));
      exit(EXIT_FAILURE);
    }
    // Open new file inside dirctory
    int destf_fd = openat(dir_fd, src_file, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (destf_fd == -1) {
      printf("Unable to open destination file in destination directory");
      (void)close(src_fd);
      (void)close(dir_fd);
      perror(strerror(errno));
      exit(EXIT_FAILURE);
    }
    // Write to the destination file from buffer
    if(write(destf_fd, buf, n_r) != n_r) {
      printf("unable to write to dest file");
      (void)close(dir_fd);
      (void)close(destf_fd);
      (void)close(src_fd);
      perror(strerror(errno));
      exit(EXIT_FAILURE);
    }
    // Close dest file and directory both
    (void)close(destf_fd);
    (void)close(dir_fd);

  } else {
    // If destination is a file then open
    int destf_fd = open(dst_file_or_dir, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (destf_fd == -1) {
      printf("Unable to open destination file");
      (void)close(src_fd);
      perror(strerror(errno));
      exit(EXIT_FAILURE);
    }
    // Write to file from the buffer
    if(write(destf_fd, buf, n_r) != n_r) {
      printf("unable to write to dest file");
      (void)close(destf_fd);
      (void)close(src_fd);
      perror(strerror(errno));
      exit(EXIT_FAILURE);
    }
    // Close destination file
    (void)close(destf_fd);
  }

  // Close Source file
  (void)close(src_fd);
  return EXIT_SUCCESS;
}
