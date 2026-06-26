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

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> ans(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 0) {
                ans[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    
    vector<pair<int, int>> dirs  = {{-1,0}, {1,0}, {0,-1}, {0, 1}};

    while(!q.empty()){
        int cr = q.front().first, cc = q.front().second;
        q.pop();

        for(int i=0; i<dirs.size(); i++){
            int nr = cr + dirs[i].first, nc = cc + dirs[i].second;
            if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if(ans[nr][nc]!=-1) continue;
            ans[nr][nc] = ans[cr][cc]+1;
            q.push({nr, nc});
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

Time complexity: O(m*n), where m is the number of rows and n is the number of cols present in the matrix.
Space complexity: O(m*n),  where m is the number of rows and n is the number of cols present in the matrix.

*/