/*
Shortest path in Directed Acyclic Graph

Given a Directed Acyclic Graph of V vertices from 0 to V-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

Examples :

Input: V = 4, E = 2, edges = [[0,1,2], [0,2,1]]
Output: [0, 2, 1, -1]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.
Input: V = 6, E = 7, edges = [[0,1,2], [0,4,1], [4,5,4], [4,2,2], [1,2,3], [2,3,6], [5,3,1]]
Output: [0, 2, 3, 6, 1, 5]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3. Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6. Shortest path from 0 to 4 is 0->4 with edge weight 1.Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.
Constraint:
1 ≤ V ≤ 100
1 ≤ E ≤ min((V*(V-1))/2,4000)
0 ≤ edges[i][0], edges[i][1] < V
0 ≤  edges[i][2] ≤105

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(vector<vector<pair<int, int>>>& adjList, vector<bool>& visited, int node, stack<int>& s){
        visited[node] = true;
        for(int i=0; i<adjList[node].size(); i++){
            int connected_node = adjList[node][i].first;
            if(visited[connected_node] == false) dfs(adjList, visited, connected_node, s);
        }
        s.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<bool> visited(V, false);
        vector<vector<pair<int, int>>> adjList(V);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1], d = edges[i][2];
            adjList[u].push_back({v, d});
        }
        stack<int> s;
        for(int i=0; i<V; i++){
            if(visited[i] == false) dfs(adjList, visited, i, s);
        }
        
        // now we will move on to finding the minimum distaces from the source node
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        
        while(!s.empty()){
            int node = s.top();
            s.pop();
            
            if (dist[node] == INT_MAX) continue;

            for(int i=0; i<adjList[node].size(); i++){
                int connected_node = adjList[node][i].first;
                int wt = adjList[node][i].second;
                // relaxation of edges
                if(dist[connected_node] > dist[node] + wt) dist[connected_node] = dist[node] + wt;
            }
        }
        
        for(int i=0; i<V; i++){
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};

/*
Time complexity: O(V+E), where V is the number of vertices present in the graph and E is the number of edges present in the graph.
Space complexity: O(V+E), where V is the number of vertices present in the graph and E is the number of edges present in the graph.
*/