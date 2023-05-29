#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;
    char *file_name = NULL;
    while ((opt = getopt(argc, argv, "f:")) != -1) {
        switch (opt) {
            case 'f':
                file_name = optarg;
                break;
            case '?':
                fprintf(stderr, "Unknown option: %c\n", optopt);
                return 1;
        }
    }

    // Check if a file name was provided
    if (file_name != NULL) {
        printf("File name: %s\n", file_name);
    } else {
        printf("No file name provided\n");
    }

    // Print any remaining arguments
    for (int i = optind; i < argc; i++) {
        printf("Argument: %s\n", argv[i]);
    }

    return 0;
}

