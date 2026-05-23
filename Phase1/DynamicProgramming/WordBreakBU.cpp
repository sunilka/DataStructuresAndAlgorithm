// https://leetcode.com/problems/word-break/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true; 

        for(int start = n - 1; start >= 0; start--) {
            string temp = "";
            for(int i = start; i < n; i++) {
                temp += s[i];
                if(word_dict.count(temp) && dp[i + 1]) {
                    dp[start] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};