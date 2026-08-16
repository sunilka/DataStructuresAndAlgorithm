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
private:
    int solve(vector<int>& arr, int n, int k, int start, vector<int>& dp) {
        if (start == n) return 0;
        if (dp[start] != -1) return dp[start];
        int maxi = 0;
        int currMax = 0;
        for (int end = start; end < start + k && end < n; end++) {
            currMax = max(currMax, arr[end]);
            int len = end - start + 1;
            int sum = (currMax * len) + solve(arr, n, k, end + 1, dp);
            maxi = max(maxi, sum);
        }

        return dp[start] = maxi;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, n, k, 0, dp);
    }
};

/*
Time Complexity: O(N⋅K)
Space Complexity: O(N)
*/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0); // dp[i] stores max sum for subarray starting at index i

        for (int start = n - 1; start >= 0; start--) {
            int maxi = 0;
            int currMax = 0;
            for (int end = start; end < start + k && end < n; end++) {
                currMax = max(currMax, arr[end]);
                int len = end - start + 1;
                int sum = (currMax * len) + dp[end + 1];
                maxi = max(maxi, sum);
            }
            dp[start] = maxi;
        }

        return dp[0];
    }
};

/*
Time Complexity: O(N⋅K)
Space Complexity: O(N)
*/