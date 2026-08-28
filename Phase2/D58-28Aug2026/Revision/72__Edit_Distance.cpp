/*
72. Edit Distance
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 
Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string& word1, string& word2, int& n1, int& n2, int i, int j){
        if(i == n1) return n2 - j;
        if(j == n2) return n1 - i;  
        if(word1[i] == word2[j]) return solve(word1, word2, n1, n2, i+1, j+1);
        int ins = solve(word1, word2, n1, n2, i, j+1)+1;
        int del = solve(word1, word2, n1, n2, i+1, j)+1;
        int rep = solve(word1, word2, n1, n2, i+1, j+1)+1;
        return min(ins, min(del, rep));
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        return solve(word1, word2, n1, n2, 0, 0);
    }
};

/*
Time complexity: O(3^N1), where N1 is the number of elements present in the word1.
Space complexity: O(N1) auxiliary stack space.
*/

/*
Top down memoization solution.
*/

class Solution {
public:
    int solve(string& word1, string& word2, int& n1, int& n2, int i, int j, vector<vector<int>>& dp){
        if(i == n1) return n2 - j;
        if(j == n2) return n1 - i; 
        if(dp[i][j]!=-1) return dp[i][j]; 
        if(word1[i] == word2[j]) return dp[i][j] = solve(word1, word2, n1, n2, i+1, j+1, dp);
        int ins = solve(word1, word2, n1, n2, i, j+1, dp)+1;
        int del = solve(word1, word2, n1, n2, i+1, j, dp)+1;
        int rep = solve(word1, word2, n1, n2, i+1, j+1, dp)+1;
        return dp[i][j] = min(ins, min(del, rep));
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return solve(word1, word2, n1, n2, 0, 0, dp);
    }
};

/*
Time complexity: O(N1*N2), where N1 is the number of elements present in the word1 and N2 is the number of elements
present in the word2.
Space complexity: O(N1*N2) for the DP array and O(N1+N2) auxiliary stack space.
*/

/*
Bottom up DP - tabulation.
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int j=0; j<=n2; j++) dp[n1][j] = n2 - j;
        for(int i=0; i<=n1; i++) dp[i][n2] = n1 - i;
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                if(word1[i] == word2[j]) dp[i][j] = dp[i+1][j+1];
                else dp[i][j] = min(dp[i][j+1]+1, min(dp[i+1][j]+1, dp[i+1][j+1]+1));
            }
        }
        return dp[0][0];
    }
};

/*
Time complexity: O(N1*N2), where N1 is the number of elements present in the word1 and N2 is the number of elements
present in the word2.
Space complexity: O(N1*N2) for the DP array and here we are not using any extra auxiliary stack space here.
*/

/*
Space optimization.
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<int> cur(n2+1, 0), next(n2+1, 0);
        for(int j=0; j<=n2; j++) next[j] = n2 - j;
        for(int i=n1-1; i>=0; i--){
            cur[n2] = n1 - i;
            for(int j=n2-1; j>=0; j--){
                if(word1[i] == word2[j]) cur[j] = next[j+1];
                else cur[j] = min(cur[j+1]+1, min(next[j]+1, next[j+1]+1));
            }
            next = cur;
        }
        return next[0];
    }
};

/*
Time complexity: O(N1*N2), where N1 is the number of elements present in the word1 and N2 is the number of elements
present in the word2.
Space complexity: O(N2) for the DP array and please note here we are not using extra stack space.
*/