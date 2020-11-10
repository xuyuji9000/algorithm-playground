/**
 * Build command: gcc -o main ./main.c
 **/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct MinHeap {
    int* array;
    int capacity;
    int count;
};

struct MinHeap* initMinHeap(int capacity);
void freeMinHeap(struct MinHeap* heap);
void insert(struct MinHeap* heap, int element);
void heapify_bottom_top(struct MinHeap* heap, int index);
void swap(int* x, int* y);
int  parent_index(int child_index);
bool smaller_than_parent(int* array, int index);
bool not_root_node(int index);
// int left_child_index(int parent_index);
// int right_child_index(int parent_index);


int extract(struct MinHeap* heap);
void printHead(struct MinHeap* heap);

int main() {

    int test_data[10] = {5, 9, 12, 13, 16, 45, 7, 66, 48, 98};
    
    const int HEAP_CAPACITY = 10;
    struct MinHeap* myMinHeap = initMinHeap(HEAP_CAPACITY);

    printf("intput array length: %lu\n", sizeof(test_data) / sizeof(test_data[0]));
    for(int i = 0; i < sizeof(test_data)/sizeof(test_data[0]); i++ ) {
        insert(myMinHeap, test_data[i]);
    }



    printHead(myMinHeap);

    int result = extract(myMinHeap);

    printf("extract result: %d\n", result);
    
    printHead(myMinHeap);

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
 * 3. If not, swap the element with its parent and return to the previous step.
 **/
void insert(struct MinHeap* heap, int element){

    // Check if the heap still have capacity for adding new element
    if (heap->count >= heap->capacity) {
        return;
    }
    
    // Add element to the end of the heap
    int current_index = heap->count;
    heap->array[current_index] = element;

    while( not_root_node(current_index) && smaller_than_parent(heap->array, current_index) ) {
        
        int* parent_element = heap->array + parent_index(current_index);
        int* child_element = heap->array + current_index;

        swap(parent_element, child_element);

        current_index = parent_index(current_index);

    }

    heap->count++;
    
};

bool not_root_node(int index) {
    if(0 == index) 
      return false;
    return true;
}

bool smaller_than_parent(int* array, int index) {
    if( *(array+index) >=  *(array + parent_index(index)))
      return false;
    return true;
}

int parent_index(int child_index) {
    return (child_index - 1)/2;
}

/**
 * Description: This function extract the root for minimum and balance the heap.
 * Steps: 
 * 1. Replace the root with the last element
 * 2. Compare the new root with its children; if they are the correct order, stop
 * 3. If not, swap will smaller children, and return to previous step
 **/
int extract(struct MinHeap* heap) {

    int root_index = 0;
    int result = heap->array[root_index];

    heap->array[root_index] = heap->array[heap->count - 1];
    heap->count--;

    // Hepify
    int current_index = root_index;
    while(true) {
        int left_child_index = current_index*2 + 1;
        int right_child_index = current_index*2 + 2;

        bool do_not_have_left_child     = left_child_index >= heap->count;
        bool have_left_child            = !do_not_have_left_child;

        bool do_not_have_right_child    = right_child_index >= heap->count;
        bool have_right_child           = !do_not_have_right_child;

        bool do_not_have_children = do_not_have_left_child && do_not_have_right_child;

        if(do_not_have_children) {
            break;
        }

        int smallest = current_index;

        bool larger_than_left_child = have_left_child && (heap->array[left_child_index] < heap->array[current_index]);
        if( larger_than_left_child ) {
            smallest = left_child_index;
        }

        bool larger_than_right_child = have_right_child && (heap->array[right_child_index] < heap->array[current_index]);
        if( larger_than_right_child ) {
            smallest = right_child_index;
        }

        swap(heap->array+smallest, heap->array+current_index);
        current_index=smallest;
    }
        

    

    return result;
}

void printHead(struct MinHeap* heap) {
    for(int i = 0; i < heap->count; i++ ) {
        printf("%d: %d\n", i, heap->array[i]);
    }
}

struct MinHeap* initMinHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->array = (int*)malloc(capacity*sizeof(int));
    heap->capacity = capacity;
    heap->count = 0;
    return heap;
};
