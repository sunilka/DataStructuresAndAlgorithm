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
    int solve(string& s, string& t, int& n1, int& n2, int i, int j){
        if(j==n2) return 1;
        if(i==n1) return 0;
        int ans = 0;
        if(s[i] == t[j]){
            ans += solve(s, t, n1, n2, i+1, j+1);
        }
        ans += solve(s, t, n1, n2, i+1, j);
        return ans;
    }
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        return solve(s, t, n1, n2, 0, 0);
    }
};

/*
Time complexity: O(2^(N1)), where N1 is the number of elements present in the string s.
Space complexity: O(N1) auxiliary stack space.
*/

/*
Top down memoization solution.
*/

class Solution {
public:
    int solve(string& s, string& t, int& n1, int& n2, int i, int j, vector<vector<int>>& dp){
        if(j==n2) return 1;
        if(i==n1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s[i] == t[j]) ans += solve(s, t, n1, n2, i+1, j+1, dp);
        ans += solve(s, t, n1, n2, i+1, j, dp);
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return solve(s, t, n1, n2, 0, 0, dp);
    }
};

/*
Time complexity: O(n1*n2), where n1 is the number of elements present in the string s and n2 is the number of 
elements present in the string t.
Space complexity: O(n1*n2) for the DP array and O(n1+n2) auxiliary stack space.
*/

/*
Bottom up - tabulation method.
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        vector<vector<unsigned long long>> dp(n1+1, vector<unsigned long long>(n2+1, 0));
        for(int i=0; i<=n1; i++) dp[i][n2] = 1;
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                unsigned long long ans = 0;
                if(s[i] == t[j]) ans += dp[i+1][j+1];
                ans += dp[i+1][j];
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};

/*
Time complexity: O(n1*n2), where n1 is the number of elements present in the string s and n2 is the number of 
elements present in the string t.
Space complexity: O(n1*n2) for the DP array and we are not using any exta auxiliary stack space here.
*/

/*
Space optimization.
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        vector<unsigned long long> cur(n2+1, 0), next(n2+1, 0);
        for(int i=n1-1; i>=0; i--){
            next[n2] = 1;
            for(int j=n2-1; j>=0; j--){
                unsigned long long ans = 0;
                if(s[i] == t[j]) ans += next[j+1];
                ans += next[j];
                cur[j] = ans;
            }
            next = cur;
        }
        return next[0];
    }
};

/*
Time complexity: O(n1*n2), where n1 is the number of elements present in the string s and n2 is the number of 
elements present in the string t.
Space complexity: O(n2) for the DP array and we are not using any exta auxiliary stack space here.
*/
