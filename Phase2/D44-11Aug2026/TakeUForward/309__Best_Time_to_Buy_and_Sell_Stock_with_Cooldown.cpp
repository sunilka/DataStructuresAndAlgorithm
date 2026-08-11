/*
309. Best Time to Buy and Sell Stock with Cooldown

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& prices, int n, int idx, bool buy, vector<vector<int>>& dp){
        if(idx >= n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        if(buy){
            int ans = max(
                solve(prices, n, idx+1, false, dp)-prices[idx],
                solve(prices, n, idx+1, buy, dp)
            );
            dp[idx][buy] = ans;
            return ans;
        }
        else{
            int ans = max(
                solve(prices, n, idx+2, true, dp)+prices[idx],
                solve(prices, n, idx+1, buy, dp)
            );
            dp[idx][buy] = ans;
            return ans;
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        return solve(prices, n, 0, true, dp);
    }
};

/*
Time complexity: O(N*3), where N is the number of elements present in the prices array given.
Space complexity: O(N*3)+O(N+3) aux space 
*/

/*
Bottom up approach
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(3, 0));
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                int ans;
                if(buy) ans = max(dp[idx+1][0]-prices[idx], dp[idx+1][buy]);
                else{
                    if(idx+2 < n) ans = max(dp[idx+2][1]+prices[idx], dp[idx+1][buy]);
                    else ans = max(prices[idx], dp[idx+1][buy]);
                }
                dp[idx][buy] = ans;
            }
        }
        return dp[0][1];
    }
};

/*
Time complexity: O(N*3), where N is the number of elements present in the prices array given.
Space complexity: O(N*3)
*/

/*
Space optimized.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(3, 0));
        vector<int> cur(3, 0), next(3, 0), next_of_next(3, 0);
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                int ans;
                if(buy) ans = max(next[0]-prices[idx], next[buy]);
                else{
                    if(idx+2 < n) ans = max(next_of_next[1]+prices[idx], next[buy]);
                    else ans = max(prices[idx], next[buy]);
                }
                cur[buy] = ans;
            }
            next_of_next = next;
            next = cur;
        }
        return next[1];
    }
};
/*
Time complexity: O(N*3), where N is the number of elements present in the prices array given.
Space complexity: O(3)
*/