/*
1020. Number of Enclaves

You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:
Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

Example 2:
Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.

*/

#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(vector<vector<int>>& grid, int sr, int sc){
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;
    q.push({sr, sc});
    grid[sr][sc] = 2;

    while(!q.empty()){
        auto [cr, cc] = q.front();
        
        q.pop();
        for(int i=0; i<dirs.size(); i++){
            int nr = cr + dirs[i].first, nc = cc + dirs[i].second;
            if(nr<0 || nr>=m || nc<0 || nc>=n) continue;
            if(grid[nr][nc]!=1) continue;
            grid[nr][nc] = 2;
            q.push({nr, nc});
        }
    }
}

int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    // Check the top edge.
    for(int i=0; i<n; i++){
        if(grid[0][i] == 1) bfs(grid, 0, i);
    }

    // Check the right edge
    for(int i=0; i<m; i++){
        if(grid[i][n-1] == 1) bfs(grid, i, n-1);
    }

    // Check the bottom edge
    for(int i=0; i<n; i++){
        if(grid[m-1][i] == 1) bfs(grid, m-1, i);
    }

    // Check the left edge
    for(int i=0; i<m; i++){
        if(grid[i][0] == 1) bfs(grid, i, 0);
    }

    int ans = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1) ans+=1;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    int ans = numEnclaves(grid);
    cout<<"Printing my answer here "<<ans<<endl;
}   

/*

Complexity analysis:

Time complexity: O(m*n), where m is the rows and n is the number of cols present in the given matrix.
- Perimeter scanning takes O(m + n) steps to locate starting points.
- The BFS wave expands through any edge-connected land component, visiting a maximum of m*n cells exactly once.
- The final nested counting loop scans every single coordinate in the matrix, contributing exactly m*n operations.

Space complexity: O(m*n), where m is the rows and n is the number of cols present in the given matrix.
- Because the algorithm modifies the matrix completely in-place, zero auxiliary arrays or vectors are allocated.
- The memory bound is determined entirely by the standard BFS `queue`, which can hold a maximum of O(m*n) elements at the absolute peak of the wave expansion.

*/