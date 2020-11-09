/**
 * Build command: gcc -o main ./main.c
 **/
#include <stdio.h>
#include <stdlib.h>


struct MinHeap {
    int* array;
    int capacity;
    int count;
};

struct MinHeap* initMinHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->array = (int*)malloc(capacity*sizeof(int));
    heap->capacity = capacity;
    heap->count = 0;
    return heap;
};

void freeMinHeap(struct MinHeap* heap);
void insert(struct MinHeap* heap, int element);
void heapify_bottom_top(struct MinHeap* heap, int index);
void swap(int* x, int* y);

void extract(){};

int main() {

    int test_data[10] = {5, 9, 12, 13, 16, 45, 7, 66, 48, 98};
    
    const int HEAP_CAPACITY = 10;
    struct MinHeap* myMinHeap = initMinHeap(HEAP_CAPACITY);

    for(int i = 0; i < sizeof(test_data)/sizeof(test_data[0]); i++ ) {
        insert(myMinHeap, test_data[i]);
    }



    for(int i = 0; i < myMinHeap->count; i++ ) {
        printf("%d: %d\n", i, myMinHeap->array[i]);
    }

    freeMinHeap(myMinHeap);
    return 0;
}



void freeMinHeap(struct MinHeap* heap){
    free(heap->array);
    free(heap);
};

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y; 
    *y = temp; 

};

void heapify_bottom_top(struct MinHeap* heap, int index) {
    int temp;
    int parent_node = (index-1)/2;

    if( heap->array[parent_node] > heap->array[index]) {
        swap(heap->array+parent_node, heap->array+index);

        heapify_bottom_top(heap, parent_node);

    }
}

/**
 * Algorithm description:
 * 1. Add the element to the bottom level of the heap at the leftmost open space;
 * 2. Compare the added element with its parent; if they are in the correct order, stop;
 **/
void insert(struct MinHeap* heap, int element){

    if(heap->count < heap->capacity) {
        heap->array[heap->count] = element;
        heapify_bottom_top(heap, heap->count);
        heap->count++;
    }
};

