/*
40. Combination Sum II
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void solve(vector<int>& candidates, int &n, int idx, int target, vector<vector<int>>& ans, vector<int>& cur){
        if(target == 0){
            ans.push_back(cur);
            return;
        }
        if(target < 0 || idx >= n) return;
        cur.push_back(candidates[idx]);
        solve(candidates, n, idx + 1, target - candidates[idx], ans, cur);
        cur.pop_back();
        while(idx + 1 < n && candidates[idx] == candidates[idx + 1]) idx++;
        solve(candidates, n, idx + 1, target, ans, cur);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        solve(candidates, n, 0, target, ans, cur);
        return ans;
    }
};


/*
Time complexity: O(2^N * N), where N is the number of elements present in the given array.
Space complexity: O(N) auxiliary stack space for the recusion
*/