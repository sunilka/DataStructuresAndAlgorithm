/*
64. Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& grid, int& m, int& n, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n) return INT_MAX;
        if(i == m-1 && j == n-1) return grid[i][j];
        int down = solve(grid, m, n, i+1, j);
        int right = solve(grid, m, n, i, j+1);
        int ans = min(down, right)+grid[i][j];
        return ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        return solve(grid, m, n, 0, 0);
    }
};

/*
Time complexity: O(2^(M+N)), where M is the number of rows and N is the number of cols present. 
Space complexity: O(M+N), where M is the number of rows and N is the number of cols present. 
*/

class Solution {
public:
    int solve(vector<vector<int>>& grid, int& m, int& n, int i, int j, vector<vector<int>>& dp){
        if(i>=m || j>=n) return INT_MAX;
        if(i == m-1 && j == n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down = solve(grid, m, n, i+1, j, dp);
        int right = solve(grid, m, n, i, j+1, dp);
        int ans = min(down, right)+grid[i][j];
        dp[i][j] = ans;
        return ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(grid, m, n, 0, 0, dp);
    }
};

/*
Time complexity: O(M*N), where M is the number of rows and N is the number of cols present. 
Space complexity: O(M*N) for the DP array and O(M+N) auxiliary stack space. 
*/

/*
Bottom up PDP, tabulation method
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        dp[m-1][n-1] = grid[m-1][n-1];
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if (i == m - 1 && j == n - 1) continue;
                int down = dp[i+1][j];
                int right = dp[i][j+1];
                int ans = min(down, right)+grid[i][j];
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};

/*
Time complexity: O(M*N), where M is the number of rows and N is the number of cols present. 
Space complexity: O(M*N) for the DP array. Please note here that there is no auxiliary stack space being used. 
*/

/*
Space optimization.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> next(n+1, INT_MAX), cur(n+1, INT_MAX);
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if (i == m - 1 && j == n - 1){
                    cur[j] = grid[m-1][n-1];
                    continue;
                }
                int down = next[j];
                int right = cur[j+1];
                int ans = min(down, right)+grid[i][j];
                cur[j] = ans;
            }
            next = cur;
        }
        return next[0];
    }
};

/*
Time complexity: O(M*N), where M is the number of rows and N is the number of cols present. 
Space complexity: O(N) for the DP array. Please note here that there is no auxiliary stack space being used. 
*/
