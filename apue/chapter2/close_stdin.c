/*
 * This program illustrates that you an close the default
 * standard I/O filedescriptors.  To reopen, you then need
 * to explicitly open the terminal device and dup(2) the
 * descriptor onto it.
 *
 * Note: as of 2024-09-15, on macOS Sonoma 14.6.1, the
 * restored stderr does not seem to work.  There,
 * 	freopen("/dev/tty", "w+", stderr)
 * appears to be necessary.
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

#define BUFSIZE 4096

int main(int argc, char *argv[])
{
  char buf[BUFSIZE];
  /*
  If this code is present dup2 will not work
  int val = close(STDIN_FILENO);
  if (val == -1) {
    fprintf(stderr, "Failed due to error %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  */
  int termdup = dup(STDIN_FILENO);
  (void)close(STDIN_FILENO);
  if (termdup == -1) {
    fprintf(stderr, "Failed due to error %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  } else {
    printf("Enter something to be read to buffer\n");
    ssize_t n = read(termdup, buf, BUFSIZE);
    if (n > 0) {
      buf[n] = '\0';
      printf("You typed: %s", buf);
    }
    (void)close(termdup);
  }
  return EXIT_SUCCESS;
}
