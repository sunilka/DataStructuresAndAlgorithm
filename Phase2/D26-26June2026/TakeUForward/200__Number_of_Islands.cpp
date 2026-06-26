/*
200. Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

*/

#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(vector<vector<char>>& grid, int sr, int sc){
    int m = grid.size(), n = grid[0].size();
    grid[sr][sc] = '0';

    for(int i=0; i<dirs.size(); i++){
        int nr = sr+dirs[i].first, nc = sc+dirs[i].second;

        if(nr<0 || nr >= m || nc <0 || nc>=n) continue;
        if(grid[nr][nc] == '0') continue;
        dfs(grid, nr, nc);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int ans = 0, m = grid.size(), n = grid[0].size();
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == '1'){
                ans+=1;
                dfs(grid, i, j);
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<char>> grid = {{'1','1','1','1','0'}, {'1','1','0','1','0'}, {'1','1','0','0','0'}, {'0','0','0','0','0'}};
    int ans = numIslands(grid);
    cout<<"Printing the number of islands here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(m*n), where m is the number of rows present in the grid and n is the number of cols present in the grid.
Space complexity: O(m*n) -> call stack. where m is the number of rows present in the grid and n is the number of cols present in the grid. 

*/