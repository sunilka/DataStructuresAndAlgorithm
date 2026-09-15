/*
Subsequence with Sum K
Given an array arr[] and target sum k, check if there exists a subsequence such that the sum of all elements in the subsequence equals to k.

Examples:

Input: arr = [10, 1, 2, 7, 6, 1, 5], k = 8.
Output: true
Explanation: Subsequences like [2, 6], [1, 7] sum upto 8
Input: arr = [2, 3, 5, 7, 9], k = 100. 
Output: false
Explanation: No subsequence can sum upto 10
Constraints:

1 ≤ k, arr.size() ≤ 2000
1 ≤ arr[i] ≤ 1000
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool solve(vector<int>& arr, int n, int k, int idx, int csum, vector<vector<int>>& dp) {
        if (csum == k) return true;
        if (csum > k) return false;
        if (idx == n) return false;
        if (dp[idx][csum] != -1) return dp[idx][csum];
        bool take = solve(arr, n, k, idx + 1, csum + arr[idx], dp);
        bool skip = solve(arr, n, k, idx + 1, csum, dp);
        return dp[idx][csum] = (take || skip);
    }

    bool checkSubsequenceSum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(arr, n, k, 0, 0, dp);
    }
};

/*
Time complexity: o(N*K), where N is the number of elements present in the given array and K is the given target.
Space complexity: O(N*K) for the DP array and O(N) auxiliary stack space.
*/


/*
Tabulation method.
*/

class Solution {
  public:
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        int n = arr.size();
        
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
        for (int i = 0; i <= n; i++) dp[i][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int target = 1; target <= k; target++) {
                bool skip = dp[i - 1][target];
                bool take = false;
                if (arr[i - 1] <= target) {
                    take = dp[i - 1][target - arr[i - 1]];
                }
                dp[i][target] = take || skip;
            }
        }

        return dp[n][k];
    }
};

/*
Time complexity: o(N*K), where N is the number of elements present in the given array and K is the given target.
Space complexity: O(N*K) for the DP array and please note that there is no auxiliary stack space used here. 
*/
