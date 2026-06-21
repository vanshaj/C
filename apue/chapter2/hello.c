#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Welcome to CS631 Advanced Programmin in the UNIX enviornment, %s\n", getlogin());
    return 0;
}