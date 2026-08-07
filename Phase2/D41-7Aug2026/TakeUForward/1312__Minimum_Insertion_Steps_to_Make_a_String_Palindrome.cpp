/*
1312. Minimum Insertion Steps to Make a String Palindrome

Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string& s, int idx1, int idx2, vector<vector<int>>& dp){
        if(idx1 > idx2) return 0;
        if(idx1 == idx2) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s[idx1] == s[idx2]){
            int ans = solve(s, idx1+1, idx2-1, dp);
            dp[idx1][idx2] = ans;
            return ans;
        }
        else{
            int ans = min(
                solve(s, idx1+1, idx2, dp)+1,
                solve(s, idx1, idx2-1, dp)+1
            );
            dp[idx1][idx2] = ans;
            return ans;
        }
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(s, 0, n-1, dp);
    }
};

/*
Time complexity: O(N*N)
Space complexity: O(N*N)+(N+N) aux space.
*/

/*
Bottom up approach
*/
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int idx1=n-1; idx1>=0; idx1--){
            for(int idx2=idx1+1; idx2<n; idx2++){
                if(s[idx1] == s[idx2]){
                    int ans = dp[idx1+1][idx2-1];
                    dp[idx1][idx2] = ans;
                }
                else{
                    int ans = min(dp[idx1+1][idx2]+1, dp[idx1][idx2-1]+1);
                    dp[idx1][idx2] = ans;
                }
            }
        }
        return dp[0][n-1];
    }
};

/*
Time complexity: O(N*N)
Space complexity: O(N*N)
*/

/*
Space optimized
*/

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<int> cur(n+1, 0), next(n+1, 0);
        for(int idx1=n-1; idx1>=0; idx1--){
            for(int idx2=idx1+1; idx2<n; idx2++){
                if(s[idx1] == s[idx2]){
                    int ans = next[idx2-1];
                    cur[idx2] = ans;
                }
                else{
                    int ans = min(next[idx2]+1, cur[idx2-1]+1);
                    cur[idx2] = ans;
                }
            }
            next = cur;
        }
        return next[n-1];
    }
};

/*
Time complexity: O(N*N)
Space complexity: O(N*N)
*/