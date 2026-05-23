// https://leetcode.com/problems/house-robber/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;       
        if (n == 1) return nums[0];  

        int prev1 = nums[0];
        int prev2 = 0;

        for(int i=1; i<nums.size(); i++){
            int take = nums[i];
            if(prev2 >= 0){
                take = take+prev2;
            }
            int no_take = prev1;
            int cur = max(take, no_take);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};

