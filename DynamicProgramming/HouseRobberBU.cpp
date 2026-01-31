// https://leetcode.com/problems/house-robber/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;       
        if (n == 1) return nums[0];  
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        for(int i=1; i<nums.size(); i++){
            int take = nums[i];
            if(i-2 >= 0){
                take = take+dp[i-2];
            }
            int no_take = dp[i-1];
            dp[i] = max(take, no_take);
        }
        return dp[nums.size()-1];
    }
};

