/*
122. Best Time to Buy and Sell Stock II

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

Find and return the maximum profit you can achieve.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& prices, int n, int idx, bool buy, vector<vector<int>>& dp){
        if(idx >= n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
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
                solve(prices, n, idx+1, true, dp)+prices[idx],
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
Time complexity: O(N*3), where N is the number of elements present in the array.
Space complexity: O(N*3)+O(N) aux space, where N is the numbe of elements present in the array.
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
                else ans = max(dp[idx+1][1]+prices[idx], dp[idx+1][buy]);
                dp[idx][buy] = ans;
            }
        }
        return dp[0][1];
    }
};

/*
Time complexity: O(N*3), where N is the number of elements present in the array.
Space complexity: O(N*3) aux space, where N is the numbe of elements present in the array.
*/

/*
Space optimization
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> cur(3, 0), next(3, 0);
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                int ans;
                if(buy) ans = max(next[0]-prices[idx], next[buy]);
                else ans = max(next[1]+prices[idx], next[buy]);
                cur[buy] = ans;
            }   
            next = cur;
        }
        return next[1];
    }
};

/*
Time complexity: O(N*3), where N is the number of elements present in the array.
Space complexity: O(3) aux space, where N is the numbe of elements present in the array.
*/