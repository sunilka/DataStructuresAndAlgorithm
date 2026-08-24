/*
Longest Common Subsequence
Given two strings s1 and s2, return the length of their longest common subsequence (LCS). If there is no common subsequence, return 0.

A subsequence is a sequence that can be derived from the given string by deleting some or no elements without changing the order of the remaining elements. For example, "ABE" is a subsequence of "ABCDE".

Examples:

Input: s1 = "ABCDGH", s2 = "AEDFHR"
Output: 3
Explanation: The longest common subsequence of "ABCDGH" and "AEDFHR" is "ADH", which has a length of 3.
Input: s1 = "ABC", s2 = "AC"
Output: 2
Explanation: The longest common subsequence of "ABC" and "AC" is "AC", which has a length of 2.
Input: s1 = "XYZW", s2 = "XYWZ"
Output: 3
Explanation: The longest common subsequences of "XYZW" and "XYWZ" are "XYZ" and "XYW", both of length 3.
Constraints:
1<= s1.size(), s2.size() <=103
Both strings s1 and s2 contain only uppercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(string& s1, string& s2, int n1, int n2, int i, int j){
        if(i>=n1 || j>=n2) return 0;
        if(s1[i] == s2[j]) return solve(s1, s2, n1, n2, i+1, j+1) + 1;
        int ans = max(solve(s1, s2, n1, n2, i+1, j), solve(s1, s2, n1, n2, i, j+1));
        return ans;
    }   
    int lcs(string &s1, string &s2) {
        int n1 = s1.size(), n2 = s2.size();
        return solve(s1, s2, n1, n2, 0, 0);
    }
};


/*
Time complexity: O(2^(m+n)), where m is the number of elements present in the s1 and n is number of elements present in s2. 
Space complexity: O(m+n) auxiliary stack space. 
*/

/*
Top down memoization.
*/

class Solution {
  public:
    int solve(string& s1, string& s2, int n1, int n2, int i, int j, vector<vector<int>>& dp){
        if(i>=n1 || j>=n2) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = solve(s1, s2, n1, n2, i+1, j+1, dp) + 1;
        int ans = max(solve(s1, s2, n1, n2, i+1, j, dp), solve(s1, s2, n1, n2, i, j+1, dp));
        return dp[i][j] = ans;
    }   
    int lcs(string &s1, string &s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return solve(s1, s2, n1, n2, 0, 0, dp);
    }
};

/*
Time complexity: O(n1*n2) where n1 is the number of characters in the string s1 and n2 is the number of characters in the string s2.
Space complexity: O(n1*n2) for the DP array and O(n1+n2) auxiliary stack space. 
*/

/*
Bottom up approach - Tabulation method
*/

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                if(s1[i] == s2[j]) dp[i][j] = dp[i+1][j+1] + 1;
                else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};


/*
Time complexity: O(n1*n2) where n1 is the number of characters in the string s1 and n2 is the number of characters in the string s2.
Space complexity: O(n1*n2) for the DP array and please note that there is no auxiliary stack space involved here.  
*/

/*
Space optimization.
*/

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<int> cur(n2+1, 0), next(n2+1, 0);
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                if(s1[i] == s2[j]) cur[j] = next[j+1] + 1;
                else cur[j] = max(next[j], cur[j+1]);
            }
            next = cur;
        }
        return next[0];
    }
};

/*
Time complexity: O(n1*n2) where n1 is the number of characters in the string s1 and n2 is the number of characters in the string s2.
Space complexity: O(n2) for the DP array and please note that there is no auxiliary stack space involved here.  
*/

