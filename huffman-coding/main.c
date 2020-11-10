// This program implements huffman encoding
// Build command: gcc -o main ./main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node {
    char value;
    int frequency;
    struct Node* left;
    struct Node* right;
};

void createInternalNode(struct Node** new_Node_pointer, struct Node* left, struct Node* right);

struct MinHeap {
    struct Node* array;
    int capacity;
    int count;
};

struct MinHeap* initMinHeap(int capacity);
void freeMinHeap(struct MinHeap* heap);
void insert(struct MinHeap* heap, struct Node element);
void swap(struct Node* x, struct Node* y);
int  parent_index(int child_index);
bool smaller_than_parent(int* array, int index);
bool not_root_node(int index);


int extract(struct MinHeap* heap);

int main() {

    // Initialize min heap
    const int HEAP_CAPACITY = 20;
    struct MinHeap* myMinHeap = initMinHeap(HEAP_CAPACITY);

    FILE *file_pointer;
    char file_path[] ="./characters.txt";

    file_pointer = fopen(file_path, "r");

    if(NULL == file_pointer) {
        fprintf(stderr, "Error! opening file\n");
        exit(EXIT_FAILURE);
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    ssize_t numbers_read; //[1]
    char * line_content = NULL;
    size_t len = 0;
    while(-1 != (numbers_read = getline(&line_content, &len,file_pointer))) {
        char delemimator = ',';
        (*new_node).value =  strtok(line_content, &delemimator)[0]; // [2]

        (*new_node).frequency =  atoi(strtok(NULL, &delemimator)); // [3]

        insert(myMinHeap, *new_node);

        // DEBUG:
        // printf("Line length: %zu\nCharacter value: %c\nCharacter frequency: %d\n\n", numbers_read, Node_array[line_number].value, Node_array[line_number].frequency);
        
    }

    free(new_node);

    // DEBUG:
    /*
    for(int i=0; i < myMinHeap->count; i++) {
        printf("frequency: %d\n", myMinHeap->array[i].frequency);
    };
    */
    

    /*
      Fixing the array size here, can be convert to dynamic array size.
    */
/*
    struct Node Node_array[10]; 
    ssize_t numbers_read; //[1]
    char * line_content = NULL;
    size_t len = 0;

    int line_number = 0;
    while(-1 != (numbers_read = getline(&line_content, &len,file_pointer))) {

        char delemimator = ',';
        Node_array[line_number].value =  strtok(line_content, &delemimator)[0]; // [2]

        Node_array[line_number].frequency =  atoi(strtok(NULL, &delemimator)); // [3]

        // DEBUG:
        // printf("Line length: %zu\nCharacter value: %c\nCharacter frequency: %d\n\n", numbers_read, Node_array[line_number].value, Node_array[line_number].frequency);
        
        line_number++;
    }
*/

/*
    int Node_count = line_number;
    int Node_index=0;

    struct Node* root;

    struct Node* new_Node = malloc(sizeof(struct Node));
    createInternalNode( &new_Node, &Node_array[0], &Node_array[1] );


    // printf("New internal Node frequency: %d\n", (*new_Node).frequency);

    root = new_Node;
    new_Node = NULL; // Prevent dangling pointer
    Node_index += 2;

    int end_of_Node_index = Node_count - 1;

    while(Node_index <= end_of_Node_index) {
        int Nodes_left = (end_of_Node_index - Node_index) +1;

        struct Node* new_Node = malloc(sizeof(struct Node));

        if( 1 == Nodes_left ) {
            if ( (*root).frequency > Node_array[Node_index].frequency)
                createInternalNode(&new_Node, root, &Node_array[Node_index]);
            else
                createInternalNode(&new_Node, &Node_array[Node_index], root);
            root = new_Node;            
            printf("New internal Node frequency: %d\n", (*new_Node).frequency);
            break;
        }

        Node_index++;
           

        

    }
*/


    fclose(file_pointer);
    if (line_content)
        free(line_content);
    freeMinHeap(myMinHeap);

    /*
      Use sorted frequency here, can change to random order .
    */
    

    exit(EXIT_SUCCESS);
}

void createInternalNode(struct Node** new_Node_pointer, struct Node* left, struct Node* right) {
    struct Node new_Node =  {
        .frequency = (*left).frequency + (*right).frequency
    };

    memcpy(*new_Node_pointer, &new_Node, sizeof(struct Node));

};

struct MinHeap* initMinHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->array = (struct Node*)malloc(capacity*sizeof(struct Node));
    heap->capacity = capacity;
    heap->count = 0;
    return heap;
}

void freeMinHeap(struct MinHeap* heap){
    free(heap->array);
    free(heap);
};


/**
 * Algorithm description:
 * 1. Add the element to the bottom level of the heap at the leftmost open space;
 * 2. Compare the added element with its parent; if they are in the correct order, stop;
 * 3. If not, swap the element with its parent and return to the previous step.
 **/
/*
void insert(struct MinHeap* heap, struct Node element){
    printf("value: %d, frequency: %d\n", element.value, element.frequency);
}
*/

void insert(struct MinHeap* heap, struct Node element){

    // Check if the heap still have capacity for adding new element
    if (heap->count >= heap->capacity) {
        return;
    }
    
    // Add element to the end of the heap
    int current_index = heap->count;
    memcpy(heap->array+current_index, &element, sizeof(struct Node));

    while(true) {

        bool is_root_node = (0 == current_index) ? true : false;
        if(is_root_node)
            break;

        bool higher_than_parent = ((heap->array+current_index)->frequency >= (heap->array+parent_index(current_index))->frequency) \
                                  ? true : false;
        if(higher_than_parent)
            break;

        struct Node parent_element = *(heap->array+parent_index(current_index));
        struct Node current_element = *(heap->array+current_index);

        swap(&parent_element, &current_element);

        current_index = parent_index(current_index);

    }

    heap->count++;
    
};


void swap(struct Node* x, struct Node* y) {

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    memcpy(temp, x, sizeof(struct Node));
    memcpy(x, y, sizeof(struct Node));
    memcpy(y, temp, sizeof(struct Node));

    free(temp);
};

int parent_index(int child_index) {
    return (child_index - 1)/2;
}

/*
# Reference
1. [What is ssize_t in C? ](https://jameshfisher.com/2017/02/22/ssize_t/)

2. [C library function - strtok()](https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm)

3. [C library function - atoi()](https://www.tutorialspoint.com/c_standard_library/c_function_atoi.htm)
*/

