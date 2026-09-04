/*
1043. Partition Array for Maximum Sum
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1
 

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int _get_temp_ans(vector<int>& arr, int low, int high){
        int tans = 0, ne = high - low + 1, mv = 0;
        for(int i=low; i<=high; i++) mv = max(mv, arr[i]);
        return (mv*ne);
    }
    int solve(vector<int>& arr, int& n, int k, int i){
        if(i >= n) return 0;
        int maxi = 0;
        for(int cut=i; cut < min(n, i + k); cut++){
            int ans = _get_temp_ans(arr, i, cut) + solve(arr, n, k, cut+1);
            maxi = max(maxi, ans);
        }
        return maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        return solve(arr, n, k, 0);
    }
}; 

/*
Time complexity: O(K^N)
Space complexity: O(N)
*/

class Solution {
public:
    int solve(vector<int>& arr, int n, int k, int i, vector<int>& dp) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        int maxi = 0;
        int curr_max = 0;

        // Try partitions of length 1 up to k
        for (int cut = i; cut < min(n, i + k); cut++) {
            // O(1) running max calculation
            curr_max = max(curr_max, arr[cut]);
            int len = cut - i + 1;

            int ans = (curr_max * len) + solve(arr, n, k, cut + 1, dp);
            maxi = max(maxi, ans);
        }

        return dp[i] = maxi;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, n, k, 0, dp);
    }
};
