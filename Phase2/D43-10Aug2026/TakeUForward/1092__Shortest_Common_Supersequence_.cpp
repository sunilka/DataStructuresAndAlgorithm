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
    int solve(string &str1, string &str2, int n1, int n2, int idx1, int idx2, vector<vector<int>>& dp){
        if(idx1 >= n1 || idx2 >= n2) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(str1[idx1] == str2[idx2]){
            int ans = solve(str1, str2, n1, n2, idx1+1, idx2+1, dp)+1;
            dp[idx1][idx2] = ans;
            return ans;
        }
        int ans = max(
            solve(str1, str2, n1, n2, idx1+1, idx2, dp),
            solve(str1, str2, n1, n2, idx1, idx2+1, dp)
        );
        dp[idx1][idx2] = ans;
        return ans;
    }
    void _print(vector<vector<int>>& dp, int n1, int n2){
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        int lcs = solve(str1, str2, n1, n2, 0, 0, dp);
        auto getDP = [&](int r, int c) {
            if (r >= n1 || c >= n2 || dp[r][c] == -1) return 0;
            return dp[r][c];
        };
        string scs = "";
        int i=0, j=0;
        while(i<n1 && j<n2){
            if(str1[i] == str2[j]){
                scs+=str1[i];
                i++, j++;
            }
            else{
                int move_i = getDP(i + 1, j);
                int move_j = getDP(i, j + 1);

                if (move_i >= move_j) {
                    scs += str1[i];
                    i++;
                } else {
                    scs += str2[j];
                    j++;
                }
            }
        }

        while (i < n1) scs += str1[i++];
        while (j < n2) scs += str2[j++];
        return scs;
    }   
};

/*
Time complexity: O(N*M), where N is the length of str1 and M is the lenght of str2.
Space complexity: O(N*M)+(N+M)aux space.
*/

/*
Bottom up DP.
*/

class Solution {
public:
    int solve(string &str1, string &str2, int n1, int n2, int idx1, int idx2, vector<vector<int>>& dp){
        if(idx1 >= n1 || idx2 >= n2) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(str1[idx1] == str2[idx2]){
            int ans = solve(str1, str2, n1, n2, idx1+1, idx2+1, dp)+1;
            dp[idx1][idx2] = ans;
            return ans;
        }
        int ans = max(
            solve(str1, str2, n1, n2, idx1+1, idx2, dp),
            solve(str1, str2, n1, n2, idx1, idx2+1, dp)
        );
        dp[idx1][idx2] = ans;
        return ans;
    }
    void _print(vector<vector<int>>& dp, int n1, int n2){
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int idx1=n1-1; idx1>=0; idx1--){
            for(int idx2=n2-1; idx2>=0; idx2--){
                int ans;
                if(str1[idx1] == str2[idx2])ans = dp[idx1+1][idx2+1]+1;
                else ans = max(dp[idx1+1][idx2], dp[idx1][idx2+1]);
                dp[idx1][idx2] = ans;
            }
        }
        
        auto getDP = [&](int r, int c) {
            if (r >= n1 || c >= n2 || dp[r][c] == -1) return 0;
            return dp[r][c];
        };
        string scs = "";
        int i=0, j=0;
        while(i<n1 && j<n2){
            if(str1[i] == str2[j]){
                scs+=str1[i];
                i++, j++;
            }
            else{
                int move_i = getDP(i + 1, j);
                int move_j = getDP(i, j + 1);

                if (move_i >= move_j) {
                    scs += str1[i];
                    i++;
                } else {
                    scs += str2[j];
                    j++;
                }
            }
        }

        while (i < n1) scs += str1[i++];
        while (j < n2) scs += str2[j++];
        return scs;
    }   
};

/*
Time complexity: O(N*M), where N is the length of str1 and M is the lenght of str2.
Space complexity: O(N*M).
*/