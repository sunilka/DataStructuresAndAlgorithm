/*

121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
 

*/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int psms = prices[prices.size()-1], ans = 0, n = prices.size();
    for(int i=n-2; i>=0; i--){
        ans = max(ans, psms - prices[i]);
        psms = max(prices[i], psms);
    }
    return ans;
}

int main(){
    vector<int> prices = {7,6,4,3,1};
    int ans = maxProfit(prices);
    cout<<"Printing the max profit that can be earned here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(N) where N is the number of elements present in the array.
Space complexity: O(1), we do not use any extra space, hence the space complexity is constant.

*/