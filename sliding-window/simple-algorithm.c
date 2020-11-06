// This program use nested loop to find smallest sum in an integer array.
// Build command: gcc -o simple-algorithm ./simple-algorithm.c

#include <stdio.h>
#include <stdlib.h> 
#include <limits.h>

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


int main()
{  
    int integers[9] = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int array_size = sizeof(integers)/sizeof(integers[0]);


    printf("array byte size: %d\narray length: %d\n", (int)sizeof(integers), array_size);


    printf("\nStart calculation...\n");
    int max_sum = INT_MIN;
    int sum_size = 2;

    if(array_size < sum_size) {
        fprintf(stderr, "The number of integers in the array is smaller than the number of integers to sum.");
        exit(1);
    }

    
    int biggest_starting_point_for_sum = array_size - sum_size + 1;
    for(int i=0; i < biggest_starting_point_for_sum; i++) {

        int current_sum = 0;

        for (int j =i; j < (i+sum_size); j++ ) {
            current_sum += integers[j];
        }

        max_sum = (max_sum > current_sum) ? max_sum : current_sum;
        printf("%d time calculation: %d\n", i+1, max_sum);
    }

    printf("\nThe biggest sequential sum of %d integer(s) is %d\n", sum_size, max_sum);

    return 0;
}

