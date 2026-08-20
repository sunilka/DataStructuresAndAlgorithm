/*
Subset Sum Problem
Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: There is no subset with target sum 30.
Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
Constraints:
1 ≤ arr.size() ≤ 200
1 ≤ arr[i] ≤ 200
1 ≤ sum ≤ 104
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool solve(vector<int>& arr, int n, int sum, int idx, vector<vector<int>>& dp){
        if(sum == 0) return true;
        if(idx >= n) return false;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        bool take = false;
        if(arr[idx] <= sum) take = solve(arr, n, sum-arr[idx], idx+1, dp);
        bool notake = solve(arr, n, sum, idx+1, dp);
        return dp[idx][sum] = (take || notake);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        int tot_sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum < 0 || sum > tot_sum) return false;
        vector<vector<int>> dp(n+1, vector<int>(tot_sum+1, -1));
        return solve(arr, n, sum, 0, dp);
    }
};

/*
Time complexity: O(N*sum), where N is the number of elements present in the array and sum is the total sum of all 
the elements present in the array.
Space complexity: O(N * tot_sum) for the DP matrix allocation + O(N) auxiliary call stack space.


NOTE:
Without memoization (plain recursion):
Time Complexity: O(2^N)
At every index, the algorithm makes up to 2 choices (either take the element or don't take it). This forms a decision tree of depth N with a total of 2 
N+1−1 recursive calls, making the time complexity exponential.
Space Complexity: O(N)
There is no DP table, so the space is solely determined by the maximum depth of the recursion call stack, which is N.
*/

/*
Bottom up - tabulation method
*/

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int tsum) {
        int n = arr.size();
        int tot_sum = accumulate(arr.begin(), arr.end(), 0);
        if (tsum < 0 || tsum > tot_sum) return false;
        vector<vector<int>> dp(n+1, vector<int>(tot_sum+1, 0));
        for(int i=0; i<=n; i++) dp[i][0] = true;
        for(int idx=n-1; idx>=0; idx--){
            for(int sum=1; sum<=tsum; sum++){
                bool take = false;
                if(arr[idx] <= sum) take = dp[idx+1][sum-arr[idx]];
                bool notake = dp[idx+1][sum];
                dp[idx][sum] = (take || notake);
            }
        }
        return dp[0][tsum];
    }
};

/*
Time complexity: O(N*sum), where N is the number of elements present in the array and sum is the total sum of all 
the elements present in the array.
Space complexity: O(N * tot_sum) for the DP matrix allocation and note that there is no auxiliary stack space here. 
*/

/*
Space optimization
*/

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int tsum) {
        int n = arr.size();
        int tot_sum = accumulate(arr.begin(), arr.end(), 0);
        if (tsum < 0 || tsum > tot_sum) return false;
        vector<int> cur(tot_sum+1, 0), next(tot_sum+1, 0);
        for(int idx=n-1; idx>=0; idx--){
            next[0] = true;
            for(int sum=1; sum<=tsum; sum++){
                bool take = false;
                if(arr[idx] <= sum) take = next[sum-arr[idx]];
                bool notake = next[sum];
                cur[sum] = (take || notake);
            }
            next = cur;
        }
        return next[tsum];
    }
};

/*
Time complexity: O(N*sum), where N is the number of elements present in the array and sum is the total sum of all 
the elements present in the array.
Space complexity: O(tot_sum) for the DP matrix allocation and note that there is no auxiliary stack space here. 
*/