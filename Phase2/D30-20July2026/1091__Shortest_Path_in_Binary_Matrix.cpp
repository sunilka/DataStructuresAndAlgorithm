/*
1091. Shortest Path in Binary Matrix

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

Example 1:
Input: grid = [[0,1],[1,0]]
Output: 2

Example 2:
Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Example 3:
Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
 
Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        grid[0][0] = 1;

        while(!q.empty()){
            pair<int, pair<int, int>> info = q.front();
            q.pop();
            int dist = info.first, r = info.second.first, c = info.second.second;
            if(r == m-1 && c == n-1) return dist;
            for(int i=0; i<dirs.size(); i++){
                int nr = r + dirs[i].first, nc = c + dirs[i].second;
                if(nr >= m || nr <0 || nc >= n || nc < 0) continue;
                if(grid[nr][nc] == 1) continue;
                grid[nr][nc] = 1;
                q.push({dist+1, {nr, nc}});
            }
        }
        return -1;
    }

    int main(){
        vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};
        int ans = shortestPathBinaryMatrix(grid);
        cout<<"Printing the shortest answer here "<<ans<<endl;
    }
};

/*
Time complexity: O(m*n), where m is the number of rows and n is the number of cols.
Space complexity: O(m*n), where m is the number of rows and n is the number of cols.
*/