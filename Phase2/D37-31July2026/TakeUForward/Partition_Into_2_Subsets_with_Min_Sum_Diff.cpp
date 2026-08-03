/*
Partition Into 2 Subsets with Min Sum Diff
Given an array arr[]  containing non-negative integers, the task is to divide it into two sets set1 and set2 such that the absolute difference between their sums is minimum and find the minimum difference.
Examples:

Input: arr[] = [1, 6, 11, 5]
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11 
Hence, minimum difference is 1.  
Input: arr[] = [1, 4]
Output: 3
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4
Hence, minimum difference is 3.
Input: arr[] = [1]
Output: 1
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {}, sum of Subset2 = 0
Hence, minimum difference is 1.
Constraints:
1 ≤ arr.size()*|sum of array elements| ≤ 105
1 <= arr[i] <= 105
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    int minDifference(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        
        vector<bool> next(sum + 1, false);
        vector<bool> cur(sum + 1, false);

        // Base case: csum == sum is achievable
        next[sum] = true;
        cur[sum] = true;
        
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int csum = sum - 1; csum >= 0; csum--) {
                bool take = false;
                if (csum + nums[idx] <= sum) {
                    take = next[csum + nums[idx]];
                }
                bool notake = next[csum];
                cur[csum] = (take || notake);
            }
            next = cur;
        }

        int mini = INT_MAX;
        
        for (int i = 0; i <= sum; i++) {
            if (next[i]) {
                int s1 = i;
                int s2 = sum - i;
                mini = min(mini, abs(s1 - s2));
            }
        }
        
        return mini;
    }
};

/* 
Time complexity: O(N*S)+O(S), where N is the number of elements present in the array and the S is the total sum of all the elements of the array.
Space complexity: O(S), S is the total sum of all the elements of the array.
*/