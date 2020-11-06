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
    int integers[9] = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    return 0;
}