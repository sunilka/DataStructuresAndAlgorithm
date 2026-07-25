/*
Number of Connected Components
Solved
Difficulty: MediumAccuracy: 54.29%Submissions: 175K+Points: 4Average Time: 20m
Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v. Count the number of connected components in the graph. Two vertices belong to the same connected component if there is a path between them.

Examples :

Input: V = 5, edges[][] = [[0, 1], [2, 1], [3, 4]]
Output: 2
Explanation:

Input: V = 7, edges[][] = [[0, 1], [6, 0], [2, 4], [2, 3], [3, 4]]
Output: 3
Explanation:


Constraints:
1 ≤ V ≤ 10^4
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Disjoint set union
    vector<int> parent, size;
    
    int find_parent(int u){
        if(parent[u] == u) return parent[u];
        return parent[u] = find_parent(parent[u]);
    }
    
    void union_of_elements(int u, int v){
        int parentu = find_parent(u);
        int parentv = find_parent(v);
        
        if(parentu == parentv) return;
        
        if(size[parentu] >= size[parentv]){
            parent[parentv] = parentu;
            size[parentu] += size[parentv];
        }
        else{
            parent[parentu] = parentv;
            size[parentv] += size[parentu];
        }
    }
    
    int countConnected(int V, vector<vector<int>>& edges) {
        parent.resize(V);
        size.resize(V);
        iota(parent.begin(), parent.end(), 0);
        fill(size.begin(), size.end(), 1);
        
        // Connect the elements present in the edges.
        for(auto info: edges){
            int u = info[0], v = info[1];
            union_of_elements(u, v);
        }
        
        // Count no of unique parents we have to the number of connected components present
        set<int> s;
        for(int i=0; i<V; i++){
            int parent = find_parent(i);
            s.insert(parent);
        }
        return s.size();
    }
};

/*

Time complexity analysis:
- O(V) time to fill the parent and the size vectors initially.
- Then we are going over the edges and inside the union we are calling there find parent method which is going to take the alpha(V) time right. (Reverse Ackerman function). 
Hence the time complexity of this algorithm is O(E*alpha(V))
- Then again we are going over the each parent to find out the parents so that we get the unqiue connected components. Hence, here again complexity is O(V*alpha(V)).
Total time complexity: O(V + E*alpha(V) + V*alpha(V)), where V is the number of vertices and E is the number of edges.

Space complexity: O(3V) = O(V), where V is the number of vertices present in the graph.


*/

class Solution {
  public:
    // Now we will try to solve this problem using the BFS approach.
    int countConnected(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        queue<int> q;
        int connected_components = 0;
        
        for(int i=0; i<V; i++){
            if(visited[i] == true) continue;
            
            connected_components++;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int i=0; i<adjList[node].size(); i++){
                    int connected_node = adjList[node][i];
                    if(visited[connected_node] == false){
                        visited[connected_node] = true;
                        q.push(connected_node);
                    }
                }
            }
        }
        return connected_components;
    }
};

/*
Time complexity analysis:
Let V be the number of vertices and E is the number of edges.
- For building the adjacency list, we are using O(E) time.
- In the loop we will look at each vertex only once (since after looking at it we would just mark it as visited) and we would
look at each edge 2 times, once for processing the edge and once for already processed edge.

Time complexity = O(E+ (V+E)).

Space complexity: O(V+E)
*/


class Solution {
  public:
    void dfs(int V, vector<vector<int>>& adjList, vector<bool>& visited, int node){
        visited[node] = true;
        for(int i=0; i<adjList[node].size(); i++){
            int connected_node = adjList[node][i];
            if(visited[connected_node] == false) dfs(V, adjList, visited, connected_node);
        }
    }
    int countConnected(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);
        for(auto itr: edges){
            int u = itr[0], v = itr[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        int connected_components = 0;
        vector<bool> visited(V, false);
        
        for(int i=0; i<V; i++){
            if(visited[i] == true) continue;
            connected_components++;
            dfs(V, adjList, visited, i);
        }
        return connected_components;
    }
};

/*
Time complexity analysis:
Let V be the number of vertices and E is the number of edges.
- For building the adjacency list, we are using O(E) time.
- In the loop we will look at each vertex only once (since after looking at it we would just mark it as visited) and we would
look at each edge 2 times, once for processing the edge and once for already processed edge.

Time complexity = O(E+ (V+E)).

Space complexity: O(V+E)
*/
