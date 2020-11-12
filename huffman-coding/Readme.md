This folder implements huffman coding in C.

Huffman Coding Algorithm is one of the building blocks of popular compression format like gzip.


## Algorithm description

1. Create a leaf node for each unique character and build a min heap of all leaf nodes.

2. Extract two nodes with the minimum frequency from the min heap

3. Create a new internal node with a frequency equal to the sum of the two nodes frequencies. 

    - Make the first extracted node as left child, and the other as right child

    - Add the internal node to the min heap

4. Repeat 2 and 3 until the heap contains only one node.

## GDB

- Prepare environment

  - `docker run -it centos:8`

  - `yum install gdb gcc`

- Generate debug information: `gcc -Wall -g ./main.c`

- Start debugging: `gdb a.out`

- Prepare layout: `layout src`

- Break at line: `break LINE_NUMBER`

# Reference

1. [Huffman Coding - Greedy Algorithm](https://www.youtube.com/watch?v=dM6us854Jk0&t=3s)

    > Get animated understanding from this video.

2. [Huffman Coding | Greedy Algo-3](https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/)

    > Get programming inspiration from this article.

    > Read pseudocode here.
