#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>


int main(){
  /*
    uid_t ruid, euid, suid;
    int c;
    if ((c = setresuid(-1, -1, 0)) == -1){
      printf("Unable to set suid due to error '%s'\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
    if (getresuid(&ruid, &euid, &suid) == -1) {
        perror("getresuid");
        return 1;
    }
    printf("Effective uid or the process %d\n", euid);
    printf("Real uid or the process %d\n", ruid);
    printf("Saved set uid or the process %d\n", suid);
  */
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
