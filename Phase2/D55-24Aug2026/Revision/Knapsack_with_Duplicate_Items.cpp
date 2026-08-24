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
    int solve(vector<int>& val, vector<int>& wt, int& n, int capacity, int idx){
        if(idx >= n) return 0;
        if(capacity == 0) return 0;
        int notake = solve(val, wt, n, capacity, idx+1);
        int take = 0;
        if(wt[idx] <= capacity){
            take = solve(val, wt, n, capacity-wt[idx], idx)+val[idx];
        }
        return max(take, notake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = wt.size();
        return solve(val, wt, n, capacity, 0);
    }
};

/*
Time complexity: O(2*(capacity+N), where wt is the wegiht array.
Space complexity:  O(capacity+N) auxiliary stack space.
*/

/*
Top down approach - memoization solution
*/

class Solution {
  public:
    int solve(vector<int>& val, vector<int>& wt, int& n, int capacity, int idx, vector<vector<int>>& dp){
        if(idx >= n) return 0;
        if(capacity == 0) return 0;
        if(dp[idx][capacity]!=-1) return dp[idx][capacity];
        int notake = solve(val, wt, n, capacity, idx+1, dp);
        int take = 0;
        if(wt[idx] <= capacity){
            take = solve(val, wt, n, capacity-wt[idx], idx, dp)+val[idx];
        }
        return dp[idx][capacity] = max(take, notake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = wt.size();
        vector<vector<int>> dp(n+1, vector<int>(capacity+1, -1));
        return solve(val, wt, n, capacity, 0, dp);
    }
};

/*
Time complexity: O(N*capacity) where is the N is the number of elements present to take. Capacity is the capacity of the knapsack.
Space complexity: O(N*capacity) for the DP array and O(N+capacity) auxiliary stack space.
*/

/*
Bottom up DP - memoization solution.
*/

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int c) {
        int n = wt.size();
        vector<vector<int>> dp(n+1, vector<int>(c+1, 0));
        for(int idx=n-1; idx>=0; idx--){
            for(int capacity=0; capacity<=c; capacity++){
                int notake = dp[idx+1][capacity];
                int take = 0;
                if(wt[idx] <= capacity){
                    take = dp[idx][capacity-wt[idx]]+val[idx];
                }
                dp[idx][capacity] = max(take, notake);
            }
        }
        return dp[0][c];
    }
}; 

/*
Time complexity: O(N*capacity) where is the N is the number of elements present to take. Capacity is the capacity of the knapsack.
Space complexity: O(N*capacity) for the DP array and there is no auxiliary stack space involved over here. 
*/


/*
Space optimization solution.
*/

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int c) {
        int n = wt.size();
        vector<int> cur(c+1, 0), next(c+1, 0);
        for(int idx=n-1; idx>=0; idx--){
            for(int capacity=0; capacity<=c; capacity++){
                int notake = next[capacity];
                int take = 0;
                if(wt[idx] <= capacity){
                    take = cur[capacity-wt[idx]]+val[idx];
                }
                cur[capacity] = max(take, notake);
            }
            next = cur;
        }
        return next[c];
    }
};

/*
Time complexity: O(N*capacity) where is the N is the number of elements present to take. Capacity is the capacity of the knapsack.
Space complexity: O(capacity) for the DP array and there is no auxiliary stack space involved over here. 
*/
