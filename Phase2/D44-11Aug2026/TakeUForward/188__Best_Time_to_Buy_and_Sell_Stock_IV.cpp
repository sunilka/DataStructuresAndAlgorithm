/*
188. Best Time to Buy and Sell Stock IV

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& prices, int n, int idx, bool buy, int nt, int k, vector<vector<vector<int>>>& dp){
        if(idx >= n) return 0;
        if(nt >= k) return 0;
        if(dp[idx][buy][nt]!=-1) return dp[idx][buy][nt];
        if(buy){
            int ans = max(
                solve(prices, n, idx+1, false, nt, k, dp)-prices[idx],
                solve(prices, n, idx+1, buy, nt, k, dp)
            );
            dp[idx][buy][nt] = ans;
            return ans;
        }
        else{
            int ans = max(
                solve(prices, n, idx+1, true, nt+1, k, dp)+prices[idx],
                solve(prices, n, idx+1, buy, nt, k, dp)
            );
            dp[idx][buy][nt] = ans;
            return ans;
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(k+1, -1)));
        return solve(prices, n, 0, true, 0, k, dp);
    }
};

/*
Time complexity: O(N*3*k), where N is the number of elements present in the array and k is the give k value.
Space complexity: O(N*3*k) + O(N+3+k)
*/

/*
Bottom up approach
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(k+1, 0)));
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                for(int nt=0; nt<k; nt++){
                    int ans;
                    if(buy) ans = max(dp[idx+1][0][nt]-prices[idx], dp[idx+1][buy][nt]);
                    else ans = max(dp[idx+1][1][nt+1]+prices[idx], dp[idx+1][buy][nt]);
                    dp[idx][buy][nt] = ans;
                }
            }
        }
        return dp[0][1][0];
    }
};

/*
Time complexity: O(N*3*k), where N is the number of elements present in the array and k is the give k value.
Space complexity: O(N*3*k)
*/

/*
Space optimization
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> cur(3, vector<int>(k+1, 0)), next(3, vector<int>(k+1, 0));
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                for(int nt=0; nt<k; nt++){
                    int ans;
                    if(buy) ans = max(next[0][nt]-prices[idx], next[buy][nt]);
                    else ans = max(next[1][nt+1]+prices[idx], next[buy][nt]);
                    cur[buy][nt] = ans;
                }
                next = cur;
            }
        }
        return next[1][0];
    }
};

/*
Time complexity: O(N*3*k), where N is the number of elements present in the array and k is the give k value.
Space complexity: O(3*k)
*/