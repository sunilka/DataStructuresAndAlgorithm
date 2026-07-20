/*

Dijkstra Algorithm

Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

Note: The Graph is connected and doesn't contain any negative weight edge.
It is guaranteed that all the shortest distance will fit in a 32-bit integer.

Examples:

Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
Output: [4, 3, 0]
Explanation:

Shortest Paths:
For 2 to 0 minimum distance will be 4. By following path 2 -> 1 -> 0
For 2 to 1 minimum distance will be 3. By following path 2 -> 1
For 2 to 2 minimum distance will be 0. By following path 2 -> 2
Input: V = 5, edges[][] = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]], src = 0
Output: [0, 4, 8, 10, 10]
Explanation: 

Shortest Paths: 
For 0 to 1 minimum distance will be 4. By following path 0 -> 1
For 0 to 2 minimum distance will be 8. By following path 0 -> 2
For 0 to 3 minimum distance will be 10. By following path 0 -> 2 -> 3 
For 0 to 4 minimum distance will be 10. By following path 0 -> 1 -> 4
Constraints:
1 ≤ V ≤ 106
1 ≤ E = edges.size() ≤ 106
0 ≤ edges[i][0], edges[i][1] ≤ V-1
0 ≤ edges[i][2] ≤ 104
0 ≤ src < V
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adjList(V);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1], d = edges[i][2];
            adjList[u].push_back({v, d});
            adjList[v].push_back({u, d}); 
        }
        
        set<pair<int, int>> s;
        s.insert({0, src});
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        while(!s.empty()){
            auto it = *(s.begin());
            int node_dist = it.first; 
            int node = it.second;
            
            s.erase(s.begin()); 
            
            for(int i=0; i<adjList[node].size(); i++){
                int connected_node = adjList[node][i].first;
                int wt = adjList[node][i].second;
                
                if(dist[connected_node] > node_dist + wt){
                    if(dist[connected_node] != INT_MAX) {
                        s.erase({dist[connected_node], connected_node});
                    }
                    
                    dist[connected_node] = node_dist + wt;
                    s.insert({dist[connected_node], connected_node});
                }
            }
        }
        return dist;
    }
};