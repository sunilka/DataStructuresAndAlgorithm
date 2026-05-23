// https://www.geeksforgeeks.org/problems/rod-cutting0840

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int cutRod(vector<int> &price) {
        vector<int> dp(price.size()+1, 0);
        for(int len=1; len<=price.size(); len++){
            int ans = INT_MIN;
            for(int cut=1; cut<=len; cut++){
                ans = max(ans, price[cut - 1] + dp[len - cut]);
            }
            dp[len] = ans;
        }
        return dp[price.size()];
    }
};