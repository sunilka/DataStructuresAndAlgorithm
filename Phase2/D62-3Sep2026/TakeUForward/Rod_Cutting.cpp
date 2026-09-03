/*
Rod Cutting
Given a rod of length n inches and an array price[], where price[i] denotes the value of a piece of length i (1-based Index). Determine the maximum value obtainable by cutting up the rod and selling the pieces.
Note: The value of n is equal to the size of price array.

Example:

Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
Output: 22
Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.
Input: price[] = [3, 5, 8, 9, 10, 17, 17, 20]
Output: 24
Explanation: The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1] = 8*3 = 24.
Input: price[] = [3]
Output: 3
Explanation: There is only 1 way to pick a piece of length 1.
Constraints:

1 ≤ price.size() ≤ 103
1 ≤ price[i] ≤ 106
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& cuts, int i, int j){
        if(i+1 >= j) return 0;
        int mini = INT_MAX;
        for(int k=i+1; k<j; k++){
            int ans = (cuts[j]-cuts[i]) + solve(cuts, i, k) + solve(cuts, k, j);
            mini = min(mini, ans);
        }
        return mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        int ans = solve(cuts, 0, m-1);
        return ans;
    }
};

/*
Time complexity: O(2^2M), where M is the number of elements present in the cuts array.
Space complexity: O(M) auxiliary stack space.
*/

/*
Top down memoization DP.
*/

class Solution {
public:
    int solve(vector<int>& cuts, int i, int j, vector<vector<int>>& dp){
        if(i+1 >= j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = INT_MAX;
        for(int k=i+1; k<j; k++){
            int ans = (cuts[j]-cuts[i]) + solve(cuts, i, k, dp) + solve(cuts, k, j, dp);
            mini = min(mini, ans);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, -1));
        int ans = solve(cuts, 0, m-1, dp);
        return ans;
    }
};

/*
Time complexity: O(M^3), where M is the number of elements present in the array.
Space complexity: O(M*M) for the DP array and O(M) auxiliary stack space.
*/

/*
Bottom up DP tabulation.
*/

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<long long>> dp(m+1, vector<long long>(m+1, 0));
        for(int i=m-1; i>=0; i--){
            for(int j=i+1; j<m; j++){
                if (i + 1 >= j) {
                    dp[i][j] = 0;
                    continue;
                }
                long long mini = INT_MAX;
                for(int k=i+1; k<j; k++){
                    long long ans = (cuts[j]-cuts[i]) + dp[i][k] + dp[k][j];
                    mini = min(mini, ans);
                }
                dp[i][j] = mini;
            }
        }

        return dp[0][m-1];
    }
};

/*
Time complexity: O(M^3), where M is the number of elements present in the array.
Space complexity: O(M*M) for the DP array and please not that we are not using an auxiliary stack space here.
*/