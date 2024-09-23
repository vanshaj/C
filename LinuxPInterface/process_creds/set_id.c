#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(){
  int rc = setresuid(-1, -1, 0);
  if (rc == -1) {
    printf("Unable to set effective uid due to error '%s'\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  int euid = geteuid();
  printf("Effective uid or the process %d\n", euid);
  FILE *f = fopen("/etc/shadow", "r");
  if (errno < 0 || f == NULL) {
    printf("Unable to open file due to error '%s'\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  size_t BUF_SIZE = 1024;
  int numBytes, numWrite;
  char buffer[BUF_SIZE];
  while((numBytes = fread(buffer, sizeof(buffer[0]), BUF_SIZE, f)) > 0){
    numWrite  = fwrite(buffer, sizeof(buffer[0]), numBytes, stdout);
    if (numBytes != numWrite) {
      printf("Unable to write due to error %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
  }
  if (numWrite == -1) {
    printf("Unable to read due to error %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  return 0;
}
