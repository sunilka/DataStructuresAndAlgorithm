/*
516. Longest Palindromic Subsequence
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string& s, int i, int j){
        if(i==j) return 1;
        if(i > j) return 0;
        if(s[i] == s[j]) return solve(s, i+1, j-1)+2;
        return max(solve(s, i+1, j), solve(s, i, j-1));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        return solve(s, 0, n-1);
    }
};

/*
Time complexity: O(2^(N)), where N is the number of characters present in the string s. 
Space complexity: O(N) auxiliary stack space.
*/

/*
Top down memoization solution.
*/

class Solution {
public:
    int solve(string& s, int i, int j, vector<vector<int>> &dp){
        if(i==j) return 1;
        if(i > j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] = solve(s, i+1, j-1, dp)+2;
        return dp[i][j] = max(solve(s, i+1, j, dp), solve(s, i, j-1, dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(s, 0, n-1, dp);
    }
};

/*
Time complexity: O(N*N), where N is the number of elements present in the given string.
Space complexity: O(N*N) for the DP array and O(N) auxiliary stack space.
*/

/*
Bottom up DP - tabulation method.
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) dp[i][j] = 1;
            }
        }
        
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1]+2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};

/*
Time complexity: O(N*N), where N is the number of elements present in the given string.
Space complexity: O(N*N) for the DP array and please note that we are not using any auxiliary stack space here. 
*/

/*
Space optimization.
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> cur(n+1, 0), next(n+1, 0);
        for(int i=n-1; i>=0; i--){
            cur[i] = 1;
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j]) cur[j] = next[j-1]+2;
                else cur[j] = max(next[j], cur[j-1]);
            }
            next = cur;
        }
        return next[n-1];
    }
};

/*
Time complexity: O(N*N), where N is the number of elements present in the given string.
Space complexity: O(N) for the DP array and please note that we are not using any auxiliary stack space here. 
*/