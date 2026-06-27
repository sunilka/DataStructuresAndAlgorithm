/*

Directed Graph Cycle

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from vertex u to v.

Examples:

Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 0], [2, 3]]
Output: true
Explanation: The diagram clearly shows a cycle 0 → 1 → 2 → 0

Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: false
Explanation: no cycle in the graph
Constraints:
1 ≤ V ≤ 105
0 ≤ E ≤ 105
0 ≤ edges[i][0], edges[i][1] < V

*/

#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& connections, vector<bool>& visited, vector<bool>& pathVisited, int src){
    visited[src] = true;
    pathVisited[src] = true;

    for(int i=0; i<connections[src].size(); i++){
        int connected_node = connections[src][i];

        if(visited[connected_node] == false){
            bool ans = dfs(connections, visited, pathVisited, connected_node);
            if(ans == true) return true;
        }

        else if(pathVisited[connected_node] == true) return true;
    }
    pathVisited[src] = false;
    return false;
}

bool isCyclic(int V, vector<vector<int>> &edges) { 
    vector<vector<int>> connections(V);
    for(auto edge: edges) connections[edge[0]].push_back(edge[1]);
    vector<bool> visited(V, false);
    vector<bool> pathVisisted(V, false);

    for(int i=0; i<V; i++){
        if(visited[i] == false){
            bool ans = dfs(connections, visited, pathVisisted, i);
            if(ans == true) return true;
        }
    }
    return false;
}

int main(){
    int V=4;
    vector<vector<int>> edges={{1,2,3},{0,2},{0,1,3},{0,2}};  
    bool ans = isCyclic(V, edges);
    cout<<"Printing my answer here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(V+E), where V is the number of nodes and E is the number of edges.
Space complexity: O(2*V)=O(V), where V is the number of nodes in the graph. 

*/