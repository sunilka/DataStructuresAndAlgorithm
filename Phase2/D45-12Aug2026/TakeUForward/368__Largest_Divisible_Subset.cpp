/*
368. Largest Divisible Subset
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int prev_idx = -1; prev_idx < n; prev_idx++) {
                int notake = dp[idx + 1][prev_idx + 1];
                int take = 0;
                if (prev_idx == -1 || nums[idx] % nums[prev_idx] == 0) {
                    take = dp[idx + 1][idx + 1] + 1;
                }
                dp[idx][prev_idx + 1] = max(take, notake);
            }
        }
        vector<int> result;
        int idx = 0, prev_idx = -1;
        while(idx<n){
            bool cantake=false;
            if(prev_idx == -1 || nums[idx] % nums[prev_idx] == 0) cantake = true;
            if(cantake && dp[idx][prev_idx + 1] == dp[idx + 1][idx + 1] + 1){
                result.push_back(nums[idx]);
                prev_idx = idx;
            }
            idx++;
        }
        return result;

    }
};

/*
Time complexity: O(N*N), where N is the number of elements present in the array. 
Space complexity: O(N*N), where N is the number of elements present in the array. 
*/