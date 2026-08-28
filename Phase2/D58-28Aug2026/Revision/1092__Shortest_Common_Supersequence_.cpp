/*
1092. Shortest Common Supersequence 

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                if(s1[i] == s2[j]) dp[i][j] = dp[i+1][j+1] + 1;
                else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        int i=0, j=0;
        string ans = "";
        while(i<n1 && j<n2){
            if(s1[i] == s2[j]){
                ans+=s1[i];
                i++, j++;
            }
            else if(dp[i+1][j] >= dp[i][j+1]){
                ans+=s1[i];
                i++;
            }
            else{
                ans+=s2[j];
                j++;
            }
        }
        while(i<n1) ans+=s1[i++];
        while(j<n2) ans+=s2[j++];
        return ans;
    }
};

/*
Time complexity: O(N1 * N2), where N1 and N2 are the lengths of s1 and s2.
Space complexity: O(N1 * N2) for the 2D DP matrix + O(N1 + N2) for the output string.
*/