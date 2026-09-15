/*
Consecutive 1's not allowed

Given a positive integer n, count all possible distinct binary strings of length n such that there are no consecutive 1’s.

Examples :

Input: n = 3
Output: 5
Explanation: 5 strings are ("000", "001", "010", "100", "101").
Input: n = 2
Output: 3
Explanation: 3 strings are ("00", "01", "10").
Input: n = 1
Output: 2
Constraints:
1 ≤ n ≤ 44
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(int n, int prev, vector<vector<int>>& dp){
        if(n==0) return 1;
        if(dp[n][prev+1]!=-1) return dp[n][prev+1];
        if(prev == 0 || prev == -1){
            return dp[n][prev+1] = solve(n-1, 0, dp) + solve(n-1, 1, dp);
        }
        else{
            return dp[n][prev+1] = solve(n-1, 0, dp);
        }
    }
    int countStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        int ans = solve(n, -1, dp);
        return ans;
    }
};

/*
Time complexity: O(N*2), where N is the given n.
Space complexity: O(N*3) for the DP array and O(N) auxiliary stack space is used because of the recursion here. 
*/

/*
Tabulation method.
*/
class Solution {
  public:
    int countStrings(int nn) {
        vector<vector<int>> dp(nn+1, vector<int>(3, 0));
        for(int i=0; i<3; i++) dp[0][i] = 1;
        for(int n=1; n<=nn; n++){
            for(int prev = -1; prev<=1; prev++){
                if(prev == 0 || prev == -1) dp[n][prev+1] = dp[n-1][1] + dp[n-1][2];
                else dp[n][prev+1] = dp[n-1][1];
            }
        }
        return dp[nn][0];
    }
};

/*
Time complexity: O(N*3), where N is the given n.
Space complexity: O(N*3), for the DP array and please note here that we are not using an extra stack space. 
*/

/*
Space optimization.
*/
class Solution {
  public:
    int countStrings(int nn) {
        vector<int> prevv(3, 0), curr(3, 0);
        for(int i=0; i<3; i++) prevv[i] = 1;
        for(int n=1; n<=nn; n++){
            for(int prev = -1; prev<=1; prev++){
                if(prev == 0 || prev == -1) curr[prev+1] = prevv[1] + prevv[2];
                else curr[prev+1] = prevv[1];
            }
            prevv = curr;
        }
        return prevv[0];
    }
};

/*
Time complexity: O(N*3), where N is the given n.
Space complexity: O(1), almost constant space, since its O(3)
*/