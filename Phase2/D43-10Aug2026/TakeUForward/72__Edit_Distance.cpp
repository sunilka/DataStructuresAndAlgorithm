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
    int solve(string& word1, string& word2, int n1, int n2, int idx1, int idx2, vector<vector<int>> &dp){   
        if(idx2 >= n2){
            if(idx1 < n1) return n1 - idx1;
            return 0;
        }
        if(idx1 >= n1){
            if(idx2 < n2) return n2 - idx2;
            return 0;
        }

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        if(word1[idx1] == word2[idx2]){
            int ans = solve(word1, word2, n1, n2, idx1+1, idx2+1, dp);
            dp[idx1][idx2] = ans;
            return ans;
        }

        int ans = min(
            solve(word1, word2, n1, n2, idx1, idx2+1, dp)+1, 
            min(
                solve(word1, word2, n1, n2, idx1+1, idx2, dp)+1, 
                solve(word1, word2, n1, n2, idx1+1, idx2+1, dp)+1
            )
        ); 
        dp[idx1][idx2] = ans;
        return ans;
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return solve(word1, word2, n1, n2, 0, 0, dp);
    }
};

/*
Time complexity: O(N*M), where N is the size of the word 1 and M is the size of the word2.
Space complexity: O(N*M)+(N+M) aux space.
*/

/*
Bottom up DP.
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i=0; i<=n1; i++) dp[i][n2] = n1 - i;
        for(int i=0; i<=n2; i++) dp[n1][i] = n2 - i;
        for(int idx1=n1-1; idx1>=0; idx1--){
            for(int idx2=n2-1; idx2>=0; idx2--){
                int ans;
                if(word1[idx1] == word2[idx2]) ans = dp[idx1+1][idx2+1];
                else ans = min(dp[idx1][idx2+1]+1, min(dp[idx1+1][idx2]+1, dp[idx1+1][idx2+1]+1)); 
                dp[idx1][idx2] = ans;
            }
        }
        return dp[0][0];
    }
};

/*
Time complexity: O(N*M), where N is the size of the word 1 and M is the size of the word2.
Space complexity: O(N*M) space.
*/

/*
Space optimization.
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<int> cur(n2+1, 0), next(n2+1, 0);
        for(int j = 0; j <= n2; j++) next[j] = n2 - j;
        for(int i=0; i<=n1; i++) next[n2] = n1 - i;
        for(int idx1=n1-1; idx1>=0; idx1--){
            cur[n2] = n1 - idx1;
            for(int idx2=n2-1; idx2>=0; idx2--){
                int ans;
                if(word1[idx1] == word2[idx2]) ans = next[idx2+1];
                else ans = min(cur[idx2+1]+1, min(next[idx2]+1, next[idx2+1]+1)); 
                cur[idx2] = ans;
            }
            next = cur;
        }
        return next[0];
    }
};
/*
Time complexity: O(N*M), where N is the size of the word 1 and M is the size of the word2.
Space complexity: O(M) space.
*/