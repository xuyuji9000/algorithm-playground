This folder contains example of finding the linear ordering of vertices in a Directed Acyclic Graph(DAG).

# Kahn’s algorithm

1. Compute indegree(number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0

2. Pick all the vertices with indegree as 0 and put them into a queue

3. Remove a vertex from the queue and then:

    3.1 Increment  count of visited nodes by 1

    3.2 Decress indegree by 1 for all neighboring nodes

    3.3 If indegree of a neighboring node is reduced to zero, then add it to the queue

4. Repeat Step 3 until the queue is empty

# Reference

1. [Kahn’s algorithm for Topological Sorting](https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/)


