/*

Topological Sort
Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.

Examples:

Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the given graph are:
[3, 2, 1, 0]
[1, 2, 3, 0]
[2, 3, 1, 0]
Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5, 2]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the graph are:
[4, 5, 0, 1, 2, 3]
[5, 2, 4, 0, 1, 3]
Constraints:
2  ≤  V  ≤  5 x 103
1  ≤  E = edges.size()  ≤  min[105, (V * (V - 1)) / 2]
0 ≤ edges[i][0], edges[i][1] < V

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> indegree(V, 0);
        vector<vector<int>> adjList(V);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            indegree[v]++;
            adjList[u].push_back(v);
        }
        
        vector<int> ans;
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            
            for(int i=0; i<adjList[node].size(); i++){
                int connected_node = adjList[node][i];
                indegree[connected_node]--;
                if(indegree[connected_node] == 0) q.push(connected_node);
            }
        }
        return ans;
    }
};

/*
Time complexity: O(V+E), where V is the number of vertices present in the graph and the E is the number of edges present in the graph.
Space complexity: O(V+E), where V is the number of vertices present in the graph and the E is the number of edges present in the graph.
- O(V + E) space is required to build the adjacency list (adjList).
- O(V) space is required for the in-degree array, the BFS queue, and the final answer vector.
Combined, the total auxiliary space scales linearly as O(V + E).
*/