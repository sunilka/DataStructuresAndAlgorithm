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
    int solve(vector<int>& prices, int& n, int idx, bool buy){
        if(idx >= n) return 0;
        if(buy){
            int ans = max(
                solve(prices, n, idx+1, !buy)-prices[idx],
                solve(prices, n, idx+1, buy)
            );
            return ans;
        }
        else{
            int ans = max(
                solve(prices, n, idx+2, !buy)+prices[idx],
                solve(prices, n, idx+1, buy)
            );
            return ans;
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(prices, n, 0, true);
    }
};

/*
Time complexity: O(2^(N)), where N is the number of elements present in the prices array.
Space complexity: O(N), where N is the auxiliary stack space.
*/

/*
Top down memoization DP.
*/

class Solution {
public:
    int solve(vector<int>& prices, int& n, int idx, bool buy, vector<vector<int>>& dp){
        if(idx >= n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            int ans = max(
                solve(prices, n, idx+1, !buy, dp)-prices[idx],
                solve(prices, n, idx+1, buy, dp)
            );
            return dp[idx][buy] = ans;
        }
        else{
            int ans = max(
                solve(prices, n, idx+2, !buy, dp)+prices[idx],
                solve(prices, n, idx+1, buy, dp)
            );
            return dp[idx][buy] = ans;
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        return solve(prices, n, 0, true, dp);
    }
};

/*
Time complexity: O( (N+1)*2) = O(2N+2) = O(N), where N is the number of elements present in the array.
Space complexity: O(N*3) for the DP array and O(N) auxiliary stack space.
*/

/*
Bottom up tabulation DP.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                if(buy) dp[idx][buy] = max(dp[idx+1][!buy]-prices[idx], dp[idx+1][buy]);
                else dp[idx][buy]= max(dp[idx+2][!buy]+prices[idx], dp[idx+1][buy]);
            }
        }
        return dp[0][true];
    }
};

/*
Time complexity: O(N*2), where N is the number of elements present in the given prices array.
Space complexity: O(N*2) for the DP array and we are not using any extra auxiliary stack space here.
*/

/*
Space optimization.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> cur(2, 0), next(2, 0), nextnext(2, 0);
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                if(buy) cur[buy] = max(next[!buy]-prices[idx], next[buy]);
                else cur[buy]= max(nextnext[!buy]+prices[idx], next[buy]);
            }
            nextnext = next;
            next = cur;
        }
        return next[true];
    }
};

/*
Time complexity: O(N*2), where N is the number of elements present in the given prices array.
Space complexity: O(2) for the DP arrays. And please not that we are not using an extra auxiliary
stack space here.
*/