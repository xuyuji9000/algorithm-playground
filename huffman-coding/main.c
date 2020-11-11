// This program implements huffman encoding

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

void createInternalNode(struct Node* new_Node_pointer, struct Node* left, struct Node* right);

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

void print_code(struct Node* node, int code[], int code_index);


bool extract(struct MinHeap* heap, struct Node* result);

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
    // DEBUG:
    // Test extract() function
    struct Node* temp_node = (struct Node*)malloc(sizeof(struct Node));
    extract(myMinHeap,temp_node);
    printf("extracted value:%d\n", temp_node->frequency);
    free(temp_node);
    temp_node=NULL;
    */


    while(true) {
        /*
        //
        // DEBUG: 
        
        struct Node* first_node=NULL;
        if(!extract(myMinHeap, first_node)) {
            printf("extract ended\n");
            break;
        }
        printf("%d\n", first_node->frequency);
        */

        printf("\ncount: %d\n", myMinHeap->count);
        for(int i=0; i<myMinHeap->count; i++){
            printf("frequency: %d\n", (myMinHeap->array[i]).frequency);

        }

        if( 0 >= myMinHeap->count) {
            fprintf(stderr,"The heap is empty\n");
            exit(EXIT_FAILURE);
            break;
        }
        
        if(1 == myMinHeap->count ) {
            printf("Huffman coding process finished\n");
            break;
        }

        struct Node* first_node=(struct Node*)malloc(sizeof(struct Node));
        struct Node* second_node=(struct Node*)malloc(sizeof(struct Node));

        if(!extract(myMinHeap, first_node)) {
            fprintf(stderr, "extract node failed\n");
            break;
        }

        if(!extract(myMinHeap, second_node)) {
            fprintf(stderr, "extract node failed\n");
            break;
        }

        struct Node* internal_node = (struct Node*)malloc(sizeof(struct Node));
        memset(internal_node, 0, sizeof(struct Node));
        createInternalNode( internal_node, first_node, second_node );

        insert(myMinHeap, *internal_node);


        // Free not using pointers
        free(first_node);
        first_node=NULL;
        free(second_node);
        second_node=NULL;  
        /**
         * do not free internal_node memory 
         * it's used to construct huffman coding tree
         **/
        internal_node=NULL;  
    }

    fclose(file_pointer);
    if (line_content)
        free(line_content);


    
    // Print huffman code
    int code[100] = {};
    int code_index = 0;
    print_code(myMinHeap->array, code, code_index);
    

    // printf("\ncharacter: %p, frequency: %p\n", myMinHeap->array[0].left, myMinHeap->array[0].right);
    freeMinHeap(myMinHeap);

    /*
      Use sorted frequency here, can change to random order .
    */
    

    exit(EXIT_SUCCESS);
}

void createInternalNode(struct Node* root, struct Node* left, struct Node* right) {
    root->frequency = left->frequency +right->frequency;


    root->left = left;
    root->right = right;

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

        struct Node* parent_element = heap->array+parent_index(current_index);
        struct Node* current_element = heap->array+current_index;

        swap(parent_element, current_element);

        parent_element = NULL;
        current_element = NULL;

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


/**
 * Description: This function extract the root for minimum and balance the heap.
 * Steps: 
 * 1. Replace the root with the last element
 * 2. Compare the new root with its children; if they are the correct order, stop
 * 3. If not, swap will smaller children, and return to previous step
 **/
 bool extract(struct MinHeap* heap, struct Node* result) {

     if(NULL ==result) {
         printf("extract failed, pointer is empty.\n");
         return false;
     }


    if(heap->count <= 0)
        return false;

    int root_index = 0;
    
    struct Node* root_element_address = heap->array+root_index;
    struct Node* last_element_address = heap->array+(heap->count - 1);

    // struct Node* result  = (struct Node*)malloc(sizeof(struct Node));
    memcpy(result, root_element_address, sizeof(struct Node));

    memcpy(root_element_address, last_element_address, sizeof(struct Node));
    memset(last_element_address, 0, sizeof(struct Node));
    heap->count--;

    /**
     * Hepify
     * Balance the heap, after extract the root node
     **/
    int current_index = root_index;
    while(true) {
        int left_child_index = current_index*2 + 1;
        int right_child_index = current_index*2 + 2;

        bool do_not_have_left_child     = left_child_index >= heap->count;
        bool have_left_child            = !do_not_have_left_child;

        bool do_not_have_right_child    = right_child_index >= heap->count;
        bool have_right_child           = !do_not_have_right_child;

        bool do_not_have_children = do_not_have_left_child && do_not_have_right_child;

        /**
         * Finish balancing
         * When current index is a leaf node
         **/
        if(do_not_have_children) {
            break;
        }

        int smallest = current_index;

        bool larger_than_left_child = have_left_child && (heap->array[left_child_index].frequency < heap->array[smallest].frequency);
        if( larger_than_left_child ) {
            smallest = left_child_index;
        }


        bool larger_than_right_child = have_right_child && (heap->array[right_child_index].frequency < heap->array[smallest].frequency);
        if( larger_than_right_child ) {
            smallest = right_child_index;
        }

        /**
         * Finish balancing
         * When current index is the smallest comparing with children
         **/
        if(smallest == current_index)
            break;

        swap(heap->array+smallest, heap->array+current_index);
        current_index=smallest;
    }

    return true;
}

void print_code(struct Node* node, int code[], int code_index) {
    if(node->left) {
        code[code_index] = 0;
        print_code(node->left, code, code_index+1);
    }
    if(node->right) {
        code[code_index] = 1;
        print_code(node->right, code, code_index+1);
    }

    printf("value: %c ", node->value);
    for(int i=0; i < code_index; i++) {
        printf("%d", code[i]);
    }
}

/*
# Reference
1. [What is ssize_t in C? ](https://jameshfisher.com/2017/02/22/ssize_t/)

2. [C library function - strtok()](https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm)

3. [C library function - atoi()](https://www.tutorialspoint.com/c_standard_library/c_function_atoi.htm)
*/

