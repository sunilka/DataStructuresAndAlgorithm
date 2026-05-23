// https://leetcode.com/problems/coin-change-ii/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    map<pair<int, int>, int> dp;
    int calc(int amount, vector<int>& coins, int pos, int cur_amount){
        if(dp.find({pos, cur_amount}) != dp.end()){
            return dp[{pos, cur_amount}];
        }
        if(cur_amount == amount){
            return 1;
        }

        else if(pos >= coins.size()){
            return 0;
        }
        
        else if(cur_amount > amount){
            return 0;
        }

        else{
            int ans= calc(amount, coins, pos, cur_amount + coins[pos]) + calc(amount, coins, pos+1, cur_amount);
            dp[{pos, cur_amount}] = ans;
            return ans;
        }
    }
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        return calc(amount, coins, 0, 0);
    }
};