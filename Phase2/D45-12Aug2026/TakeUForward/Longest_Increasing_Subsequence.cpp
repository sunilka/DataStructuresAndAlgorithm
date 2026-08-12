/*
Longest Increasing Subsequence
Given an array arr[] of non-negative integers, find the length of the Longest Strictly Increasing Subsequence (LIS). A subsequence is strictly increasing if each element in the subsequence is strictly less than the next element.

Examples:

Input: arr[] = [5, 8, 3, 7, 9, 1]
Output: 3
Explanation: The longest strictly increasing subsequence could be [5, 7, 9], which has a length of 3.
Input: arr[] = [10, 6, 3, 11, 7, 15]
Output: 3
Explanation: One of the possible longest strictly increasing subsequences is [10, 11, 15], which has a length of 3.
Input: arr[] = [3, 10, 2, 1, 20]
Output: 3
Explanation: The longest strictly increasing subsequence could be [3, 10, 20], which has a length of 3.
Constraints:

1 ≤ arr.size() ≤ 103
0 ≤ arr[i] ≤ 106
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& arr, int& n, int idx, int prev_idx, vector<vector<int>>& dp) {
        if (idx >= n) return 0;
        if (dp[idx][prev_idx + 1] != -1) return dp[idx][prev_idx + 1];
        int notTake = solve(arr, n, idx + 1, prev_idx, dp);
        int take = 0;
        if (prev_idx == -1 || arr[idx] > arr[prev_idx]) {
            take = 1 + solve(arr, n, idx + 1, idx, dp);
        }
        return dp[idx][prev_idx + 1] = max(take, notTake);
    }

    int lis(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(arr, n, 0, -1, dp);
    }
};

/*
Time complexity: O(N*N), where N is the number of elements present in the array.
Space complexity: O(N*N)+O(N+N) aux space
*/  

/*
Bottom up approach
*/

class Solution {
public:
    int lis(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int idx=n-1; idx>=0; idx--){
            for(int prev_idx=-1; prev_idx<n; prev_idx++){
                int notTake = dp[idx + 1][prev_idx+1];
                int take = 0;
                if (prev_idx == -1 || arr[idx] > arr[prev_idx]) {
                    take = 1 + dp[idx + 1][idx+1];
                }
                dp[idx][prev_idx + 1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};

/*
Time complexity: O(N*N), where N is the number of elements present in the array.
Space complexity: O(N*N)
*/  

/*
Space optimized version.
*/

class Solution {
public:
    int lis(vector<int>& arr) {
        int n = arr.size();
        vector<int> cur(n+1, 0), next(n+1, 0);
        for(int idx=n-1; idx>=0; idx--){
            for(int prev_idx=-1; prev_idx<n; prev_idx++){
                int notTake = next[prev_idx+1];
                int take = 0;
                if (prev_idx == -1 || arr[idx] > arr[prev_idx]) take = 1 + next[idx+1];
                cur[prev_idx + 1] = max(take, notTake);
            }
            next = cur;
        }
        return cur[0];
    }
};

/*
Time complexity: O(N*N), where N is the number of elements present in the array.
Space complexity: O(N)
*/  