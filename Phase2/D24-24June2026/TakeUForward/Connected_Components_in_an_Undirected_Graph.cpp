/*

Connected Components in an Undirected Graph

Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v.
Your task is to return a list of all connected components. Each connected component should be represented as a list of its vertices, with all components returned in a collection where each component is listed separately.
Note: You can return the components in any order, driver code will print the components in sorted order.

Examples :

Input: V = 5, edges[][] = [[0, 1], [2, 1], [3, 4]]
Output: [[0, 1, 2], [3, 4]]
Explanation:

Input: V = 7, edges[][] = [[0, 1], [6, 0], [2, 4], [2, 3], [3, 4]]
Output: [[0, 1, 6], [2, 3, 4], [5]]
Explanation:

Constraints:
1 ≤ V, E ≤ 105
0 ≤ edges[i][0], edges[i][1] < V

*/

#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& connections, vector<bool>& visited, int sn, vector<int>& tans){
    queue<int> q;
    q.push(sn);
    visited[sn] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        tans.push_back(node);
        vector<int> cs = connections[node];
        for(int i=0; i<cs.size(); i++){
            if(visited[cs[i]] == false){
                visited[cs[i]] = true;
                q.push(cs[i]);
            }
        }
    }
}


vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
    vector<vector<int>> connections(V);
    vector<bool> visited(V, false);
    vector<vector<int>> ans;

    // Making the adjacency matrix
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0], v = edges[i][1];
        connections[u].push_back(v);
        connections[v].push_back(u);
    }

    for(int i=0; i<V; i++){
        if(visited[i] == false){
            vector<int> tans;
            bfs(connections, visited, i, tans);
            ans.push_back(tans);
        }
    }

    return ans;
}

int main(){
    int V = 7;
    vector<vector<int>> edges = {{0, 1}, {6, 0}, {2, 4}, {2, 3}, {3, 4}};
    vector<vector<int>> ans = getComponents(V, edges);
    cout<<"Printing the answer here "<<endl;
    for(auto a: ans){
        for(auto ele: a) cout<<ele<<" ";
        cout<<endl;
    }
}

/*

Complexity analysis:

Time complexity: O(V+E), where V is the number of nodes and E is the number of edges.
Space complexity: O(V+E), where V is the number of nodes and E is the number of edges.

*/