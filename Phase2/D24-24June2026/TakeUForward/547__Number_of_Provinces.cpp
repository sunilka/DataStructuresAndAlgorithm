/*

547. Number of Provinces

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

Example 1:

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]

Output: 3
 
Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]

*/

#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& isConnected, vector<bool>& visited, int V, int sn){
    queue<int> q;
    q.push(sn);
    visited[sn] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=0; i<V; i++){
            if(i == node || isConnected[node][i] == 0) continue;
            if(visited[i]==true) continue;
            q.push(i);
            visited[i] = true;
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int V = isConnected.size();
    vector<bool> visited(V, false);
    int ans = 0;

    for(int i=0; i<V; i++){
        if(visited[i] == false){
            ans+=1;
            bfs(isConnected, visited, V, i);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> isConnected;
    int ans = findCircleNum(isConnected);
    cout<<"Printing my answer here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(V^2) where V is the number of nodes present in the graph. We are using adjacency matrix, hence, for every node we will
have to scan the whole row to check for connections and hence the time complexity is V^2.
Space complexity: O(V), where V is the number of nodes present in the graph.

*/