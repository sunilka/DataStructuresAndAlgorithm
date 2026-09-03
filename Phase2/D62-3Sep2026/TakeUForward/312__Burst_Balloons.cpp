/*
312. Burst Balloons

You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10
 

Constraints:

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int i, int j){
        if(i+1>=j) return 0;
        int mini = INT_MIN;
        for(int k=i+1; k<j; k++){
            int ans = (nums[i] * nums[k] * nums[j]) + solve(nums, i, k) + solve(nums, k, j);
            mini = max(mini, ans);
        }
        return mini == INT_MIN ? 0: mini;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        return solve(nums, 0, n-1);
    }
};

/*
Time complexity: O(2^(2N)), where N is the number of elements present in the given nums array.
Space complexity: O(N) auxiliary stack space.
*/

/*
Top down memoization solution.
*/

class Solution {
public:
    int solve(vector<int>& nums, int i, int j, vector<vector<int>> &dp){
        if(i+1>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = INT_MIN;
        for(int k=i+1; k<j; k++){
            int ans = (nums[i] * nums[k] * nums[j]) + solve(nums, i, k, dp) + solve(nums, k, j, dp);
            mini = max(mini, ans);
        }
        return dp[i][j] = mini == INT_MIN ? 0: mini;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(nums, 0, n-1, dp);
    }
};

/*
Time complexity: O(N*N*N), where N is the number of elements present in the given nums array.
Space complexity: O(N*N) for the DP array and O(N) for the auxiliary stack space.
*/

/*
Bottom up tabulation method/
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(i+1>=j){
                    dp[i][j] = 0;
                    continue;
                }
                int mini = INT_MIN;
                for(int k=i+1; k<j; k++){
                    int ans = (nums[i] * nums[k] * nums[j]) + dp[i][k] + dp[k][j];
                    mini = max(mini, ans);
                }
                dp[i][j] = mini == INT_MIN ? 0: mini;
            }
        }
        return dp[0][n-1];
    }
};

/*
Time complexity: O(N*N*N), where N is the number of elements present in the given nums array.
Space complexity: O(N*N) for the DP array and please note that there is no auxiliary stack space involved here.
*/