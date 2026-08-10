/*
115. Distinct Subsequences

Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
 

Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string& s, string& t, int n1, int n2, int idx1, int idx2,vector<vector<int>>& dp){
        if (idx2 >= n2) return 1; 
        if (idx1 >= n1) return 0;
        if (dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        int ans = 0;
        if(s[idx1] == t[idx2]){
            ans += solve(s, t, n1, n2, idx1+1, idx2+1, dp);
        }
        ans += solve(s, t, n1, n2, idx1+1, idx2, dp);
        dp[idx1][idx2] = ans;
        return ans;
    }
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return solve(s, t, n1, n2, 0, 0, dp);
    }
};

/*
Time complexity: O(N*M), where N is the length of 1 and M is the length of s.
Space complexity: O(N*M)+(N+M), where N is the length of 1 and M is the length of s.
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        vector<vector<unsigned long long>> dp(n1+1, vector<unsigned long long>(n2+1, 0));
        for(int i=0; i<=n1; i++) dp[i][n2] = 1;
        for(int idx1=n1-1; idx1>=0; idx1--){
            for(int idx2=n2-1; idx2>=0; idx2--){
                unsigned long long ans = 0;
                if (s[idx1] == t[idx2]) {
                    ans += dp[idx1 + 1][idx2 + 1];
                }
                ans += dp[idx1 + 1][idx2];
                dp[idx1][idx2] = ans;
            }
        }
        return dp[0][0];
    }
};

/*
Time complexity: O(N*M), where N is the length of 1 and M is the length of s.
Space complexity: O(N*M), where N is the length of 1 and M is the length of s.
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        vector<unsigned long long> next(n2+1, 0), cur(n2+1, 0);
        for(int idx1=n1-1; idx1>=0; idx1--){
            next[n2] = 1;
            for(int idx2=n2-1; idx2>=0; idx2--){
                unsigned long long ans = 0;
                if (s[idx1] == t[idx2]) {
                    ans += next[idx2 + 1];
                }
                ans += next[idx2];
                cur[idx2] = ans;
            }
            next = cur;
        }
        return next[0];
    }
};

/*
Time complexity: O(N*M), where N is the length of 1 and M is the length of s.
Space complexity: O(M), where N is the length of 1 and M is the length of s.
*/
