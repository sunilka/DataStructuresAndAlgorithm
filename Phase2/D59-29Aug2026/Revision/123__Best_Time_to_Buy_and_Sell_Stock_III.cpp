/*
123. Best Time to Buy and Sell Stock III

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& prices, int &n, int& k,int idx, int nt, bool buy_stock){
        if(idx >= n) return 0;
        if(nt>=2) return 0;
        if(buy_stock){
            int ans = max(
                solve(prices, n, k, idx+1, nt, !buy_stock)-prices[idx],
                solve(prices, n, k, idx+1, nt, buy_stock)
            );
            return ans;
        }
        else{
            int ans = max(
                solve(prices, n, k, idx+1, nt+1, !buy_stock)+prices[idx],
                solve(prices, n, k, idx+1, nt, buy_stock)
            );
            return ans;
        }

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), k=2;
        return solve(prices, n, k, 0, 0, true);
    }
};

/*
Time complexity: O(2^(N)), where N is the number of elements in the given prices array.
Space complexity: O(N+1) auxiliary stack space.
*/

/*
Top down memoization DP.
*/

class Solution {
public:
    int solve(vector<int>& prices, int &n, int& k,int idx, int nt, bool buy_stock, vector<vector<vector<int>>>& dp){
        if(idx >= n) return 0;
        if(nt>=2) return 0;
        if(dp[idx][nt][buy_stock]!=-1) return dp[idx][nt][buy_stock];
        if(buy_stock){
            int ans = max(
                solve(prices, n, k, idx+1, nt, !buy_stock, dp)-prices[idx],
                solve(prices, n, k, idx+1, nt, buy_stock, dp)
            );
            return dp[idx][nt][buy_stock] = ans;
        }
        else{
            int ans = max(
                solve(prices, n, k, idx+1, nt+1, !buy_stock, dp)+prices[idx],
                solve(prices, n, k, idx+1, nt, buy_stock, dp)
            );
            return dp[idx][nt][buy_stock] = ans;
        }

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), k=2;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(3, -1)));
        return solve(prices, n, k, 0, 0, true, dp);
    }
};

/*
Time complexity:  O(N * 2 * 2) = O(4N)-> N indices * 2 transaction states (0,1) * 2 buy states (0,1)
Space complexity: O((N + 1) * 3 * 3) = O(9N + 9) for the allocated DP array O(N + 1) for the auxiliary stack space
*/

/*
Bottom up tabulation method.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), k=2;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(3, 0)));
        for(int idx=n-1; idx>=0; idx--){
            for(int nt=k-1; nt>=0; nt--){
                for(int buy_stock=0; buy_stock<=1; buy_stock++){
                    if(buy_stock) dp[idx][nt][buy_stock] = max(dp[idx+1][nt][!buy_stock]-prices[idx], dp[idx+1][nt][buy_stock]);
                    else dp[idx][nt][buy_stock] = max(dp[idx+1][nt+1][!buy_stock]+prices[idx], dp[idx+1][nt][buy_stock]);
                }
            }
        }
        return dp[0][0][1];
    }
};

/*
Time complexity:  O(N * 2 * 2) = O(4N)-> N indices * 2 transaction states (0,1) * 2 buy states (0,1)
Space complexity: O((N + 1) * 3 * 3) = O(9N + 9) for the allocated DP array and we are not using any extra auxiliary 
stack space here. 
*/

/*
Space optimization
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), k=2;
        vector<vector<int>> cur(k+1, vector<int>(3, 0)), next(k+1, vector<int>(3, 0));
        for(int idx=n-1; idx>=0; idx--){
            for(int nt=k-1; nt>=0; nt--){
                for(int buy_stock=0; buy_stock<=1; buy_stock++){
                    if(buy_stock) cur[nt][buy_stock] = max(next[nt][!buy_stock]-prices[idx], next[nt][buy_stock]);
                    else cur[nt][buy_stock] = max(next[nt+1][!buy_stock]+prices[idx], next[nt][buy_stock]);
                }
                next = cur;
            }
        }
        return next[0][1];
    }
};


/*
Time complexity:  O(N * 2 * 2) = O(4N)-> N indices * 2 transaction states (0,1) * 2 buy states (0,1)
Space complexity: O((3 * 3) = O(9) = O(1) for the allocated DP array and we are not using any extra auxiliary 
stack space here. 
*/