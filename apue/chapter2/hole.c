/*
 * This simple program creates a file with a hole in it, a so-called
 * sparse file.  Use hexdump(1) or od(1) to verify that there is no data
 * in between the two strings; then copy the file to to another and
 * observe that the kernel supplied zeros to fill the hole.
 */

/*
* Create a file
* Write some text to it
* move to far place in file
* Write some other text
* Close the file
*/
#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include <unistd.h>


char a[] = "abcdefghijkl";
char b[] = "ABCDEFGHIJKL";

#define BIGNUM 10240000

int main(int argc, char *argv[])
{
  int fd = open("./data/hole.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR );
  if (fd < 0) {
    printf("Failed due to error: %s\n", strerror(errno));
  }
  if( write(fd, a, strlen(a)) != sizeof(a) - 1 ) { // why -1 because sizeof will include '\0' as well
    printf("unable to write whole bytes\n");
    exit(EXIT_FAILURE);
  }
  if (lseek(fd, BIGNUM, SEEK_CUR) == -1){
    printf("Unable to move to position\n");
    exit(EXIT_FAILURE);
  }
  if( write(fd, b, strlen(b)) != sizeof(b) - 1 ) { // why -1 because sizeof will include '\0' as well
    printf("unable to write whole bytes\n");
    exit(EXIT_FAILURE);
  }
  (void)close(fd);
  return EXIT_SUCCESS;
}
