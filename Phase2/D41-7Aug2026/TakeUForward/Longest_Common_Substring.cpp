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
    int solve(string& s1, string& s2, int idx1, int idx2, vector<vector<int>>& dp, int& maxLen) {
        if (idx1 >= s1.size() || idx2 >= s2.size()) return 0;
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
        int currentMatch = 0;
        if (s1[idx1] == s2[idx2]) {
            currentMatch = 1 + solve(s1, s2, idx1 + 1, idx2 + 1, dp, maxLen);
        }
        maxLen = max(maxLen, currentMatch);
        solve(s1, s2, idx1 + 1, idx2, dp, maxLen);
        solve(s1, s2, idx1, idx2 + 1, dp, maxLen);
        return dp[idx1][idx2] = currentMatch;
    }

    int longCommSubstr(string& s1, string& s2) {
        int n1 = s1.size(), n2 = s2.size(), maxLen = 0;
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        solve(s1, s2, 0, 0, dp, maxLen);
        return maxLen;
    }
};

/*
Time complexity: O(N*M), where N is the number of elements present in the first array and the N2 is the 
number of elements present in the 2nd array.
Space complexity: O(N*M)+O(N+M), for the DP array, and O(N+M) is the aux space.
*/

class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        int n1 = s1.size(), n2 = s2.size(), maxLen = 0;
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int idx1 = n1 - 1; idx1 >= 0; idx1--) {
            for (int idx2 = n2 - 1; idx2 >= 0; idx2--) {
                if (s1[idx1] == s2[idx2]) {
                    dp[idx1][idx2] = 1 + dp[idx1 + 1][idx2 + 1]; 
                    maxLen = max(maxLen, dp[idx1][idx2]);
                } else {
                    dp[idx1][idx2] = 0;
                }
            }
        }
        return maxLen;
    }
};

/*
Time complexity: O(N*M), where N is the number of elements present in the first array and the N2 is the 
number of elements present in the 2nd array.
Space complexity: O(N*M), for the DP array, and O(N+M) is the aux space.
*/
