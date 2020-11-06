// This program is used to practice sliding window algorithm.
// Build command: gcc main.c -o main

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
    // Sliding Window Algorithm description:
    //
    //  Prepare summary of the first window 
    //  Slide through the array, extract maximum_summary along the way
    // int integers[9] = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int array_size = 10;
    int* integers = generateRandomNumbers(0,100, array_size);

    printf("Print out the integer array.\n\n");
    for(int i=0; i<array_size; i++){
        printf("%d ", integers[i]);
    }

    printf("\n\nCalculations:\n");

    int current_summary=0;
    int summary_size = 2;
    
    // Prepare summary of the first window
    for(int i=0; i < summary_size; i++) {
        current_summary += integers[i];
    }
    printf("\nNumber %d calculation: %d\n", 0+1, current_summary);
    
    
    int maximum_summary=current_summary;
    // Slide through the array
    // - need to define where to start in the array
    // - and define where to end
    int last_starting_point_for_summary = array_size - summary_size + 1;
    for( int i = 1; i < last_starting_point_for_summary; i++) {
        int index_to_remove=i-1;
        int index_to_add=(i-1)+(summary_size-1)+1; // index_to_remove + range + 1
        current_summary = current_summary - integers[index_to_remove] + integers[index_to_add];
        printf("Number %d calculation: %d\n", i+1, current_summary);


        maximum_summary = (maximum_summary > current_summary) ? maximum_summary : current_summary;
    }

    printf("\nThe biggest sequential sum of %d integer(s) is: %d\n\n", summary_size, maximum_summary);

    return 0;
}