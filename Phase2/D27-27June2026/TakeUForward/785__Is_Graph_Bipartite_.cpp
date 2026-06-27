/*

785. Is Graph Bipartite?

There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

Example 1:

Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.

Example 2:

Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
 

Constraints:

graph.length == n
1 <= n <= 100
0 <= graph[u].length < n
0 <= graph[u][i] <= n - 1
graph[u] does not contain u.
All the values of graph[u] are unique.
If graph[u] contains v, then graph[v] contains u.

*/

#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& graph, vector<int>& color, int src, int c){
    color[src] = c;
    for(int i=0; i<graph[src].size(); i++){
        int connected_node = graph[src][i];
        if(color[connected_node] == -1) {
            bool ans = dfs(graph, color, connected_node, !c);
            if(ans == false) return false;
        }

        else if(color[connected_node] == c) return false;
    }
    return true;
}


bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> color(V, -1);

    for(int i=0; i<V; i++){
        if(color[i] == -1){
            bool ans = dfs(graph, color, i, 0);
            if(!ans) return false;
        }
    }
    return true;
}

int main(){
    vector<vector<int>> graph;
    bool ans = isBipartite(graph);
    cout<<"Printing my answer here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(V+E), where V is the number of nodes in the graph and E is the number of edges present in the graph.
Space complexity: O(V) space for the color array.

*/