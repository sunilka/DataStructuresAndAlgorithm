/*
Subsets

Given an array arr[] of distinct positive integers, your task is to find all its subsets.
Note: You can return the subsets in any order, the driver code will print them in sorted order.
Examples:
Input: arr[] = [1, 2, 3]
Output: [[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]]
Explanation: 
The subsets of [1, 2, 3] in lexicographical order are:
[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]
Input: arr[] = [2, 4]
Output: [[], [2], [2, 4], [4]]
Explanation:
The subsets of [2, 4] in lexicographical order are:
[], [2], [2, 4], [4]
Constraints :
1 ≤ arr.size() ≤ 10
1 ≤ arr[i] ≤ 103
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
        solve(arr, n, idx+1, cans, ans);
        cans.push_back(arr[idx]);
        solve(arr, n, idx+1, cans, ans);
        cans.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> cans;
        int n = arr.size();
        solve(arr, n, 0, cans, ans);
        return ans;
    }
};

/*
Time complexity: O(2^(N)*N), where N is the number of elements present in the given array. Here the extra N time is consumed for
the cans to be copied into the ans array.
Space complexity: O(2^N * N) we are using O(2^N) for the output array and O(N) auxiliary stack space is used here because 
of the recursion. 
*/