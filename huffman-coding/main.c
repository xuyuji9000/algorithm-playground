// This program implements huffman encoding
// Build command: gcc -o main ./main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char value;
    int frequency;
    struct Node* left;
    struct Node* right;
};


void createInternalNode(struct Node** new_Node_pointer, struct Node* left, struct Node* right) {
    struct Node new_Node =  {
        .frequency = (*left).frequency + (*right).frequency
    };

    memcpy(*new_Node_pointer, &new_Node, sizeof(struct Node));

};



int main() {

    FILE *file_pointer;
    char file_path[] ="./characters.txt";

    file_pointer = fopen(file_path, "r");

    if(NULL == file_pointer) {
        fprintf(stderr, "Error! opening file\n");
        exit(EXIT_FAILURE);
    }

    /*
      Fixing the array size here, can be convert to dynamic array size.
    */
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

        // if ( (*root).frequency > Node_array[Node_index].frequency ) {
        //     createInternalNode(&new_Node, root, &Node_array[Node_index]);
        //     Node_index+=1;
        //     root = new_Node;            
        //     printf("New internal Node frequency: %d\n", (*new_Node).frequency);
        //     continue;
        // }

        // if ( Node_array[Node_index].frequency > Node_array[Node_index+1].frequency )
        
        //     createInternalNode(&new_Node, &Node_array[Node_index], &Node_array[Node_index+1]);         
        //     Node_index+=2;
        //     continue;
        // }
           

        

    }

    // for(int i = Node_index;  i <= end_of_Node_index; ) {
    //     int Nodes_left = (end_of_Node_index - i) +1;

    //     if( 1 == Nodes_left ) {
    //         struct Node* new_Node = malloc(sizeof(struct Node));
    //         createInternalNode(&new_Node, &Node_array[i], root);
    //         root = new_Node;            
    //         printf("New internal Node frequency: %d\n", (*new_Node).frequency);
    //         break;
    //     }


    // }


    fclose(file_pointer);
    if (line_content)
        free(line_content);

    /*
      Use sorted frequency here, can change to random order .
    */
    

    exit(EXIT_SUCCESS);
}


/*
# Reference
1. [What is ssize_t in C? ](https://jameshfisher.com/2017/02/22/ssize_t/)

2. [C library function - strtok()](https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm)

3. [C library function - atoi()](https://www.tutorialspoint.com/c_standard_library/c_function_atoi.htm)
*/

