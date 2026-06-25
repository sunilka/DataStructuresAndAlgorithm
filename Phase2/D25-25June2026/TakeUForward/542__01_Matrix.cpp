/*

542. 01 Matrix

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 
Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.

*/

#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(vector<vector<int>>& mat, int si, int sj){
    set<pair<int, int>> visited;
    int m = mat.size(), n = mat[0].size();
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {si, sj}});
    visited.insert({si, sj});

    while(!q.empty()){
        int ci = q.front().second.first, cj = q.front().second.second, cd = q.front().first;
        q.pop();
        if(mat[ci][cj] == 0) return cd;

        for(int i=0; i<dirs.size(); i++){
            int ni = ci + dirs[i].first, nj = cj + dirs[i].second;
            if(ni<0 || ni>=m || nj<0 || nj>=n) continue;
            else if(visited.count({ni, nj})) continue;
            else{
                q.push({cd+1, {ni, nj}});
                visited.insert({ni, nj});
            }
        }
    }
    return -1;
}

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> ans(m, vector<int>(n, 0));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 0) ans[i][j] = 0;
            else{
                int sd = bfs(mat, i, j);
                ans[i][j] = sd;
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    vector<vector<int>> ans = updateMatrix(mat);
    cout<<"Printing the answer here "<<endl;
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

/*

Complexity analysis:

Time complexity: O( (m*n)^2 log(m*n)), where m is the row size and the n is the col size of the matrix.
Space complexity: O(m*n)

*/