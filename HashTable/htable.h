/* htable.h */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>

typedef unsigned int int32;
typedef unsigned short int int16;
typedef unsigned char int8;

struct s_hash {
    unsigned int hash:21;
};
typedef struct s_hash Hash;

int main();
