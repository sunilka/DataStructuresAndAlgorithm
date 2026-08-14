/*
673. Number of Longest Increasing Subsequence
Solved
Medium

Topics
premium lock icon
Companies
Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
 

Constraints:

1 <= nums.length <= 2000
-106 <= nums[i] <= 106
The answer is guaranteed to fit inside a 32-bit integer.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxi = 1;
        vector<int> dp(n, 1), cnt(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i] && dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    cnt[i] = cnt[j];
                }
                else if(nums[j] < nums[i] && dp[i] == dp[j]+1){
                    cnt[i] = cnt[i] + cnt[j];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int countLIS = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi) {
                countLIS += cnt[i];
            }
        }
        return countLIS;
    }
};

/*
Time complexity: O(N^2)
Space complexity: O(N)
*/