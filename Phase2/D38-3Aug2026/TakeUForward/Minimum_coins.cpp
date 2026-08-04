/*
322. Coin Change

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        reverse(coins.begin(), coins.end());
        vector<int> dp(amount+1, 1e9);
        dp[amount]=0;
        for(int cur_amount=amount-1; cur_amount>=0; cur_amount--){
            int ans = 1e9;
            for(int i=0; i<coins.size(); i++){
                if((long long)cur_amount + (long long)coins[i] <= (long long)amount){
                    int tans = dp[cur_amount+coins[i]];
                    if(tans!=1e9) ans = min(ans, tans+1);
                }
            }
            dp[cur_amount] = ans;
        }
        if(dp[0] == 1e9) return -1;
        return dp[0];
    }
};

/*
Time complexity: O(A*S), where A is the target amount and the S is the number of elements present in the array.
Space complexity: O(A*S), where A is the target amount and the S is the number of elements present in the array.
*/