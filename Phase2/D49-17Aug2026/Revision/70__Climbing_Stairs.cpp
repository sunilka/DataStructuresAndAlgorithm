/*
70. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int curpos, vector<int>& dp){
        if(curpos == n) return 1;
        if(curpos > n) return 0;
        if(dp[curpos]!=-1) return dp[curpos];
        int ans = solve(n, curpos+1, dp) + solve(n, curpos+2, dp);
        dp[curpos] = ans;
        return ans;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, 0, dp);
    }
};

/*
Time complexity: O(N), where N is the target number of steps given to us.
Space complexity: O(N) for the DP array that we are using and O(N) auxiliary stack space.
*/

/*
Tabulation method
*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+2, 0);
        dp[n] = 1;
        for(int curpos=n-1; curpos>=0; curpos--){
            int ans = dp[curpos+1] + dp[curpos+2];
            dp[curpos] = ans;
        }
        return dp[0];
    }
};

/*
Time complexity: O(N), where N is the target number of steps given to us.
Space complexity: O(N) for the DP array that we are using note here that the auxiliary stack space that 
was present in the recursive solution is not present here.
*/

/*
Space optimization
*/

class Solution {
public:
    int climbStairs(int n) {
        int next1 = 1, next2 = 0;
        for(int curpos=n-1; curpos>=0; curpos--){
            int ans = next1 + next2;
            next2 = next1;
            next1 = ans;
        }
        return next1;
    }
};

/*
Time complexity: O(N), where N is the target number of steps given to us.
Space complexity: O(1) constant space, since we are just using the variables here.
*/
