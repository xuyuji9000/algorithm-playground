// This program implements huffman encoding
// Build command: gcc -o main ./main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Characters {
    char value;
    int frequency;
};

int main() {

    FILE *file_pointer;
    char file_path[] ="./characters.txt";

    file_pointer = fopen(file_path, "r");

    if(NULL == file_pointer) {
        fprintf(stderr, "Error! opening file\n");
        exit(EXIT_FAILURE);
    }

    /*
      Fixing the array size here, can be convert to dynamic array size.
    */
    struct Characters Characters_array[10]; 
    ssize_t numbers_read; //[1]
    char * line_content = NULL;
    size_t len = 0;

    int line_number = 0;
    while(-1 != (numbers_read = getline(&line_content, &len,file_pointer))) {

        /*

        */
        char delemimator = ',';
        char* value = strtok(line_content, &delemimator); // [2]

        int frequency = atoi(strtok(NULL, &delemimator)); // [3]

        printf("Line length: %zu\nCharacter value: %s\nCharacter frequency: %d\n", numbers_read, value, frequency);

        

        // Characters_array[line_number].;
        
        line_number++;
    }

    fclose(file_pointer);

    if (line_content)
        free(line_content);
    exit(EXIT_SUCCESS);
}


/*
# Reference
1. [What is ssize_t in C? ](https://jameshfisher.com/2017/02/22/ssize_t/)

2. [C library function - strtok()](https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm)

3. [C library function - atoi()](https://www.tutorialspoint.com/c_standard_library/c_function_atoi.htm)
*/

