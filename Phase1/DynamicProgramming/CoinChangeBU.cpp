// https://leetcode.com/problems/climbing-stairs/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(amount + 1, 0));
        for(int i = 0; i <= n; i++){
            dp[i][amount] = 1;
        }
        for(int pos = n - 1; pos >= 0; pos--){
            for(int cur = amount; cur >= 0; cur--){
                long long take = 0;
                if(cur + coins[pos] <= amount){
                    take = dp[pos][cur + coins[pos]];
                }
                long long skip = dp[pos + 1][cur];
                dp[pos][cur] = take + skip;
            }
        }

        return (int)dp[0][0]; 
    }
};