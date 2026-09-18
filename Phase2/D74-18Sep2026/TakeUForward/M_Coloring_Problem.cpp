/*
M-Coloring Problem
You are given an undirected graph consisting of V vertices and E edges represented by a list edges[][], along with an integer m. Your task is to find if it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. 

Note: The graph is indexed with 0-based indexing.

Examples:

Input: V = 4, edges[][] = [[0, 1], [1, 3], [2, 3], [3, 0], [0, 2]], m = 3
Output: true
Explanation: It is possible to color the given graph using 3 colors, for example, one of the possible ways vertices can be colored as follows:

Vertex 0: Color 1
Vertex 1: Color 2
Vertex 2: Color 2
Vertex 3: Color 3
Input: V = 3, edges[][] = [[0, 1], [1, 2], [0, 2]], m = 2
Output: false
Explanation: It is not possible to color the given graph using only 2 colors because vertices 0, 1, and 2 form a triangle.
Constraints:
1 ≤ V ≤ 10
1 ≤ E = edges.size() ≤ (V*(V-1))/2
0 ≤ edges[i][j] ≤ V-1
1 ≤ m ≤ V
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool is_safe(int node, int col, vector<vector<int>>& adj, vector<int>& ncolor) {
        for (int neighbor : adj[node]) {
            if (ncolor[neighbor] == col) return false;
        }
        return true;
    }

    bool solve(int node, int V, int m, vector<vector<int>>& adj, vector<int>& ncolor) {
        if (node == V) return true;
        for (int col = 0; col < m; col++) {
            if (is_safe(node, col, adj, ncolor)) {
                ncolor[node] = col;
                if (solve(node + 1, V, m, adj, ncolor)) return true;
                ncolor[node] = -1;
            }
        }
        return false;
    }
    bool graphColoring(int V, vector<vector<int>> &edges, int m) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> ncolor(V, -1);
        return solve(0, V, m, adj, ncolor);
    }
};


/*
Time Complexity: O(m^V) 
Space Complexity: O(V+E) overall.
*/