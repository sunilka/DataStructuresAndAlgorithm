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
    int solve(string &s, int idx1, int idx2, vector<vector<int>>& dp){
        if(idx1 > idx2) return 0;
        if(idx1 == idx2) return 1;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s[idx1] == s[idx2]){
            int ans = solve(s, idx1+1, idx2-1, dp)+2;
            dp[idx1][idx2] = ans;
            return ans;
        }
        else{
            int ans = max(
                solve(s, idx1+1, idx2, dp),
                solve(s, idx1, idx2-1, dp)
            );
            dp[idx1][idx2] = ans;
            return ans;
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(s, 0, n-1, dp);
    }
};

/*
Time complexity: O(N*N), where N is the size of the string.
Space complexity: O(N*N)+O(N+N) aux space, where N is the size of the string
*/

/*
Bottom up approach.
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for(int idx1=n-1; idx1>=0; idx1--){
            for(int idx2=idx1+1; idx2<n; idx2++){
                if(s[idx1] == s[idx2]) dp[idx1][idx2] = dp[idx1+1][idx2-1]+2;
                else dp[idx1][idx2] = max(dp[idx1+1][idx2],dp[idx1][idx2-1]);
            }
        }
        return dp[0][n-1];
    }
};
/*
Time complexity: O(N*N), where N is the size of the string.
Space complexity: O(N*N), where N is the size of the string
*/

/*
Space optimized version
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> next(n+1, 0);
        vector<int> cur(n+1, 0);
        for(int idx1=n-1; idx1>=0; idx1--){
            cur[idx1] = 1;
            for(int idx2=idx1+1; idx2<n; idx2++){
                if(s[idx1] == s[idx2]) cur[idx2] = next[idx2-1]+2;
                else cur[idx2] = max(next[idx2], cur[idx2-1]);
            }
            next = cur;
        }
        return next[n-1];
    }
};
/*
Time complexity: O(N*N), where N is the size of the string.
Space complexity: O(N), where N is the size of the string
*/