#include <fcntl.h>      // For open()
#include <unistd.h>     // For read(), write(), close(), dup2()
#include <stdlib.h>     // For exit(), EXIT_FAILURE, EXIT_SUCCESS
#include <string.h>     // For strlen()
#include <errno.h>      // For errno

#define BUF_SIZE 1024

void handle_error(const char *msg) {
    write(STDERR_FILENO, msg, strlen(msg));
    write(STDERR_FILENO, "\n", 1);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int infile_fd = open("data.txt", O_RDWR);
    // Open the file specified in write mode (create if it doesn't exist, truncate if it does).
    int file_fd = open("outdata.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_fd == -1) {
        handle_error("Error opening the file");
    }

    // Duplicate stdout (fd 1) to a new file descriptor, so we can write to both
    int stdout_copy_fd = dup(STDOUT_FILENO);
    if (stdout_copy_fd == -1) {
        handle_error("Error duplicating stdout");
    }

    // Redirect stdout to the file
    if (dup2(file_fd, STDOUT_FILENO) == -1) {
        handle_error("Error redirecting stdout to file");
    }

    char buf[BUF_SIZE];
    ssize_t num_read;

    // Read from stdin
    while ((num_read = read(infile_fd, buf, BUF_SIZE)) > 0) {
        // Write to file (now stdout is redirected to the file)
        if (write(STDOUT_FILENO, buf, num_read) != num_read) {
            handle_error("Error writing to file");
        }

        // Write to the original stdout (stdout_copy_fd)
        if (write(stdout_copy_fd, buf, num_read) != num_read) {
            handle_error("Error writing to original stdout");
        }
    }

    if (num_read == -1) {
        handle_error("Error reading from stdin");
    }

    // Close file descriptor
    if (close(file_fd) == -1) {
        handle_error("Error closing the file");
    }

    // Close the duplicated stdout file descriptor
    if (close(stdout_copy_fd) == -1) {
        handle_error("Error closing duplicated stdout");
    }

    return EXIT_SUCCESS;
}
