/*
198. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    vector<int> dp;
    int calc(vector<int>& nums, int n, int idx){
        if(idx >= n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans = max(
            calc(nums, n, idx+2)+nums[idx],
            calc(nums, n, idx+1)
        );
        dp[idx] = ans;
        return ans;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1, -1);
        return calc(nums, n, 0);
    }
};

/*
Time complexity: O(N), where N is the size of the array.
Space complexity: O(N), where N is the size of the array.
*/


class Solution {
public: 
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[n] = 0;
        dp[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            int take = dp[i+2]+nums[i];
            int notake = dp[i+1];
            int ans = max(take, notake);
            dp[i] = ans;
        }
        return dp[0];
    }
};

/*
Time complexity: O(N), where N is the size of the array.
Space complexity: O(N), where N is the size of the array.
*/