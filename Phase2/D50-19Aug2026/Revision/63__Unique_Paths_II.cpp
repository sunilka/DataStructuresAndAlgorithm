/*
63. Unique Paths II

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, int &m, int &n, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n) return 0;
        if(i == m-1 && j == n-1) return 1;  
        int right = 0;
        if(j+1 < n && obstacleGrid[i][j+1] == 0){
            right += solve(obstacleGrid, m, n, i, j+1);
        }

        int down = 0;
        if(i+1 < m && obstacleGrid[i+1][j] == 0){
            down += solve(obstacleGrid, m, n, i+1, j);
        }
        return right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        return solve(obstacleGrid, m, n, 0, 0);
    }
};

/*
Time complexity: O(2^(M+N)), where M is the number of rows and N is the number of cols in the given matrix.
Space complexity: O(M*N) for the DP array and O(M+N) auxiliary space complexity.
*/

/*
Top down approach with memoization.
*/

class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, int &m, int &n, int i, int j, vector<vector<int>>& dp){
        if(i<0 || i>=m || j<0 || j>=n) return 0;
        if(i == m-1 && j == n-1) return 1;  
        if(dp[i][j] != -1) return dp[i][j];
        int right = 0;
        if(j+1 < n && obstacleGrid[i][j+1] == 0){
            right += solve(obstacleGrid, m, n, i, j+1, dp);
        }

        int down = 0;
        if(i+1 < m && obstacleGrid[i+1][j] == 0){
            down += solve(obstacleGrid, m, n, i+1, j, dp);
        }
        dp[i][j] = right + down;
        return right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(obstacleGrid, m, n, 0, 0, dp);
    }
};

/*
Time complexity: O(M*N), where M is the number of rows and N is the number of cols in the given matrix.
Space complexity: O(M*N) for the DP array and O(M+N) auxiliary space complexity.
*/

/*
Bottom up approach or tabulation method.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i == m-1 && j == n-1) dp[i][j] = 1;
                else{
                    long long down = 0, right = 0;
                    if(j+1 < n && obstacleGrid[i][j+1] == 0) right += dp[i][j+1];
                    if(i+1 < m && obstacleGrid[i+1][j] == 0) down += dp[i+1][j];
                    dp[i][j] = right + down;
                }
            }
        }
        return dp[0][0];
    }
};

/*
Time complexity: O(M*N), where M is the number of rows and N is the number of cols in the given matrix.
Space complexity: O(M*N) for the DP array and please note that there is not stack space involved here.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        vector<long long> next(n+1, 0), cur(n+1, 0);
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i == m-1 && j == n-1) cur[j] = 1;
                else{
                    long long down = 0, right = 0;
                    if(j+1 < n && obstacleGrid[i][j+1] == 0) right += cur[j+1];
                    if(i+1 < m && obstacleGrid[i+1][j] == 0) down += next[j];
                    cur[j] = right + down;
                }
            }
            next = cur;
        }
        return cur[0];
    }
};

/*
Time complexity: O(M*N), where M is the number of rows and N is the number of cols in the given matrix.
Space complexity: O(2N) = O(N) for the DP array.
*/