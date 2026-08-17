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
    int solve(vector<int>& nums, int n, int idx, vector<int>& dp){
        if(idx >= n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int notake = solve(nums, n, idx+1, dp);
        int take = solve(nums, n, idx+2, dp) + nums[idx];
        int ans = max(take, notake);
        dp[idx] = ans;
        return ans;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(nums, n, 0, dp);
    }
};

/*
Time complexity: O(N), where N is the number of elements present in the arrya, basically the number of houses present.
Space complexity: O(N) for the DP array and also we are going to use O(N) auxiliary stack space.
*/

/*
Bottom Up DP/ Tabulation method
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2, 0);
        for(int idx=n-1; idx>=0; idx--) dp[idx] = max(dp[idx+2] + nums[idx], dp[idx+1]);
        return dp[0];
    }
};

/*
Time complexity: O(N), where N is the number of elements present in the arrya, basically the number of houses present.
Space complexity: O(N) for the DP array and we are not going to use an auxiliary space over here since this is a iterative 
solution.
*/

/*
Space optimization solution.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), next1 = 0, next2 = 0;
        for(int idx=n-1; idx>=0; idx--){
            int ans = max(next2 + nums[idx], next1);
            next2 = next1;
            next1 = ans;
        }
        return next1;
    }
};
