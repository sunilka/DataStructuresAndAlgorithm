/*
123. Best Time to Buy and Sell Stock III
Solved
Hard

Topics
premium lock icon
Companies
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
    int solve(vector<int>& prices, int n, int idx, bool buy, int nt, vector<vector<vector<int>>>& dp){
        if(idx >= n) return 0;
        if(nt >= 2) return 0;
        if(dp[idx][buy][nt]!=-1) return dp[idx][buy][nt];
        if(buy){
            int ans = max(
                solve(prices, n, idx+1, false, nt, dp)-prices[idx],
                solve(prices, n, idx+1, buy, nt, dp)
            );
            dp[idx][buy][nt] = ans;
            return ans;
        }
        else{
            int ans = max(
                solve(prices, n, idx+1, true, nt+1, dp)+prices[idx],
                solve(prices, n, idx+1, buy, nt, dp)
            );
            dp[idx][buy][nt] = ans;
            return ans;
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(3, -1)));
        return solve(prices, n, 0, true, 0, dp);
    }
};

/*
Time complexity: O(N*3*3), where N is the number of elements present in the array.
Space complexity: O(N*3*3)+O(N+3+3) aux space, where N is the numbe of elements present in the array.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(3, 0)));
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                for(int nt=0; nt<=1; nt++){
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
Time complexity: O(N*3*3), where N is the number of elements present in the array.
Space complexity: O(N*3*3), where N is the numbe of elements present in the array.
*/

/*
Space optimized
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> cur(3, vector<int>(3, 0)), next(3, vector<int>(3, 0));
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                for(int nt=0; nt<=1; nt++){
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
Time complexity: O(N*3*3), where N is the number of elements present in the array.
Space complexity: O(3*3), where N is the numbe of elements present in the array.
*/