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
    int solve(string &s, int i, int j){
        if(i>=j) return 0;
        if(s[i] == s[j]) return solve(s, i+1, j-1);
        int ans = min(solve(s, i+1, j)+1, solve(s, i, j-1)+1);
        return ans;
    }
    int minInsertions(string s) {
        int n = s.size();
        return solve(s, 0, n-1);
    }
};

/*
Time complexity: O(2^(N)), where N is the number of characters present in the given string.
Space complexity: O(N) auxiliary stack space.
*/

/*
Top down memoization solution.
*/

class Solution {
public:
    int solve(string &s, int i, int j, vector<vector<int>>& dp){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] = solve(s, i+1, j-1, dp);
        int ans = min(solve(s, i+1, j, dp)+1, solve(s, i, j-1, dp)+1);
        return dp[i][j] = ans;
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(s, 0, n-1, dp);
    }
};

/*
Time complexity: O(N*N) = O(N^2), where N is the number of characters present in the given string.
Space complexity: O(N*N) for the DP array and O(N) auxiliary stack space.
*/


/*
Bottom up - tabulation method
*/

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                int ans;
                if(s[i] == s[j]) ans = dp[i+1][j-1];
                else ans = min(dp[i+1][j]+1, dp[i][j-1]+1);
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }
};

/*
Time complexity: O(N*N) = O(N^2), where N is the number of characters present in the given string.
Space complexity: O(N*N) for the DP array and please note that there is not auxiliary stack space involved here. 
*/

/*
Space optimization code.
*/

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<int> cur(n+1, 0), next(n+1, 0);
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                int ans;
                if(s[i] == s[j]) ans = next[j-1];
                else ans = min(next[j]+1, cur[j-1]+1);
                cur[j] = ans;
            }
            next = cur;
        }
        return next[n-1];
    }
};

/*
Time complexity: O(N*N) = O(N^2), where N is the number of characters present in the given string.
Space complexity: O(N) for the DP array and please note that there is not auxiliary stack space involved here. 
*/
