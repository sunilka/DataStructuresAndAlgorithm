/*
1319. Number of Operations to Make Network Connected

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

Example 1:


Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:


Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
 

Constraints:

1 <= n <= 105
1 <= connections.length <= min(n * (n - 1) / 2, 105)
connections[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated connections.
No two computers are connected by more than one cable.
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int find_parent(int u){
        if(parent[u] == u) return u;
        return parent[u] = find_parent(parent[u]);
    }

    void union_of_elements(int u, int v){
        int parent_u = find_parent(u);
        int parent_v = find_parent(v);

        if(parent_u == parent_v) return;

        if(size[parent_u] > size[parent_v]){
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
        else{
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        parent.resize(n);
        size.resize(n);
        iota(parent.begin(), parent.end(), 0);
        fill(size.begin(), size.end(), 1);

        for (auto conn : connections) {
            union_of_elements(conn[0], conn[1]);
        }

        set<int> connected_components;
        for(int i=0; i<n; i++){
            int parent = find_parent(i);
            connected_components.insert(parent);
        }        

        return connected_components.size() - 1;
    }
};

/*
Time complexity: O(E+V*alpha(V)), where is the number of given edges and V is the number of the given vertices.
Space complexity: O(V)
*/