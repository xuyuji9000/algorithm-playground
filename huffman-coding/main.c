// This program implements huffman encoding
// Build command: gcc -o main ./main.c

#include <stdio.h>

struct Characters {
    char value;
    int frequency;
};

int main() {

    // printf("Hello World.\n");
    struct Characters char1;
    
    char1.value='a';
    char1.frequency=5;

    printf("Character \'%c\' frequency: %d\n", char1.value, char1.frequency);
     


    return 0;
}