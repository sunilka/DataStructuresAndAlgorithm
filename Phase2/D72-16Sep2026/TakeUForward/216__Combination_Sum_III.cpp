/*
216. Combination Sum III

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.


Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
 

Constraints:

2 <= k <= 9
1 <= n <= 60
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, int& target, int k, int idx, vector<int>& cans, int csum, vector<vector<int>>& ans){
        if(k == 0){
            if(csum == target) ans.push_back(cans);
            return;
        }
        if(idx >= nums.size() || csum > target) return;
        solve(nums, target, k, idx+1, cans, csum, ans);
        cans.push_back(nums[idx]);
        solve(nums, target, k-1, idx+1, cans, csum+nums[idx], ans);
        cans.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums(9), cans;
        iota(nums.begin(), nums.end(), 1);
        vector<vector<int>> ans;
        solve(nums, n, k, 0, cans, 0, ans); 
        return ans;
    }
};

/*
Time Complexity: O(K * C(9, K))
- There are at most C(9, K) combinations generated from numbers 1-9.
- Copying a valid combination into ans takes O(K) time.
- Since N = 9 is fixed, this runs in O(1) time bounded by ~4608 operations max.

Space Complexity:
- Auxiliary Space: O(K) for recursion depth stack and temporary array cans.
- Output Space: O(K * C(9, K)) to store the resulting combinations.
*/