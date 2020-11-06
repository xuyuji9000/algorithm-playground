// This program is used to practice sliding window algorithm.

#include <stdio.h>
#include <stdlib.h> 

void printRandom(int lower, int upper) {
    if (upper < lower) {
        fprintf(stderr,"printRandom(): upper parameter should not be smaller than lower parameter.");
    }
    int number = rand() % (upper - lower + 1);

    printf("random number: %d\n",number );
}


int main() {
    printRandom(1,10);
    return 0;
}