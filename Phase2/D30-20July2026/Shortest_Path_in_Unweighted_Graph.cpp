/*

Shortest Path in Unweighted Graph

Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, where edges[i] = [u, v] denotes an undirected edge between vertex u and vertex v, given two vertices src and dest, find the length of the shortest path from src to dest. If there is no path between src and dest, return -1.

Note: All edges have a unit weight of 1.

Examples :

Input: V = 9, edges[][] = [[0, 1], [0, 3], [1, 2], [3, 4], [4, 5], [2, 6], [5, 6], [6, 7], [6, 8], [7, 8]], src = 0, dest = 8
Output: 4
Explanation: One of the shortest paths from vertex 0 to vertex 8 is 0 -> 1 -> 2 -> 6 -> 8, which contains 4 edges.

Input: V = 4, edges[][]= [[0, 3], [1, 3]], src = 3, dest = 2
Output: -1
Explanation: There is no path between vertices 3 and 2.

Constraints:

1 ≤ V ≤ 10^4
0 ≤ E ≤ V × (V - 1) / 2
0 ≤ edges[i][0], edges[i][1] < V

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<int>> adjList(V);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        queue<pair<int, int>> q;
        q.push({src, 0});
        visited[src] = true;
        
        while(!q.empty()){
            auto [node, dist] = q.front();
            q.pop();
            
            if(node == dest) return dist;
            
            for(int i=0; i<adjList[node].size(); i++){
                int connected_node = adjList[node][i];
                if(!visited[connected_node]){
                    visited[connected_node] = true;
                    q.push({connected_node, dist+1});
                }
            }
        }
        return -1;
    }
};


/*
Time complexity: O(V+E), where V is the number of vertices in the graph and E is the number of edges present in the graph.
Space complexity: O(V+E), where V is the number of vertices in the graph and E is the number of edges present in the graph. 
*/