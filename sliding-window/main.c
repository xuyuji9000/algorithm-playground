// This program is used to practice sliding window algorithm.

#include <stdio.h>
#include <stdlib.h> 

int* generateRandomNumbers(int lower, int upper, int count) {
    int random_numbers[count];
    for (int i = 0; i < count; i++) {
        if (upper < lower) {
            fprintf(stderr,"printRandom(): upper parameter should not be smaller than lower parameter.");
        }
        int number = rand() % (upper - lower + 1);

        random_numbers[i] = number;

        // printf("random number: %d\n",number );
    }

    return random_numbers;
    
}


int main() {
    int lower = 1, upper = 10, count=5;
    int* random_numbers = generateRandomNumbers(1,10, 5);

    for(int i=0; i < count; i++) {
        printf("Number %d: %d\n", i+1, random_numbers[i]);
    }
    return 0;
}