/*
Undirected Graph Cycle

Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Note: The graph can have multiple component.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 
 
1 -> 2 -> 0 -> 1 is a cycle.
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation: 
 
No cycle in the graph.
Constraints:
1 ≤ V, E ≤ 105
0 ≤ edges[i][0], edges[i][1] < V
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        queue<pair<int, int>> q; // node, parent
        vector<bool> visited(V, false);
        
        for(int i=0; i<V; i++){
            if(visited[i] == true) continue;
            
            q.push({i, -1});
            visited[i] = true;
            
            while(!q.empty()){
                auto [node, parent] = q.front();
                q.pop();
                
                for(int i=0; i<adjList[node].size(); i++){
                    int connected_node = adjList[node][i];
                    if(visited[connected_node] == true && connected_node != parent) return true;
                    if(visited[connected_node] == true) continue;
                    visited[connected_node] = true;
                    q.push({connected_node, node});
                }
            }
        }
        return false;
    }
};

/*
Time complexity: O(V+E)
Space complexity: O(V+E).
*/

class Solution {
  public:
    bool dfs(int V, vector<vector<int>>& adjList, vector<bool>& visited, int node, int parent){
        visited[node] = true;
        for(int i=0; i<adjList[node].size(); i++){
            int connected_node = adjList[node][i];
            if(visited[connected_node] == true && connected_node != parent) return true;
            if(visited[connected_node]) continue;
            if(dfs(V, adjList, visited, connected_node, node)) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++){
            if(visited[i] == true) continue;
            
            bool cycle_exists = dfs(V, adjList, visited, i, -1);
            if(cycle_exists) return true;
        }
        
        return false;
    }
};


/*
Time complexity: O(V+E)
Space complexity: O(V+E).
*/

