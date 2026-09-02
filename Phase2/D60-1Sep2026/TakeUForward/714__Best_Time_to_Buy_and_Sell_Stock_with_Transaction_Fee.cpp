/*
714. Best Time to Buy and Sell Stock with Transaction Fee
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 

Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& prices, int& n, int& fee, int idx, bool buy, vector<vector<int>>& dp){
        if(idx >= n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            int ans = max(
                solve(prices, n, fee, idx+1, !buy, dp)-prices[idx],
                solve(prices, n, fee, idx+1, buy, dp)
            );
            return dp[idx][buy] = ans;
        }
        else{
            int ans = max(
                solve(prices, n, fee, idx+1, !buy, dp)+(prices[idx]-fee),
                solve(prices, n, fee, idx+1, buy, dp)
            );
            return dp[idx][buy] = ans;
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(prices, n, fee, 0, true, dp);
    }
};

/*
Time complexity: O(N*2), where N is the number of elements given in the prices array.
Space complexity: O(N*2) for the DP array and O(N) auxiliary stack space. 
*/

/*
Bottom up DP - tabulation method.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(3, 0));
        for(int idx=n-1; idx>=0; idx--){
            for(int buy_stock=0; buy_stock<=1; buy_stock++){
                if(buy_stock) dp[idx][buy_stock] = max(dp[idx+1][!buy_stock]-prices[idx], dp[idx+1][buy_stock]);
                else dp[idx][buy_stock] = max(dp[idx+1][!buy_stock]+prices[idx]-fee, dp[idx+1][buy_stock]);
            }
        }
        return dp[0][1];
    }
};

/*
Time complexity: O(N*2), where N is the number of elements given in the prices array.
Space complexity: O(N) for the DP array and please note here that we are not using auxiliary stack space.
*/

/*
Space optimization.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> cur(2, 0), next(2, 0);
        for(int idx=n-1; idx>=0; idx--){
            for(int buy_stock=0; buy_stock<=1; buy_stock++){
                if(buy_stock) cur[buy_stock] = max(next[!buy_stock]-prices[idx], next[buy_stock]);
                else cur[buy_stock] = max(next[!buy_stock]+prices[idx]-fee, next[buy_stock]);
            }
            next = cur;
        }
        return next[1];
    }
};

/*
Time complexity: O(N*2), where N is the number of elements given in the prices array.
Space complexity: O(2) for the DP arrays and please note here that we are not using auxiliary stack space.
*/