/*
Count Subsets with Sum
Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.
Examples:

Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
Output: 3
Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.
Input: arr[] = [2, 5, 1, 4, 3], target = 10
Output: 3
Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.
Input: arr[] = [5, 7, 8], target = 3
Output: 0
Explanation: There are no subsets of the array that sum up to the target 3.
Input: arr[] = [35, 2, 8, 22], target = 0
Output: 1
Explanation: The empty subset is the only subset with a sum of 0.
Constraints:
1 ≤ arr.size() ≤ 103
0 ≤ arr[i] ≤ 103
0 ≤ target ≤ 103
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(vector<int>& arr, int &n, int target, int idx){
        if(idx >= n){
            if(target == 0) return 1;
            return 0;
        }
        int notake = solve(arr, n, target, idx+1);
        int take = 0;
        if(target - arr[idx] >=0) take = solve(arr, n, target-arr[idx], idx+1);
        return notake + take;
    }
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        return solve(arr, n, target, 0);
        
    }
};

/*
Time complexity: O(2^N), where N is the number of elements present in the array.
Space complexity: O(N) auxiliary stack space
*/

/*
Top down memoization solution.
*/

class Solution {
  public:
    int solve(vector<int>& arr, int &n, int target, int idx, vector<vector<int>>& dp){
        if(idx >= n){
            if(target == 0) return 1;
            return 0;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int notake = solve(arr, n, target, idx+1, dp);
        int take = 0;
        if(target - arr[idx] >=0) take = solve(arr, n, target-arr[idx], idx+1, dp);
        return dp[idx][target]=(take+notake);
    }
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        int tot_sum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(n+1, vector<int>(tot_sum+1, -1));
        return solve(arr, n, target, 0, dp);
    }
};

/*
Time complexity: O(N*tot_sum), where N is the number of elements present in the array.
Space complexity: O(N*tot_sum) for DP array and O(N) auxiliary stack space. 
*/

/*
Bottom up approach - tabulation method
*/
class Solution {
  public:
    int perfectSum(vector<int>& arr, int t) {
        int n = arr.size(), tot_sum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(n+1, vector<int>(tot_sum+1, 0));
        dp[n][0] = 1;
        for(int idx=n-1; idx>=0; idx--){
            for(int target=0; target<=t; target++){
                int notake = dp[idx+1][target];
                int take = 0;
                if(target - arr[idx] >=0) take = dp[idx+1][target-arr[idx]];
                dp[idx][target]=(take+notake);
            }
        }
        return dp[0][t];
    }
};

/*
Time complexity: O(N*tot_sum), where N is the number of elements present in the array.
Space complexity: O(N*tot_sum) for DP array, please note that we do not have any auxiliary stack space here.
*/


/*
Space optimization.
*/

class Solution {
  public:
    int perfectSum(vector<int>& arr, int t) {
        int n = arr.size(), tot_sum = accumulate(arr.begin(), arr.end(), 0);
        vector<int> cur(tot_sum+1, 0), next(tot_sum+1, 0);
        next[0] = 1;
        for(int idx=n-1; idx>=0; idx--){
            for(int target=0; target<=t; target++){
                int notake = next[target];
                int take = 0;
                if(target - arr[idx] >=0) take = next[target-arr[idx]];
                cur[target]=(take+notake);
            }
            next = cur;
        }
        return next[t];
    }
};

/*
Time complexity: O(N*tot_sum), where N is the number of elements present in the array.
Space complexity: O(tot_sum) for DP array, please note that we do not have any auxiliary stack space here.
*/