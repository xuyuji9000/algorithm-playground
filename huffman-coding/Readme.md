This folder implements huffman coding in C.

pseudocode

- Prepare a sorted character node list, from small to large based on frequency.

- Pop two character node, Create a new internal node(CreateInternalNode())

  - Build an internal node with summed frenquency from the character nodes.

  - Internal node has left pointer and right pointer, and point to the character nodes. 


- While Check how many characters node has not been integrated into the tree

  - If only one left
    
    - Pop the character node.
    
    - Create a new internal node with the new character node and the last internal node, CreateInternalNode().

    - Return the internal node.
    
    - **END**

  - Else Pop two character nodes, sort the three nodes by frequency, and CreateInternalNode() with the smaller two. 

# Reference

1. [Huffman Coding - Greedy Algorithm](https://www.youtube.com/watch?v=dM6us854Jk0&t=3s)

  > Get animated understanding from this video.

2. [Huffman Coding | Greedy Algo-3](https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/)

  > Get programming inspiration from this article.
