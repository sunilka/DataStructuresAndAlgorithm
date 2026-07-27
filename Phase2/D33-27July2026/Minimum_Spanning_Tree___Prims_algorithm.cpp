/*
Minimum Spanning Tree

Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is provided as a list of edges, where each edge is represented as [u, v, w], indicating an edge between vertex u and vertex v with edge weight w.

Input: V = 3, E = 3, Edges = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]
 
Output: 4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
Input: V = 2, E = 1, Edges = [[0 1 5]]

 

Output: 5 
Explanation: Only one Spanning Tree is possible which has a weight of 5.
Constraints:
2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
The graph is connected and doesn't contain self-loops & multiple edges.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adjList(V);
        for(auto edge: edges){
            int u = edge[0], v = edge[1], w = edge[2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }
        
        vector<int> visited(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});
        int ans = 0;
        
        while(!pq.empty()){
            auto [weight, node] = pq.top();
            pq.pop();

            if(visited[node] == true) continue;            
            ans += weight;
            visited[node] = true;
            
            for(int i=0; i<adjList[node].size(); i++){
                int connected_node = adjList[node][i].first, w = adjList[node][i].second;
                if(visited[connected_node] == true) continue;
                pq.push({w, connected_node});
            }
        }
        return ans;
    }
};

/*
Time complexity: If you see we are actually going over all the edges and since we are using the priority queue, the time complexity would be O(ElogE), where E is the 
number of edges present in the graph.
Space complexity: O(V+E+E), where V is the number of number edges present in the graph, O(V+E) is the used of the adjacency list and the O(E) for the priority queue. 
*/