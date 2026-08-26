/*
Longest Common Substring
Given two strings s1 and s2, determine the length of the longest substring that appears in both strings.

Examples:

Input: s1 = "ABCDGH", s2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" with a length of 4.
Input: s1 = "abc", s2 = "acb"
Output: 1
Explanation: The longest common substrings are "a", "b", "c" all having length 1.
Input: s1 = "YZ", s2 = "yz"
Output: 0
Explanation: Comparison is case-sensitive, so 'Y' ≠ 'y' and 'Z' ≠ 'z'. Hence, no common substring exists.
Constraints:
1 ≤ s1.size(), s2.size() ≤ 103
Both strings consist only of uppercase and lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(string &s1, string &s2, int& n1, int& n2, int i, int j, int& max_ans){
        if(i>=n1 || j>=n2) return 0;
        solve(s1, s2, n1, n2, i+1, j, max_ans);
        solve(s1, s2, n1, n2, i, j+1, max_ans);
        int ans = 0;
        if(s1[i] == s2[j]){
            ans = solve(s1, s2, n1, n2, i+1, j+1, max_ans)+1;
            max_ans = max(max_ans, ans);
        }
        return ans;
    }
    int longCommSubstr(string& s1, string& s2) {
        int n1 = s1.size(), n2 = s2.size(), max_ans = 0;
        solve(s1, s2, n1, n2, 0, 0, max_ans);
        return max_ans;
    }
};

/*
Time complexity: O(3^(M+N)), where M is the number of elements present in the first string and N is the number of elements
present in the second string.
Space complexity: O(M+N) auxiliary stack space.
*/

/*
Top down memoization DP.
*/

class Solution {
  public:
    int solve(string &s1, string &s2, int& n1, int& n2, int i, int j, int& max_ans, vector<vector<int>>& dp){
        if(i>=n1 || j>=n2) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        solve(s1, s2, n1, n2, i+1, j, max_ans, dp);
        solve(s1, s2, n1, n2, i, j+1, max_ans, dp);
        int ans = 0;
        if(s1[i] == s2[j]){
            ans = solve(s1, s2, n1, n2, i+1, j+1, max_ans, dp)+1;
            max_ans = max(max_ans, ans);
        }
        dp[i][j] = ans;
        return ans;
    }
    int longCommSubstr(string& s1, string& s2) {
        int n1 = s1.size(), n2 = s2.size(), max_ans = 0;
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        solve(s1, s2, n1, n2, 0, 0, max_ans, dp);
        return max_ans;
    }
};

/*
Time complexity: O(M*N), where M is the number of elements present in the s1 string and N is the number of elements 
present in the s2 string.
Space complexity: O(M*N) for the DP array and O(M+N) auxiliary stack space.
*/


/*
Bottom up DP. Tabulation method
*/

class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        int n1 = s1.size(), n2 = s2.size(), max_ans = 0;
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                int ans = 0;
                if(s1[i] == s2[j]){
                    ans = dp[i+1][j+1]+1;
                    max_ans = max(max_ans, ans);
                }
                dp[i][j] = ans;
            }
        }
        return max_ans;
    }
};

/*
Time complexity: O(M*N), where M is the number of elements present in the s1 string and N is the number of elements 
present in the s2 string.
Space complexity: O(M*N) for the DP array and please note that there is no auxikiary stack space involved here.
*/

/*
Space optimization.
*/

class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        int n1 = s1.size(), n2 = s2.size(), max_ans = 0;
        vector<int> cur(n2+1, 0), next(n2+1, 0);
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                int ans = 0;
                if(s1[i] == s2[j]){
                    ans = next[j+1]+1;
                    max_ans = max(max_ans, ans);
                }
                cur[j] = ans;
            }
            next = cur;
        }
        return max_ans;
    }
};

/*
Time complexity: O(M*N), where M is the number of elements present in the s1 string and N is the number of elements 
present in the s2 string.
Space complexity: O(N) for the DP array and please note that there is no auxikiary stack space involved here.
*/