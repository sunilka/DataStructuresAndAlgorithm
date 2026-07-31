/*
416. Partition Equal Subset Sum
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(vector<int>& nums, int n, int idx, int target, int csum, vector<vector<int>>& dp) {
        if (csum == target) return true;
        if (idx >= n) return false;
        if (csum > target) return false;
        if(dp[idx][csum] != -1) return dp[idx][csum];
        bool take = solve(nums, n, idx + 1, target, csum + nums[idx], dp);
        bool notake = solve(nums, n, idx + 1, target, csum, dp);
        bool ans = take || notake;
        dp[idx][csum] = ans;
        return ans;
    }

    bool canPartition(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if (total_sum % 2 != 0) return false;
        int target = total_sum / 2;
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(nums, n, 0, target, 0, dp);
    }
};

/*
Time Complexity: O(N * T), where N is nums.size() and T is target (total_sum / 2).
Space Complexity: O(N * T) overall 
                 - O(N * T) for the DP table 
                 - O(N) auxiliary recursion stack space
*/

/* Bottom up DP*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if (total_sum % 2 != 0) return false;
        int target = total_sum / 2;
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
        for(int i=0; i<=n; i++) dp[i][target] = true;

        for(int idx=n-1; idx>=0; idx--){
            for(int csum=target-1; csum>=0; csum--){
                bool take = false;
                if(csum+nums[idx]<=target){
                    take = dp[idx+1][csum + nums[idx]];
                }
                bool notake = dp[idx+1][csum];
                bool ans = take || notake;
                dp[idx][csum] = ans;
            }
        }
        return dp[0][0];
    }
};

/*
Time Complexity: O(N * T), where N is nums.size() and T is target (total_sum / 2).
Space Complexity: O(N * T)
*/


/*
Space optimized.
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if (total_sum % 2 != 0) return false;
        int target = total_sum / 2;

        vector<bool> next(target+1, false), cur(target+1, false);
        next[target] = true;
        cur[target] = true;
        for(int idx=n-1; idx>=0; idx--){
            for(int csum=target-1; csum>=0; csum--){
                bool take = false;
                if(csum+nums[idx]<=target){
                    take = next[csum + nums[idx]];
                }
                bool notake = next[csum];
                bool ans = take || notake;
                cur[csum] = ans;
            }
            next = cur;
        }
        return cur[0];
    }
};

/*
Time Complexity: O(N * T), where N is nums.size() and T is target (total_sum / 2).
Space Complexity: O(T)
*/