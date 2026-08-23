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
    int solve(vector<int>& nums, int& n, int& target, int cur_sum, int idx){
        if(idx == n){
            if(cur_sum == target) return 1;
            return 0;
        }
        int positive = solve(nums, n, target, cur_sum+nums[idx], idx+1);
        int negative = solve(nums, n, target, cur_sum-nums[idx], idx+1);
        return positive + negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums, n, target, 0, 0);
    }
};

/*
Time complexity: O(2^(N)), where N is the number of elements present in the array.
Space complexity: O(N) auxiliary stack space.
*/

/*
Top down memoization approach.
*/

class Solution {
public:
    int solve(vector<int>& nums, int& n, int &tot_sum, int& target, int cur_sum, int idx, vector<vector<int>>& dp){
        if(idx == n){
            if(cur_sum == target) return 1;
            return 0;
        }
        int offset = cur_sum + tot_sum;
        if(dp[idx][offset]!=-1) return dp[idx][offset];
        int positive = solve(nums, n, tot_sum, target, cur_sum+nums[idx], idx+1, dp);
        int negative = solve(nums, n, tot_sum, target, cur_sum-nums[idx], idx+1, dp);
        return dp[idx][offset] = positive + negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int tot_sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n+1, vector<int>( (tot_sum*2)+1 , -1));
        return solve(nums, n, tot_sum, target, 0, 0, dp);
    }
};

/*
Time complexity: O(N*(tot_sum*2)), where N is the number of elements present in the array and tot_sum is the total sum of all 
the elements present in the array.
Space complexity: O(N*(tot_sum*2)) for the DP array and O(N) for the auxiliary stack space. 
*/

/*
Bottom up - tabulation method.
*/

class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int t) {
        int n = nums.size();
        int tot_sum = accumulate(nums.begin(), nums.end(), 0);
        int total_cols = 2 * tot_sum + 1;
        vector<vector<int>> dp(n+1, vector<int>(total_cols , 0));
        dp[n][t+tot_sum] = 1;
        for(int idx = n-1; idx>=0; idx--){
            for(int cur_sum=-tot_sum; cur_sum<=tot_sum; cur_sum++){
                int offset = cur_sum + tot_sum;
                int positive = 0, negative = 0;
                if (cur_sum + nums[idx] <= tot_sum) {
                    positive = dp[idx + 1][(cur_sum + nums[idx]) + tot_sum];
                }
                if (cur_sum - nums[idx] >= -tot_sum) {
                    negative = dp[idx + 1][(cur_sum - nums[idx]) + tot_sum];
                }
                dp[idx][offset] = positive + negative;
            }
        }
        return dp[0][0+tot_sum];
    }
};

/*
Time complexity: O(N*(tot_sum*2)), where N is the number of elements present in the array and tot_sum is the total sum of all 
the elements present in the array.
Space complexity: O(N*(tot_sum*2)) for the DP array, please note here that we are not using any exta auxiliary stack space.
*/

/*
Space optmization
*/
class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int t) {
        int n = nums.size();
        int tot_sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(t) > tot_sum) return 0;
        int total_cols = 2 * tot_sum + 1;
        vector<int> cur(total_cols+1, 0), next(total_cols+1, 0);
        next[t+tot_sum] = 1;
        for(int idx = n-1; idx>=0; idx--){
            for(int cur_sum=-tot_sum; cur_sum<=tot_sum; cur_sum++){
                int offset = cur_sum + tot_sum, positive = 0, negative = 0;
                if (cur_sum + nums[idx] <= tot_sum) positive = next[(cur_sum + nums[idx]) + tot_sum];
                if (cur_sum - nums[idx] >= -tot_sum) negative = next[(cur_sum - nums[idx]) + tot_sum];
                cur[offset] = positive + negative;
            }
            next = cur;
        }
        return next[0+tot_sum];
    }
};

/*
Time complexity: O(N*(tot_sum*2)), where N is the number of elements present in the array and tot_sum is the total sum of all 
the elements present in the array.
Space complexity: O((tot_sum*2)) for the DP array, please note here that we are not using any exta auxiliary stack space.
*/