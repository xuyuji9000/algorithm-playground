/**
 * Build command: gcc -o main ./main.c
 **/
#include <stdio.h>
#include <stdlib.h>


struct MinHeap {
    int* array;
    int capacity;
};

struct MinHeap* initMinHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->array = (int*)malloc(capacity*sizeof(int));
    return heap;
};

void freeMinHeap(struct MinHeap* heap){
    free(heap->array);
    free(heap);
}

void insert(){}
void extract(){}

int main() {
    
    const int HEAP_CAPACITY = 10;
    struct MinHeap* myMinHeap = initMinHeap(HEAP_CAPACITY);



    freeMinHeap(myMinHeap);
    return 0;
}