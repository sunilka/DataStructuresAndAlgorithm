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
    int solve(vector<int>& coins, int target, int idx, int csum, vector<vector<int>> &dp){
        int n = coins.size();
        if(csum == target) return 1;
        if (idx >= coins.size()) return 0;
        if(dp[idx][csum]!=-1) return dp[idx][csum];
        int ans = 0;
        int take = 0;
        if(csum+coins[idx]<=target){
            take+=solve(coins, target, idx, csum + coins[idx], dp);
        }
        int skip = solve(coins, target, idx + 1, csum, dp);
        return dp[idx][csum] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int tot_sum = accumulate(coins.begin(), coins.end(), 0);
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return solve(coins, amount, 0, 0, dp);
    }
};

/*
Time complexity: O(N*T), where N is the number of elements present in the array and T is my target sum.
Space complexity: O(N*T)+O(N+T) aux space, where N is the number of elements present in the array and T is my target sum
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned int> cur(amount + 1, 0);
        vector<unsigned int> next(amount + 1, 0);
        
        next[amount] = 1;

        for (int idx = n - 1; idx >= 0; idx--) {
            cur[amount] = 1;
            for (int csum = amount - 1; csum >= 0; csum--) {
                unsigned int take = 0;
                if (csum + coins[idx] <= amount) {
                    take = cur[csum + coins[idx]];
                }
                unsigned int skip = next[csum];
                
                cur[csum] = take + skip; 
            }
            next = cur; 
        }
        
        return next[0];
    }
};

/*
Time complexity: O(N*T), where N is the number of elements present in the array and T is my target sum.
Space complexity: O(T), where N is the number of elements present in the array and T is my target sum
*/