/*

994. Rotting Oranges

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.

*/

#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    int ans = 0, m = grid.size(), n = grid[0].size(), fresh_oranges = 0;
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Get all the oranges that are rotten in the 0th second.
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 2) q.push({i, j});
            else if(grid[i][j] == 1) fresh_oranges++;
        }
    }

    while(!q.empty()){
        // Get all the oranges that were rotten the before'th minute.
        int s = q.size();
        bool nor = false;
        while(s--){
            auto [posr, posc] = q.front();
            q.pop();    

            for(int i=0; i<dirs.size(); i++){
                int nposr = posr + dirs[i].first;
                int nposc = posc + dirs[i].second;

                if(nposr >= m || nposr <0 || nposc >= n || nposc < 0) continue;

                if(grid[nposr][nposc] == 1){
                    nor = true;
                    grid[nposr][nposc] = 2;
                    q.push({nposr, nposc});
                    fresh_oranges--;
                }
            }
        }

        if(nor) ans+=1;
    }
    return (fresh_oranges == 0) ? ans : -1;
}

int main(){
    vector<vector<int>> grid = {{2,1,1},{0,1,1},{1,0,1}};
    int ans = orangesRotting(grid);
    cout<<"Printing the answer here "<<ans<<endl;
}

/* 

Complexity analysis:

Time complexity: O(m*n), where m is the number of rows present in the grid and the n is the number of cols present in the grid.
Space complexity: O(m*n), where m is the number of rows present in the grid and the n is the number of cols present in the grid. This is for 
the queue.

*/