/*
583. Delete Operation for Two Strings

Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
 

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string& word1, string &word2, int& n1, int& n2, int i, int j){
        if (i == n1) return n2 - j;
        if (j == n2) return n1 - i; 
        if(word1[i] == word2[j]){
            return solve(word1, word2, n1, n2, i+1, j+1);
        }
        int ans = min(
            solve(word1, word2, n1, n2, i+1, j)+1,
            solve(word1, word2, n1, n2, i, j+1)+1
        );
        return ans;
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        return solve(word1, word2, n1, n2, 0, 0);
    }
};

/*
Time complexity: O(2^(n1+n2)), where n1 is the number of elements present in the word1 and word2 is the number 
of elements present in the word2.
Space complexity: O(n1+n2) auxiliary stack space.
*/

class Solution {
public:
    int solve(string& word1, string &word2, int& n1, int& n2, int i, int j, vector<vector<int>>& dp){
        if(i == n1) return n2 - j;
        if(j == n2) return n1 - i; 
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) return dp[i][j] = solve(word1, word2, n1, n2, i+1, j+1, dp);
        int ans = min(
            solve(word1, word2, n1, n2, i+1, j, dp)+1,
            solve(word1, word2, n1, n2, i, j+1, dp)+1
        );
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return solve(word1, word2, n1, n2, 0, 0, dp);
    }
};

/*
Time complexity: O(n1*n2), where n1 is the number of elements present in the word1 and word2 is the number 
of elements present in the word2.
Space complexity: O(n1*n2) for the DP array and O(n1+n2) auxiliary stack space. 
*/


class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size(), ans;
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int j=0; j<n2; j++) dp[n1][j] = n2 - j;
        for(int i=0; i<n1; i++) dp[i][n2] = n1 - i;
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                if(word1[i] == word2[j]) ans = dp[i+1][j+1];
                else ans = min(dp[i+1][j]+1, dp[i][j+1]+1);
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};

/*
Time complexity: O(n1*n2), where n1 is the number of elements present in the word1 and word2 is the number 
of elements present in the word2.
Space complexity: O(n1*n2) for the DP array and please note here that there is no auxiliary stack space here.
*/

/*
Space optimization
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size(), ans;
        vector<int> cur(n2+1, 0), next(n2+1, 0);
        for(int j=0; j<n2; j++) next[j] = n2 - j;
        for(int i=n1-1; i>=0; i--){
            cur[n2] = n1 - i;
            for(int j=n2-1; j>=0; j--){
                if(word1[i] == word2[j]) ans = next[j+1];
                else ans = min(next[j]+1, cur[j+1]+1);
                cur[j] = ans;
            }
            next = cur;
        }
        return next[0];
    }
};

/*
Time complexity: O(n1*n2), where n1 is the number of elements present in the word1 and word2 is the number 
of elements present in the word2.
Space complexity: O(n2) for the DP array and please note here that there is no auxiliary stack space here.
*/
