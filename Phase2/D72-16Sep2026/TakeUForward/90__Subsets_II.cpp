/*
90. Subsets II
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>& arr, int& n, int idx, vector<int>& cans, vector<vector<int>>& ans){
        if(idx == n){
            ans.push_back(cans);
            return;
        }
        cans.push_back(arr[idx]);
        solve(arr, n, idx+1, cans, ans);
        cans.pop_back();
        while(idx + 1 < n && arr[idx] == arr[idx + 1]) idx++;
        solve(arr, n, idx+1, cans, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> cans;
        solve(nums, n, 0, cans, ans);
        return ans;
    }
};

/*
Time complexity: O(2^(N)*N), where N is the number of elements present in the given array. Here the extra N time is consumed for
the cans to be copied into the ans array.
Space complexity: O(2^N * N) we are using O(2^N) for the output array and O(N) auxiliary stack space is used here because 
of the recursion. 
*/