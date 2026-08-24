/*
Rod Cutting
Given a rod of length n inches and an array price[], where price[i] denotes the value of a piece of length i (1-based Index). Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: The value of n is equal to the size of price array.

Example:

Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
Output: 22
Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.
Input: price[] = [3, 5, 8, 9, 10, 17, 17, 20]
Output: 24
Explanation: The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1] = 8*3 = 24.
Input: price[] = [3]
Output: 3
Explanation: There is only 1 way to pick a piece of length 1.
Constraints:

1 ≤ price.size() ≤ 103
1 ≤ price[i] ≤ 106
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(vector<int>& price, int rl, vector<int>& dp){
        if(rl == 0) return 0;
        if(dp[rl]!=-1) return dp[rl];
        int max_val = 0;
        for(int i=0; i<price.size(); i++){
            int len = i+1;
            if(rl - len >=0){
                int ans = solve(price, rl - len, dp)+price[i];
                max_val = max(max_val, ans);
            }
        }
        return dp[rl] = max_val;
    }
    int cutRod(vector<int> &price) {
        vector<int> dp(price.size()+1, -1);
        return solve(price, price.size(), dp);
    }
};

/*
Time complexity: O(rl*N), where N is the lenght of the prices array and rl is the rod length.
Space complexity: O(rl) for the DP array and O(rl) auxiliary stack space
*/

/*
Bottom up tabulation method.
*/

class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n=price.size();
        vector<int> dp(n+1, 0);
        for(int rl=0; rl<=n; rl++){
            int max_val = 0;
            for(int i=0; i<price.size(); i++){
                int len = i+1;
                if(rl - len >=0){
                    int ans = dp[rl - len]+price[i];
                    max_val = max(max_val, ans);
                }
            }
            dp[rl] = max_val;
        }
        return dp[n];
    }
};

/*
Time complexity: O(rl*N), where N is the lenght of the prices array and rl is the rod length.
Space complexity: O(rl) for the DP array and please note that there is no auxiliary stack space involved in this 
approach at all.
*/