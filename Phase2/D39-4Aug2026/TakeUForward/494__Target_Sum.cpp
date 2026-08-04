/*
494. Target Sum
You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:

Input: nums = [1], target = 1
Output: 1

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int target, int idx, int cans){
        int n = nums.size();
        if(idx >= n){
            if(cans == target) return 1;
            else return 0;
        }
        int add = solve(nums, target, idx+1, cans+nums[idx]);
        int sub = solve(nums, target, idx+1, cans-nums[idx]);
        int ans = add + sub;
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0, 0);
    }
};

/*
Time complexity: 2^N, where N is the number of elements present in the given array.
Space complexity: 2^N, where N is the number of elements present in the given array.
*/

class Solution {
public:
    int solve(vector<int>& nums, int target, int idx, int cans, int tot_sum, vector<vector<int>>& dp){
        int n = nums.size();
        if(idx >= n){
            if(cans == target) return 1;
            else return 0;
        }
        int shifted_sum = cans + tot_sum;
        if (shifted_sum < 0 || shifted_sum > 2 * tot_sum) return 0;
        if(dp[idx][shifted_sum]!=-1) return dp[idx][shifted_sum];
        int add = solve(nums, target, idx+1, cans+nums[idx], tot_sum, dp);
        int sub = solve(nums, target, idx+1, cans-nums[idx], tot_sum, dp);
        int ans = add + sub;
        dp[idx][shifted_sum] = ans;
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int tot_sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n+1, vector<int>((2*tot_sum)+1, -1));
        return solve(nums, target, 0, 0, tot_sum, dp);
    }
};

/*
Time complexity: O(N*(2*sum)), where N is the number of elements present in the array and sum is the sum of the elements
present in the array.
Space complexity: O(N*(2*sum))+O(N) aux space,  where N is the number of elements present in the array and sum is the sum of the elements
present in the array.
*/


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int tot_sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > tot_sum) return 0;
        vector<vector<int>> dp(n+1, vector<int>((2*tot_sum)+1, 0));
        dp[n][target+tot_sum] = 1;

        for(int idx=n-1; idx>=0; idx--){
            for(int cans=-tot_sum; cans<=tot_sum; cans++){
                int shifted_sum = cans + tot_sum;
                int add = 0, sub = 0;
                if (cans + nums[idx] <= tot_sum) {
                    add = dp[idx + 1][(cans + nums[idx]) + tot_sum];
                }
                if (cans - nums[idx] >= -tot_sum) {
                    sub = dp[idx + 1][(cans - nums[idx]) + tot_sum];
                }
                int ans = add + sub;
                dp[idx][shifted_sum] = ans;
            }
        }
        return dp[0][tot_sum];
    }
};

/*
Time complexity: O(N*(2*sum)), where N is the number of elements present in the array and sum is the sum of the elements
present in the array.
Space complexity: O(N*(2*sum)),  where N is the number of elements present in the array and sum is the sum of the elements
present in the array.
*/


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int tot_sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > tot_sum) return 0;
        vector<int> cur((2*tot_sum)+1, 0);
        vector<int> next((2*tot_sum)+1, 0);

        next[target+tot_sum] = 1;

        for(int idx=n-1; idx>=0; idx--){
            for(int cans=-tot_sum; cans<=tot_sum; cans++){
                int shifted_sum = cans + tot_sum;
                int add = 0, sub = 0;
                if (cans + nums[idx] <= tot_sum) {
                    add = next[(cans + nums[idx]) + tot_sum];
                }
                if (cans - nums[idx] >= -tot_sum) {
                    sub = next[(cans - nums[idx]) + tot_sum];
                }
                int ans = add + sub;
                cur[shifted_sum] = ans;
            }
            next = cur;
        }
        return next[tot_sum];
    }
};

/*

*/