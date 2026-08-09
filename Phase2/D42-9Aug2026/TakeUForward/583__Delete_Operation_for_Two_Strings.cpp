/*
583. Delete Operation for Two Strings
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

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
    int solve(string& word1, string& word2, int n1, int n2, int idx1, int idx2, vector<vector<int>>& dp){
        if(idx1 >= n1){
            if(idx2 < n2) return n2 - idx2;
            return 0;
        }
        if(idx2 >= n2){
            if(idx1 < n1) return n1 - idx1;
            return 0;
        }

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        if(word1[idx1] == word2[idx2]){
            int ans = solve(word1, word2, n1, n2, idx1+1, idx2+1, dp);
            dp[idx1][idx2] = ans;
            return ans;
        }
        
        int ans = min(
            solve(word1, word2, n1, n2, idx1+1, idx2, dp)+1,
            solve(word1, word2, n1, n2, idx1, idx2+1, dp)+1
        );
        dp[idx1][idx2] = ans;
        return ans;
    }
    int minDistance(string word1, string word2) {
        if(word1 == word2) return 0;
        if(word1.size() == 0 && word2.size()>0) return word2.size();
        if(word2.size() == 0 && word1.size()>0) return word1.size();
        if(word1.size() > word2.size()) return minDistance(word2, word1);
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return solve(word1, word2, n1, n2, 0, 0, dp);
    }
};

/*
Time complexity: O(N*M) where N is the length of word1 and M is the length of word2.
Space complexity: O(N*M)+O(N+M) aux space
*/

/*
Bottom up approach
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1 == word2) return 0;
        if(word1.size() == 0 && word2.size()>0) return word2.size();
        if(word2.size() == 0 && word1.size()>0) return word1.size();
        if(word1.size() > word2.size()) return minDistance(word2, word1);
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for (int idx2 = 0; idx2 <= n2; idx2++) dp[n1][idx2] = n2 - idx2;
        for (int idx1 = 0; idx1 <= n1; idx1++) dp[idx1][n2] = n1 - idx1;

        for(int idx1=n1-1; idx1>=0; idx1--){
            for(int idx2=n2-1; idx2>=0; idx2--){
                int ans;
                if(word1[idx1] == word2[idx2]) ans = dp[idx1+1][idx2+1];
                else ans = min(dp[idx1+1][idx2]+1, dp[idx1][idx2+1]+1);
                dp[idx1][idx2] = ans;
            }
        }
        return dp[0][0];
    }
};

/*
Time complexity: O(N*M) where N is the length of word1 and M is the length of word2.
Space complexity: O(N*M)
*/

/*
Space optimization
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1 == word2) return 0;
        if(word1.size() == 0 && word2.size()>0) return word2.size();
        if(word2.size() == 0 && word1.size()>0) return word1.size();
        if(word1.size() > word2.size()) return minDistance(word2, word1);
        int n1 = word1.size(), n2 = word2.size();

        vector<int> next(n2+1, 0), cur(n2+1, 0);
        for (int idx2 = 0; idx2 <= n2; idx2++) next[idx2] = n2 - idx2;

        for(int idx1=n1-1; idx1>=0; idx1--){
            cur[n2] = n1 - idx1;
            for(int idx2=n2-1; idx2>=0; idx2--){
                int ans;
                if(word1[idx1] == word2[idx2]) ans = next[idx2+1];
                else ans = min(next[idx2]+1, cur[idx2+1]+1);
                cur[idx2] = ans;
            }
            next = cur;
        }
        return next[0];
    }
};

/*
Time complexity: O(N*M) where N is the length of word1 and M is the length of word2.
Space complexity: O(M)
*/