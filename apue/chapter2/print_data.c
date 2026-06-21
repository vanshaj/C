#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

void multiple_writes(const char* filename) {
    char *input_txt_1 = "Hello this is from code";
    char *input_txt_2 = "Bye this is from code";

    int fd_open = open(filename, O_RDWR | O_CREAT, S_IRGRP | S_IWGRP | S_IRUSR | S_IWUSR);
    printf("File descriptor of file opened by open() is: %d\n", fd_open);
    write(fd_open, input_txt_1, strlen(input_txt_1));
    close(fd_open);
    
    FILE* fd_fopen = fopen(filename, "w+");
    // If not closed by close(fd_open), it will create a new file_descriptor otherwise same
    printf("File descriptor of file opened by fopen() is %d\n", fileno(fd_fopen));
    write(fileno(fd_fopen), input_txt_2, strlen(input_txt_2));
    fclose(fd_fopen);

}

void read_write_sim(const char* filename) {
    char BUF_READ[100];
    char *new_input_text = "New one line\n";
    int fd_open = open(filename, O_RDWR | O_CREAT, S_IRGRP | S_IWGRP | S_IRUSR | S_IWUSR);
    read(fd_open, BUF_READ, 100);
    printf("%s\n", BUF_READ);
    write(fd_open, new_input_text, strlen(new_input_text));
    close(fd_open);
}

int main() {
    printf("InFileNo: %d\n", STDIN_FILENO);
    printf("OutFileNo: %d\n", STDOUT_FILENO);
    printf("ErrFileNo: %d\n", STDERR_FILENO);

    // fileno is used to get file descriptor of a File*
    printf("FD stdin: %d\n", fileno(stdin));
    printf("FD stdout: %d\n", fileno(stdout));
    printf("FD stderr: %d\n", fileno(stderr));

    const char* env_name = "HOME";
    const char* homedir = getenv(env_name);
    const char* path = "/tmp/myfile.txt";

    char *filename = malloc(strlen(homedir) + strlen(path) + 1);
    strcpy(filename, homedir);
    strcat(filename, path);
    // multiple_writes(filename);
    read_write_sim(filename);
    free(filename);
    return 0;
}