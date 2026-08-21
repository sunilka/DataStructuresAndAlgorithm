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
    bool solve(vector<int>& nums, int& n, int target, int idx){
        if(target == 0) return true;
        if(idx >= n) return false;
        bool take = false;
        if(target - nums[idx] >=0) take = solve(nums, n, target - nums[idx], idx+1);
        bool notake = solve(nums, n, target, idx+1);
        bool ans = take || notake;
        return ans;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int tot_sum = accumulate(nums.begin(), nums.end(), 0);
        if(tot_sum % 2 != 0) return false;
        int target = tot_sum / 2;
        return solve(nums, n, target, 0);
    }
};

/*
Time complexity: 2^(N), where N is the number of elements present in the array.
Space complexity: O(N), where N is the number of elements present in the array.
*/


/*
Top down - memoization solution
*/
class Solution {
public:
    bool solve(vector<int>& nums, int& n, int target, int idx, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(idx >= n) return false;
        if(dp[idx][target]!=-1) return dp[idx][target];
        bool take = false;
        if(target - nums[idx] >=0) take = solve(nums, n, target - nums[idx], idx+1, dp);
        bool notake = solve(nums, n, target, idx+1, dp);
        bool ans = take || notake;
        dp[idx][target] = ans;
        return ans;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int tot_sum = accumulate(nums.begin(), nums.end(), 0);
        if(tot_sum % 2 != 0) return false;
        int target = tot_sum / 2;
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(nums, n, target, 0, dp);
    }
};

/*
Time complexity: O(N*(tot_sum/2)), where N is the total number of elements present in the array and tot_sum is the total sum 
of all the elements present in the array.
Space complexity: O(N*(tot_sum/2)) for the DP array and O(N) auxiliary stack space. 
*/

/*
Bottom up approach
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int tot_sum = accumulate(nums.begin(), nums.end(), 0);
        if(tot_sum % 2 != 0) return false;
        int t = tot_sum / 2;
        vector<vector<int>> dp(n+1, vector<int>(t+1, 0));
        for(int i=0; i<=n; i++) dp[i][0] = true;
        for(int idx=n-1; idx>=0; idx--){
            for(int target=1; target<=t; target++){
                bool take = false;  
                if(target - nums[idx] >=0) take = dp[idx+1][target - nums[idx]];
                bool notake = dp[idx+1][target];
                bool ans = take || notake;
                dp[idx][target] = ans;
            }
        }
        return dp[0][t];
    }
};

/*
Time complexity: O(N*(tot_sum/2)), where N is the total number of elements present in the array and tot_sum is the total sum 
of all the elements present in the array.
Space complexity: O(N*(tot_sum/2)) for the DP array. PLease note here that the auxiliary stack space is not used.
*/

/*
Space optimization.
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int tot_sum = accumulate(nums.begin(), nums.end(), 0);
        if(tot_sum % 2 != 0) return false;
        int t = tot_sum / 2;
        vector<int> cur(t+1, 0), next(t+1, 0);
        cur[0] = true;
        next[0] = true;
        for(int idx=n-1; idx>=0; idx--){
            for(int target=1; target<=t; target++){
                bool take = false;  
                if(target - nums[idx] >=0) take = next[target - nums[idx]];
                bool notake = next[target];
                bool ans = take || notake;
                cur[target] = ans;
            }
            next = cur;
        }
        return next[t];
    }
};

/*
Time complexity: O(N*(tot_sum/2)), where N is the total number of elements present in the array and tot_sum is the total sum 
of all the elements present in the array.
Space complexity: O(tot_sum/2) for the DP array. PLease note here that the auxiliary stack space is not used.
*/


