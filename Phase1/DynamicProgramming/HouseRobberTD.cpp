// https://leetcode.com/problems/house-robber/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> dp;
    int calc(vector<int>& nums, int pos){
        if(dp.find(pos) != dp.end()){
            return dp[pos];
        }

        if(pos>=nums.size()){
            return 0;
        }

        else{
            int ans = max(
                calc(nums, pos+2)+nums[pos],
                calc(nums, pos+1)
            );
            dp[pos] = ans;
            return ans;
        }
    }
    int rob(vector<int>& nums) {
        return calc(nums, 0);
    }
};