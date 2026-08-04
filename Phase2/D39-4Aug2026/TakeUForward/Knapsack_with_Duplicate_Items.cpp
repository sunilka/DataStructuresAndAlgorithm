/*
Knapsack with Duplicate Items

Given a set of items, each with a weight and a value, represented by the array wt[] and val[] respectively. Also, a knapsack with a weight limit capacity.
Your task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.

Note: Each item can be taken any number of times.
Examples:

Input: val[] = [1, 1], wt[] = [2, 1], capacity = 3
Output: 3
Explanation: The optimal choice is to pick the 2nd element 3 times.
Input: val[] = [10, 40, 50, 70], wt[] = [1, 3, 4, 5], capacity = 8
Output: 110
Explanation: The optimal choice is to pick the 2nd element and the 4th element.
Input: val[] = [6, 8, 7, 100], wt[] = [2, 3, 4, 5], capacity = 1
Output: 0
Explanation: We can't pick any element. Hence, total profit is 0.
Constraints:
1 ≤ val.size() = wt.size() ≤ 1000
1 ≤ capacity ≤ 1000
1 ≤ val[i], wt[i] ≤ 100

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(vector<int>& val, vector<int>& wt, int n, int capacity, int idx, vector<vector<int>>& dp){
        if(capacity == 0) return 0;
        if(idx >= n) return 0;
        if(dp[idx][capacity]!=-1) return dp[idx][capacity];
        int take = 0;
        if(capacity >= wt[idx]){
            take += solve(val, wt, n, capacity-wt[idx], idx, dp) + val[idx];
        }
        int notake = solve(val, wt, n, capacity, idx+1, dp);
        return dp[idx][capacity] = max(take, notake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n+1, vector<int>(capacity+1, -1));
        return solve(val, wt, n, capacity, 0, dp);
    }
};

/*
Time complexity: O(N*C), where N is the number of elements present in the array and C is the capacity provided.
Space complexity; O(N*C)+(N+C) aux space.
*/

/* 
Bottom up approach.
*/

class Solution {
public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        if (capacity == 0) return 0;
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int c = 1; c <= capacity; c++) {
                int take = 0;
                if (c >= wt[idx]) {
                    take = dp[idx][c - wt[idx]] + val[idx];
                }
                int notake = dp[idx + 1][c];
                
                dp[idx][c] = max(take, notake);
            }
        }
        
        return dp[0][capacity];
    }
};

/*
Time complexity: O(N*C), where N is the number of elements present in the array and C is the capacity provided.
Space complexity; O(N*C).
*/

/*
Space optimized
*/

class Solution {
public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        if (capacity == 0) return 0;
        int n = val.size();
        vector<int> cur(capacity + 1, 0);
        vector<int> next(capacity + 1, 0);
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int c = 1; c <= capacity; c++) {
                int take = 0;
                if (c >= wt[idx]) {
                    take = cur[c - wt[idx]] + val[idx];
                }
                int notake = next[c];
                cur[c] = max(take, notake);
            }
            next = cur;
        }
        
        return next[capacity];
    }
};

/*
Time complexity: O(N*C), where N is the number of elements present in the array and C is the capacity provided.
Space complexity; O(C).
*/