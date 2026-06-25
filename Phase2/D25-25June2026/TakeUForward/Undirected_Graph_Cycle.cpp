/*=
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

bool bfs(vector<vector<int>>& connections, int sn, vector<bool>& visited){
    queue<pair<int, int>> q;
    q.push({-1, sn});
    visited[sn] = true;

    while(!q.empty()){
        auto [parent, node] = q.front();
        q.pop();
        vector<int>& connected_nodes = connections[node];
        for(int i=0; i<connected_nodes.size(); i++){
            int cn = connected_nodes[i];
            if(visited[cn] == true && cn!=parent) return true;
            else if(visited[cn] == true) continue;
            else{
                visited[cn] = true;
                q.push({node, cn});
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> connections(V);
    vector<bool> visited(V, false);
    for(auto edge: edges){
        int u = edge[0], v = edge[1];
        connections[u].push_back(v);
        connections[v].push_back(u);
    }

    for(int i=0; i<V; i++){
        if(visited[i] == false){
            bool ans = bfs(connections, i, visited);
            if(ans == true) return true;
        }
    }
    return false;
}

int main(){
    int V = 4, E = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};
    bool ans = isCycle(V, edges);
    cout<<"Printing the answer here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(V+E), where V is the number of vertices and E is the number of edges. (standard BFS time complexity)
Space complexity:  O(V+E), where V is the number of vertices and E is the number of edges. (standard BFS space complexity)

*/