/*

How do we represent the graph of n nodes in c++?

There are 2 ways to represent a graph of n nodes in c++, namely:
1) Adjacency matrix.
2) Adjacency list.

1) Adjancency matrix: 
- In the adjacency matrix, we would have a 2D array of size n*n, where [i][j] == 1, if there a edge going from the node i to node j.
- Space complexity of the adjacency matrix is n*n, where n is the number of nodes in the graphs.

2) Adjacency list:
- In the adjacency list we would have a vector of vector, where at an index i, we would have a list of all the connections of the node i.
- Space complexity of the adjacency list would be 2*E where E is the number of edges present in the graph, because for an undirected graph where there is an edge from u to v, 
v would appear in the list of u and u would appear in the list of v and hence, we would need 2*E space for storing the graph.

*/