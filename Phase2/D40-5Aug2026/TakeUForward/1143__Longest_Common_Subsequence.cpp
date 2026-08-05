/*
1143. Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string& text1, string& text2, int n1, int n2, int idx1, int idx2, vector<vector<int>>& dp){
        if(idx1 >= n1 || idx2 >= n2) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(text1[idx1] == text2[idx2]){
            int ans = solve(text1, text2, n1, n2, idx1+1, idx2+1, dp)+1;
            dp[idx1][idx2] = ans;
            return ans;
        }
        else{
            int ans = max(
                solve(text1, text2, n1, n2, idx1+1, idx2, dp),
                solve(text1, text2, n1, n2, idx1, idx2+1, dp)
            );
            dp[idx1][idx2] = ans;
            return ans;
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size() > text2.size()) return longestCommonSubsequence(text2, text1);
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return solve(text1, text2, n1, n2, 0, 0, dp);
    }
};

/*
Time complexity: O(N*M), where N is the number of characters in string 1 and M is the number of charatcers in string 2.
Space complexity: O(N×M)+O(min(N,M)), where N is the number of characters in string 1 and M is the number of charatcers in string 2.
*/

/*
Bottom up approach
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size() > text2.size()) return longestCommonSubsequence(text2, text1);
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int idx1=n1-1; idx1>=0; idx1--){
            for(int idx2=n2-1; idx2>=0; idx2--){
                int ans = 0;
                if(text1[idx1] == text2[idx2]) ans = dp[idx1+1][idx2+1]+1;
                else ans = max(dp[idx1+1][idx2], dp[idx1][idx2+1]);
                dp[idx1][idx2] = ans;
            }
        }
        return dp[0][0];
    }
};

/*
Time complexity: O(N*M), where N is the number of characters in string 1 and M is the number of charatcers in string 2.
Space complexity: O(N*M), where N is the number of characters in string 1 and M is the number of charatcers in string 2.
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size() > text2.size()) return longestCommonSubsequence(text2, text1);
        int n1 = text1.size(), n2 = text2.size();
        vector<int> next(n2+1, 0), cur(n2+1, 0);
        for(int idx1=n1-1; idx1>=0; idx1--){
            for(int idx2=n2-1; idx2>=0; idx2--){
                int ans = 0;
                if(text1[idx1] == text2[idx2]) ans = next[idx2+1]+1;
                else ans = max(next[idx2], cur[idx2+1]);
                cur[idx2] = ans;
            }
            next = cur;
        }
        return next[0];
    }
};

/*
Time complexity: O(N*M), where N is the number of characters in string 1 and M is the number of charatcers in string 2.
Space complexity: O(M), where N is the number of characters in string 1 and M is the number of charatcers in string 2.
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() > text2.size()) return longestCommonSubsequence(text2, text1);
        
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // 1. Fill the DP Table (Bottom-Up)
        for (int idx1 = n1 - 1; idx1 >= 0; idx1--) {
            for (int idx2 = n2 - 1; idx2 >= 0; idx2--) {
                if (text1[idx1] == text2[idx2]) {
                    dp[idx1][idx2] = dp[idx1 + 1][idx2 + 1] + 1;
                } else {
                    dp[idx1][idx2] = max(dp[idx1 + 1][idx2], dp[idx1][idx2 + 1]);
                }
            }
        }

        // 2. Backtrack from dp[0][0] to reconstruct the string
        string lcs = "";
        int idx1 = 0, idx2 = 0;

        while (idx1 < n1 && idx2 < n2) {
            if (text1[idx1] == text2[idx2]) {
                lcs += text1[idx1];  // Include character in LCS
                idx1++;
                idx2++;
            } else if (dp[idx1 + 1][idx2] > dp[idx1][idx2 + 1]) {
                idx1++;  // Move down
            } else {
                idx2++;  // Move right
            }
        }

        cout << "LCS String: " << lcs << endl;
        return dp[0][0];
    }
};