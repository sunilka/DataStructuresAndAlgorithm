/*
213. House Robber II

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int start, int end, int idx, vector<int>& dp){
        if(idx > end) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take = solve(nums, start, end, idx+2, dp) + nums[idx];
        int notake = solve(nums, start, end, idx+1, dp);
        int ans = max(take, notake);
        dp[idx] = ans;
        return ans;
    }
    int rob(vector<int>& nums) {
        vector<int> dp1, dp2;
        int n = nums.size();
        dp1.resize(n, -1);
        dp2.resize(n, -1);
        if(n == 1) return nums[0];
        int ans1 = solve(nums, 0, n-2, 0, dp1);
        int ans2 = solve(nums, 1, n-1, 1, dp2);
        return max(ans1, ans2);
    }
};

/*
Time complexity: O(N), where N is the number of elements present in the array.
Space complexity: O(N), where N is the number of elements present in the array.
*/


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp1(n+2, 0);
        for(int i=n-2; i>=0; i--){
            int take = dp1[i+2] + nums[i];
            int notake = dp1[i+1];
            int ans = max(take, notake);
            dp1[i] = ans;
        }

        vector<int> dp2(n+2, 0);
        for(int i=n-1; i>=1; i--){
            int take = dp2[i+2] + nums[i];
            int notake = dp2[i+1];
            int ans = max(take, notake);
            dp2[i] = ans;
        }
        return max(dp1[0], dp2[1]);
    }
};

/*
Time complexity: O(N), where N is the number of elements present in the array.
Space complexity: O(N), where N is the number of elements present in the array.
*/