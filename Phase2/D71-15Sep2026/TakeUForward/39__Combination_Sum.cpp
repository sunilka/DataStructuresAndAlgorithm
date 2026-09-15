/*
39. Combination Sum
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>& candidates, int &n, int idx, int target, vector<vector<int>>& ans, vector<int> cur){
        if(target == 0){
            ans.push_back(cur);
            return;
        }
        if(target < 0) return;
        if(idx>=n) return;
        solve(candidates, n, idx+1, target, ans, cur);
        if(target - candidates[idx] >= 0){
            cur.push_back(candidates[idx]);
            solve(candidates, n, idx, target-candidates[idx], ans, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n = candidates.size();
        solve(candidates, n, 0, target, ans, {});
        return ans;
    }
};

/*
Time complexity: O(2^T/M* T/M), where T is the target, M is the minium number that is present in the given array.
Since we can pick the same element at an idx again and again, the recusion stack is not constricted by the N value. 
Seconf T/M is becasue we are passing cur by value and not referenec, and in each recusion call the copy would be generated.
And the max element that can be present in the cur array is nothing but T/M.
Space compelxity: O(T/M) auxiliary stack space. 
*/