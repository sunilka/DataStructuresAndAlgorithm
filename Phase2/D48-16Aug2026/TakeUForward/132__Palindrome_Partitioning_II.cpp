/*
132. Palindrome Partitioning II
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1
 

Constraints:

1 <= s.length <= 2000
s consists of lowercase English letters only.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string& s, int i, int j){
        while(i<j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    int solve(string& s, int i, int j, vector<vector<int>>& dp){
        if(i>=j || isPalindrome(s, i, j)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = INT_MAX;
        for(int k=i; k<j; k++){
            if(isPalindrome(s, i, k)){
                int ans = solve(s, k+1, j, dp)+1;
                mini = min(mini, ans);
            }
        }
        dp[i][j] = mini;
        return mini;
    }
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(s, 0, n-1, dp);
    }
};

/*
Time complexity: O(N^4)
Space complexity: O(N^2)+O(N)aux space.
*/


class Solution {
public:
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    int solve(string &s, int n, int start, vector<int>& dp){
        if(start == n || isPalindrome(s, start, n-1)) return 0;
        if(dp[start]!=-1) return dp[start];
        int mini = INT_MAX;
        for(int end=start; end<n; end++){
            if(isPalindrome(s, start, end)){
                int ans = solve(s, n, end+1, dp) + 1;
                mini = min(ans, mini);
            }
        }
        dp[start] = mini;
        return mini;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return solve(s, n, 0, dp);
    }
};

/*
Time complexity: O(N^3)
Space complexity: O(N)aux space.
*/

/*
Bottom up DP.
*/

class Solution {
public:
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        for(int start=n-1; start>=0; start--){
            if(isPalindrome(s, start, n-1)){
                dp[start] = 0;
                continue;
            }
            int mini = INT_MAX;
            for(int end=start; end<n; end++){
                if(isPalindrome(s, start, end)){
                    int ans = dp[end+1] + 1;
                    mini = min(ans, mini);
                }
            }
            dp[start] = mini;
        }
        return dp[0];
    }
};

/*
Time complexity: O(N^3)
Space complexity: O(N)
*/