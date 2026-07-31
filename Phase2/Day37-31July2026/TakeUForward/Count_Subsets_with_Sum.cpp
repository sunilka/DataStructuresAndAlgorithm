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
    int solve(vector<int>& arr, int n, int target, int idx,  int csum){
        if(idx >= n){
            if(csum == target) return 1;
            return 0;
        }
        if(csum > target) return 0;
        
        int take = solve(arr, n, target, idx+1, csum+arr[idx]);
        int notake = solve(arr, n, target, idx+1, csum);
        int ans = take + notake;
        return ans;
    }
    int perfectSum(vector<int>& arr, int target) {
        return solve(arr, arr.size(), target, 0, 0);
    }
};

/*
Time complexity: O(2^(N)), where N is the number of elements present in the array.
Space complexxity: Auxiliary stack space of O(N) is used.
*/


/*
Top down DP.
*/
class Solution {
  public:
    int solve(vector<int>& arr, int n, int target, int idx, int csum, vector<vector<int>>& dp){
        if(idx >= n){
            if(csum == target) return 1;
            return 0;
        }
        if(dp[idx][csum] != -1) return dp[idx][csum];
        
        int take = 0;
        if(csum + arr[idx] <= target){
            take = solve(arr, n, target, idx+1, csum+arr[idx], dp);
        }
        int notake = solve(arr, n, target, idx+1, csum, dp);
        int ans = take + notake;
        dp[idx][csum] = ans;
        return ans;
    }
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(arr, n, target, 0, 0, dp);
    }
};

/*
Time complexity: O(N*T), where N is the number of elements present in the array and T is the target sum.
Space complexity: O(N*T) for DP table and O(N) auxillary space, where N is the number of elements present in the array and T is the target sum.
*/

/*
Bottom up approach.
*/
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[n][target] = 1;
        
        for(int idx=n-1; idx>=0; idx--){
            for(int csum=target; csum>=0; csum--){
                int take = 0;
                if(csum + arr[idx] <= target){
                    take = dp[idx+1][csum+arr[idx]];
                }
                int notake = dp[idx+1][csum];
                int ans = take + notake;
                dp[idx][csum] = ans;
            }
        }
        return dp[0][0];
    }
};

/*
Time complexity: O(N*T), where N is the number of elements present in the array and T is the target sum.
Space complexity: O(N*T) for DP table, where N is the number of elements present in the array and T is the target sum.
*/

/*
Space optimized
*/

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> cur(target+1, 0), next(target+1, 0);
        next[target] = 1;
        
        for(int idx=n-1; idx>=0; idx--){
            for(int csum=target; csum>=0; csum--){
                int take = 0;
                if(csum + arr[idx] <= target){
                    take = next[csum+arr[idx]];
                }
                int notake = next[csum];
                int ans = take + notake;
                cur[csum] = ans;
            }
            next = cur;
        }
        return next[0];
    }
};

/*
Time complexity: O(N*T), where N is the number of elements present in the array and T is the target sum.
Space complexity: O(T) for DP table, where T is the target sum.
*/