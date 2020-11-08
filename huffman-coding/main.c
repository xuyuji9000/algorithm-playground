// This program implements huffman encoding
// Build command: gcc -o main ./main.c

#include <stdio.h>
#include <stdlib.h>

struct Characters {
    char value;
    int frequency;
};

int main() {

    FILE *fptr;
    char file_path[] ="./characters.txt";

    fptr = fopen(file_path, "r");

    if(NULL == fptr) {
        fprintf(stderr, "Error! opening file\n");
        exit(EXIT_FAILURE);
    }

    ssize_t numbers_read; //[1]
    char * line = NULL;
    size_t len = 0;
    while(-1 != (numbers_read = getline(&line, &len,fptr))) {
        printf("Line length: %zu\nLine value: %s\n", numbers_read, line);
    }

    fclose(fptr);

    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}


/*
# Reference
1. [What is ssize_t in C? ](https://jameshfisher.com/2017/02/22/ssize_t/)
*/