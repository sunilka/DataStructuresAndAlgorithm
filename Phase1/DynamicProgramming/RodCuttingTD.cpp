// https://www.geeksforgeeks.org/problems/rod-cutting0840

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    unordered_map<int, int> dp;
    int calc(vector<int> &price, int remaining_rod_length){
        if(dp.find(remaining_rod_length) != dp.end()){
            return dp[remaining_rod_length];
        }
        
        if(remaining_rod_length == 0){
            return 0;
        }
        
        else if(remaining_rod_length < 0){
            return INT_MIN;
        }
        
        else{
            int ans = INT_MIN;
            for(int i=0; i<remaining_rod_length; i++){
                int cur_ans = calc(price, remaining_rod_length - (i+1)) + price[i];
                ans = max(ans, cur_ans);
            }
            dp[remaining_rod_length] = ans;
            return ans;
        }
        
    }
    int cutRod(vector<int> &price) {
        return calc(price, price.size());
    }
};