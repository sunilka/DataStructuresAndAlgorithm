/*
Connected Components in an Undirected Graph
Difficulty: MediumAccuracy: 48.5%Submissions: 42K+Points: 4
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

// Solving this question with the help of disjoint set union.

#include<bits/stdc++.h>
using namespace std;

vector<int> parent, size;

int find_parent(int u){
    if(parent[u] == u) return u;
    return parent[u] = find_parent(parent[u]);
}

void union_of_elements(int u, int v){
    int parent_u = find_parent(u);
    int parent_v = find_parent(v);

    if(parent_u == parent_v) return;

    // You got to attach the smallest size one to the larger one.
    if(size[parent_u] > size[parent_v]){ 
        parent[parent_v] = parent_u;
        size[parent_u] += size[parent_v];
    }
    else{
        parent[parent_u] = parent_v;
        size[parent_v] += size[parent_u];
    }
}

vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
    parent.resize(V);
    size.resize(V, 1);
    iota(parent.begin(), parent.end(), 0);
    for(auto &ele: edges) union_of_elements(ele[0], ele[1]);

    unordered_map<int, vector<int>> m;
    for(int i=0; i<V; i++){
        int root_leader = find_parent(i);
        m[root_leader].push_back(i);
    }

    vector<vector<int>> ans;
    for(auto &[key, val]: m) ans.push_back(val);
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

Time complexity: O(V+E*alpha(V)), where V is the number of nodes and E is the number of edges in the graph and the alpha is the Inverse
Ackermann function. This inverse arkermann function grows very slow and its near to just <= 4 for all partical situations,
Space complexity: O(V), where V is the number of nodes present in the graph.

*/