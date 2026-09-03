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
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    int solve(string& s, int i, int n) {
        if (i >= n) return 0;
        if (isPalindrome(s, i, n - 1)) return 0;
        int mini = INT_MAX;
        for (int k = i; k < n; k++) {
            if (isPalindrome(s, i, k)) {
                int ans = 1 + solve(s, k + 1, n);
                mini = min(mini, ans);
            }
        }
        return mini;
    }

    int minCut(string s) {
        int n = s.size();
        return solve(s, 0, n);
    }
};

/*
Time complexity: O(2^N*N), where N is the number of characters in the given string.
Space complexity: O(N) auxiliary stack space.
*/

/*
Top down memoization solution.
*/

class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    int solve(string& s, int i, int& n, vector<int>& dp) {
        if (i >= n) return 0;
        if (isPalindrome(s, i, n - 1)) return 0;
        if(dp[i]!=-1) return dp[i];
        int mini = INT_MAX;
        for (int k = i; k < n; k++) {
            if (isPalindrome(s, i, k)) {
                int ans = 1 + solve(s, k + 1, n, dp);
                mini = min(mini, ans);
            }
        }
        return dp[i] = mini;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return solve(s, 0, n, dp);
    }
};

/*
Time complexity: O(N*N), where N is the number of characters present in the given string.
Space complexity: O(N) for the DP array and O(N) for the auxiliary stack space.
*/

/*
Bottom up - tabulation method.
*/

class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            if(isPalindrome(s, i, n - 1)){
                dp[i] = 0;
                continue;
            }
            int mini = INT_MAX;
            for (int k = i; k < n; k++) {
                if (isPalindrome(s, i, k)) {
                    int ans = 1 + dp[k + 1];
                    mini = min(mini, ans);
                }
            }
            dp[i] = mini;
        }
        return dp[0];
    }   
};

/*
Time complexity: O(N*N) where N is the number of characters present in the given string.
Space complexity: O(N) for the DP array and please note that we do not use any auxiliary stack space here.
*/