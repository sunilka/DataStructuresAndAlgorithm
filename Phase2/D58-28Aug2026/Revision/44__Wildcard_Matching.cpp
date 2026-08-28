/*
44. Wildcard Matching

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(string& s, string& p, int n1, int n2, int idx1, int idx2){
        if(idx1 == n1 && idx2 == n2) return true;
        if(idx2 == n2) return false;
        if(idx1 == n1){
            for(int i=idx2; i<n2; i++){
                if(p[i]!='*') return false;
            }
            return true;
        }
        if(s[idx1] == p[idx2] || p[idx2] == '?') return solve(s, p, n1, n2, idx1+1, idx2+1);
        if(p[idx2] == '*') return solve(s, p, n1, n2, idx1, idx2+1) || solve(s, p, n1, n2, idx1+1, idx2);
        return false;
    }
    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        return solve(s, p, n1, n2, 0, 0);
    }
};

/*
Time complexity: O(2^(N1+N2)), where N1 is the number of elements present in string s and N2 is the number of 
elements present in string p.
Space complexity: O(N1+N2) auxiliary stack space would be used.
*/

/*
Top down memoization solution
*/
class Solution {
public:
    bool solve(string& s, string& p, int n1, int n2, int idx1, int idx2,vector<vector<int>> &dp){
        if(idx1 == n1 && idx2 == n2) return true;
        if(idx2 == n2) return false;
        if(idx1 == n1){
            for(int i=idx2; i<n2; i++){
                if(p[i]!='*') return false;
            }
            return true;
        }
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s[idx1] == p[idx2] || p[idx2] == '?') return dp[idx1][idx2] = solve(s, p, n1, n2, idx1+1, idx2+1, dp);
        if(p[idx2] == '*') return dp[idx1][idx2] = solve(s, p, n1, n2, idx1, idx2+1, dp) || solve(s, p, n1, n2, idx1+1, idx2, dp);
        return dp[idx1][idx2] = false;
    }
    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return solve(s, p, n1, n2, 0, 0, dp);
    }
};

/*
Time complexity: O(N1*N2) where N1 is the number of elements present in the string s and N2 is the number of elements
present in the string p.
Space complexity: O(N1*N2) for the DP array and O(N1+N2) auxiliary stack space.
*/

/*
Bottom up DP - tabulation method.
*/

class Solution {
public:
    bool isAllStars(string &p, int idx2, int n2){
        for (int i = idx2; i < n2; i++) {
            if (p[i] != '*') return false;
        }
        return true;
    }
    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
        dp[n1][n2] = true;
        for (int idx2 = 0; idx2 < n2; idx2++) {
            dp[n1][idx2] = isAllStars(p, idx2, n2);
        }
        for(int idx1=n1-1; idx1>=0; idx1--){
            for(int idx2=n2-1; idx2>=0; idx2--){
                if(s[idx1] == p[idx2] || p[idx2] == '?') dp[idx1][idx2] = dp[idx1+1][idx2+1];
                else if(p[idx2] == '*') dp[idx1][idx2] = dp[idx1][idx2+1] || dp[idx1+1][idx2];
                else dp[idx1][idx2] = false;
            }
        }
        return dp[0][0];
    }
};

/*
Time complexity: O(N1*N2) where N1 is the number of elements present in the string s and N2 is the number of elements
present in the string p.
Space complexity: O(N1*N2) for the DP array and please note here that there is no auxiliary space involved in this 
approach.
*/