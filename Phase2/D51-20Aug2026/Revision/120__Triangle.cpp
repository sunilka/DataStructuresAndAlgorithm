/*
120. Triangle
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 

Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& triangle, int& m, int i, int j){
        if(i == m-1) return triangle[i][j];
        int ans = min(
            solve(triangle, m, i+1, j)+triangle[i][j], 
            solve(triangle, m, i+1, j+1)+triangle[i][j]
        );
        return ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, INT_MAX));
        return solve(triangle, m, 0, 0);
    }
};

/*
Time complexity: O(2^(N)), where N is the number of rows present in the given array.
Space complexity: O(N) for call stack
*/

/*
Top down memoization solution.
*/
class Solution {
public:
    int solve(vector<vector<int>>& triangle, int& m, int i, int j, vector<vector<int>>& dp){
        if(i == m-1) return triangle[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];
        int ans = min(
            solve(triangle, m, i+1, j, dp)+triangle[i][j], 
            solve(triangle, m, i+1, j+1, dp)+triangle[i][j]
        );
        dp[i][j] = ans;
        return ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, INT_MAX));
        return solve(triangle, m, 0, 0, dp);
    }
};

/*
Time complexity: O(N*N) = O(N^2) where N is the number of rows present in the array.
Space complexity: O(N*N) = O(N^2) for the DP array and O(N) auxiliary stack space.
*/

/*
Bottom up - tabulation method
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, INT_MAX));
        for(int i=m-1; i>=0; i--){
            for(int j=triangle[i].size()-1; j>=0; j--){
                int ans = INT_MAX;
                if(i == m-1) ans = triangle[i][j];
                else ans = min(dp[i+1][j]+triangle[i][j], dp[i+1][j+1]+triangle[i][j]);
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};

/*
Time complexity: O(N*N) = O(N^2) where N is the number of rows present in the array.
Space complexity: O(N*N) = O(N^2) for the DP array. Please note here that we are not using an auxiliary stack space.
*/

/*
Space optimization.
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> cur(m+1, INT_MAX), next(m+1, INT_MAX);
        for(int i=m-1; i>=0; i--){
            for(int j=triangle[i].size()-1; j>=0; j--){
                int ans = INT_MAX;
                if(i == m-1) ans = triangle[i][j];
                else ans = min(next[j]+triangle[i][j], next[j+1]+triangle[i][j]);
                cur[j] = ans;
            }
            next = cur;
        }
        return next[0];
    }
};


/*
Time complexity: O(N*N) = O(N^2) where N is the number of rows present in the array.
Space complexity: O(N) for the DP array. Please note here that we are not using an auxiliary stack space.
*/


