This folder provide an example of binary heap.

> A binary heap is a heap data structure that takes the form of a binary tree.[1]

> Binary heaps are common way of implementing priority queues.[1]


## How is Binary Heap  represented?

1. The root element is at array[0]

2. Below shows indexes of the other nodes for the i<sup>th</sup> node, i.e. , array[i]

    - array[ ( i - 1 ) / 2 ] Returns the parent node

    - array[ ( i * 2 ) + 1 ] Returns left child node

    - array[ ( i * 2 ) + 2 ] Returns right child node

## Efficiency

- The hight of the heap of **n** nodes is **O(lgn)**

- Insertion: each level new value moves up takes **O(1)** time, **O(lgn)** is the worst case.



# Reference

1. [Binary heap](https://en.wikipedia.org/wiki/Binary_heap)

    > Wikipedia

2. [Binary Heap](https://www.geeksforgeeks.org/binary-heap/)

    > Read this article for implementation inspiration.

3. [Binary heap / Heap operations](https://en.wikipedia.org/wiki/Binary_heap#Heap_operations)

    > Understand binary heap operations.

4. [Min Heap array implementation in c](https://gist.github.com/sudhanshuptl/d86da25da46aa3d060e7be876bbdb343)

    > Read this source code for implementation inspiration.

5. [Introduction to Binary Heaps (MaxHeaps)](https://www.youtube.com/watch?v=WCm3TqScBM8)

    > Use this video introduction to get more intuitive understanding.
