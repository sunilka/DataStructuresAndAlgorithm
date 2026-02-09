//https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSumIS(vector<int>& a) {
        int n = a.size();
    
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int pos = n - 1; pos >= 0; pos--) {
            for (int prev = pos - 1; prev >= -1; prev--) {
                int ans = dp[pos + 1][prev + 1];
    
                if (prev == -1 || a[pos] > a[prev]) {
                    ans = max(ans, a[pos] + dp[pos + 1][pos + 1]);
                }
    
                dp[pos][prev + 1] = ans;
            }
        }
    
        return dp[0][0]; 
    }

};