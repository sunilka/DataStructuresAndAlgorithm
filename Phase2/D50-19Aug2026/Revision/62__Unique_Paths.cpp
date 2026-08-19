/*
62. Unique Paths
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:
Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 

Constraints:

1 <= m, n <= 100
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int m, int n, int i, int j){
        if(i==m-1 && j==n-1) return 1;
        if(i < 0 || i>=m || j<0 || j>=n) return 0;
        int ans = solve(m, n, i+1, j) + solve(m, n, i, j+1);
        return ans;
    }
    int uniquePaths(int m, int n) {
        return solve(m, n, 0, 0);
    }
};

/*
Time complexity: O(2^(N+M)), where M is the number of rows of the given matrix and N is the number of cols in the given matrix.
Space complexity: O(M+N) auxiliary stack space.
*/

/*
Top down memoization
*/

class Solution {
public:
    int solve(int m, int n, int i, int j, vector<vector<int>>& dp){
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(i < 0 || i>=m || j<0 || j>=n) return 0;
        int ans = solve(m, n, i+1, j, dp) + solve(m, n, i, j+1, dp);
        dp[i][j] = ans;
        return ans;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(m, n, 0, 0, dp);
    }
};

/*
Time complexity: O(M*N), where M is the number of rows and N is the number of cols.
Space complexity: O(M*N) for the DP array , O(N+M) auxiliary stack space. 
*/

/*
Bottom up approach
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i==m-1 && j==n-1) dp[i][j] = 1;
                else dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};

/*
Time complexity: O(M*N), where M is the number of rows and N is the number of cols.
Space complexity: O(M*N) for the DP array. Please note that we are not using an auxiliary stack space here. 
*/


/*
Space optimization.
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> next(n+1, 0), cur(n+1, 0);
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i==m-1 && j==n-1) cur[j] = 1;
                else cur[j] = next[j] + cur[j+1];
            }
            next = cur;
        }
        return next[0];
    }
};

/*
Time complexity: O(M*N), where M is the number of rows and N is the number of cols.
Space complexity: O(2N) = O(N) for the DP array.
*/


