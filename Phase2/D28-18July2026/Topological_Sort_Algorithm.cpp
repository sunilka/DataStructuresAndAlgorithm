/*

- Topological sorting algorithm says that if there is an edge from u to v, then in the ordering the vertex u would come first and then v. So, u->v then the topological 
order would be u, v.
- The topological order would work only for directed acylic graph only. (DAG)
- Bookish definition: Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int V, int node, vector<vector<int>>& adjList, vector<bool>& visited, stack<int>& s){
        visited[node] = true;
        for(int i=0; i<adjList[node].size(); i++){
            if(!visited[adjList[node][i]]){
                dfs(V, adjList[node][i], adjList, visited, s);
            }
        }
        s.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<bool> visited(V, false);
        vector<vector<int>> adjList(V);
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adjList[u].push_back(v);
        }
        stack<int> s;
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(!visited[i]) dfs(V, i, adjList, visited, s);
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

/*
Time complexity: O(V+E), where V is the number of vertices in the graph and the E is the number of edges present in the graph.
Space complexity: O(V+E), where V is the number of vertices in the graph and the E is the number of edges present in the graph.

*/