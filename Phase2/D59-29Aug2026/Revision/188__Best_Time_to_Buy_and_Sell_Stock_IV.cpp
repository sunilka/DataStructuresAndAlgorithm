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
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> cur(k+1, vector<int>(3, 0)), next(k+1, vector<int>(3, 0));
        for(int idx=n-1; idx>=0; idx--){
            for(int nt=k-1; nt>=0; nt--){
                for(int buy_stock=0; buy_stock<=1; buy_stock++){
                    if(buy_stock) cur[nt][buy_stock] = max(next[nt][!buy_stock]-prices[idx], next[nt][buy_stock]);
                    else cur[nt][buy_stock] = max(next[nt+1][!buy_stock]+prices[idx], next[nt][buy_stock]);
                }
            }
            next = cur;
        }
        return next[0][1];
    }
};
/*
Time complexity:  O(N * k * 2), where N is the number of elements present in the prices array and k is the given 
transaction limit and 2 is for the buy or dont buy
Space complexity: O( (k+1)*3) = O(3k+1) = O(k) for the DP array and O(N) auxiliary stack space.
*/