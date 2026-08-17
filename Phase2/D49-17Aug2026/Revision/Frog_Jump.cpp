/*
Frog Jump
Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the last stair.
From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs.
Determine the minimum total cost required for the frog to reach the last stair.

Example:
Input: heights[] = [20, 30, 40, 20]
Output: 20
Explanation: Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
jump from stair 0 to 1: cost = |30 - 20| = 10
jump from stair 1 to 3: cost = |20 - 30| = 10
Total Cost = 10 + 10 = 20
Input: heights[] = [30, 20, 50, 10, 40]
Output: 30
Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
jump from stair 0 to 2: cost = |50 - 30| = 20
jump from stair 2 to 4: cost = |40 - 50| = 10
Total Cost = 20 + 10 = 30
Constraints:

1 ≤ height.size() ≤ 105
0 ≤ height[i] ≤ 104
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(vector<int>& height, int idx, vector<int>& dp){
        if(idx == 0) return 0;
        if(idx < 0) return 1e8;
        if(dp[idx] != -1) return dp[idx];
        int one_step = 1e8, two_step = 1e8;
        if(idx-1 >= 0) one_step = solve(height, idx-1, dp)+abs(height[idx] - height[idx-1]);
        if(idx-2 >= 0) two_step = solve(height, idx-2, dp)+abs(height[idx] - height[idx-2]);
        int ans = min(one_step, two_step);
        dp[idx] = ans;
        return ans;
    }
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n+1, -1);
        return solve(height, n-1, dp);
    }
};

/*
Time complexity: O(N), where N is the number of elements present in the array.
Space complexity: O(N) for the DP, and O(N) auxiliary stack space.
*/

/*
Tabulation method
*/

class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n+1, 0);
        for(int idx=1; idx<n; idx++){
            int one_step = 1e8, two_step = 1e8;
            if(idx-1 >= 0) one_step = dp[idx-1]+abs(height[idx] - height[idx-1]);
            if(idx-2 >= 0) two_step = dp[idx-2]+abs(height[idx] - height[idx-2]);
            int ans = min(one_step, two_step);
            dp[idx] = ans;
        }
        return dp[n-1];
    }
};

/*
Time complexity: O(N), where N is the number of elements present in the array.
Space complexity: O(N) for the DP, here we are not using any extra auxiliary stack space.
*/

/*
Space optimization.
*/

class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        int prev1 = 0, prev2 = 0;
        for(int idx=1; idx<n; idx++){
            int one_step = 1e8, two_step = 1e8;
            if(idx-1 >= 0) one_step = prev1+abs(height[idx] - height[idx-1]);
            if(idx-2 >= 0) two_step = prev2+abs(height[idx] - height[idx-2]);
            int ans = min(one_step, two_step);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
};

/*
Time complexity: O(N), where N is the number of elements present in the array.
Space complexity: O(1) constant space, since we are using just variables.
*/
