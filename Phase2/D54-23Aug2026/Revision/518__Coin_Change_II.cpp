/*
518. Coin Change II
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The final answer is guaranteed to fit into a signed 32-bit integer.
Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
 

Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& coins, int &n, int target, int idx){
        if(target == 0) return 1;
        if(idx >= n) return 0;
        int notake = solve(coins, n, target, idx+1);
        int take = 0;
        if(target - coins[idx] >= 0){
            take = solve(coins, n, target - coins[idx], idx);
        }
        return take + notake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return solve(coins, n, amount, 0);
    }
};

/*
Time Complexity: O(2 ^amount/min(coins))
It is exponential, but not limited by N. Because you stay at the same index idx when taking a coin, the recursion tree depth reaches up to  
min(coins) amount.
Space Complexity: O(N+ min(coins)/amount) auxiliary stack space.
*/

/*
Top down approach memoization.
*/

class Solution {
public:
    int solve(vector<int>& coins, int &n, int target, int idx, vector<vector<int>>& dp){
        if(target == 0) return 1;
        if(idx >= n) return 0;
        if(dp[idx][target]!=-1) return dp[idx][target];
        int notake = solve(coins, n, target, idx+1, dp);
        int take = 0;
        if(target - coins[idx] >= 0){
            take = solve(coins, n, target - coins[idx], idx, dp);
        }
        return dp[idx][target] = take + notake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return solve(coins, n, amount, 0, dp);
    }
};

/*
Time complexity: O(N*target), where N is the number of elements present in the array and target is the given amount value.
Space complexity: O(N*target) for the DP array, and O(N+target) auxiliary stack space.
*/

/*
Bottom up tabulation method.
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned int>> dp(n+1, vector<unsigned int>(amount+1, 0));
        dp[n][0] = 1;
        for(int idx=n-1; idx>=0; idx--){
            for(int target=0; target<=amount; target++){
                unsigned int notake = dp[idx+1][target];
                unsigned int take = 0;
                if(target - coins[idx] >= 0){
                    take = dp[idx][target - coins[idx]];
                }
                dp[idx][target] = take + notake;
            }
        }
        return dp[0][amount];
    }
};

/*
Time complexity: O(N*target), where N is the number of elements present in the array and target is the given amount value.
Space complexity: O(N*target) for the DP array and there is no auxiliary space involved here. 
*/

/*
Space optimization.
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned int> cur(amount+1, 0), next(amount+1, 0);
        next[0] = 1;
        for(int idx=n-1; idx>=0; idx--){
            for(int target=0; target<=amount; target++){
                unsigned int notake = next[target];
                unsigned int take = 0;
                if(target - coins[idx] >= 0){
                    take = cur[target - coins[idx]];
                }
                cur[target] = take + notake;
            }
            next = cur;
        }
        return next[amount];
    }
};

/*
Time complexity: O(N*target), where N is the number of elements present in the array and target is the given amount value.
Space complexity: O(target) for the DP array and there is no auxiliary space involved here. 
*/

