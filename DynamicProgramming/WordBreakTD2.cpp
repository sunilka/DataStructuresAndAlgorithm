// https://leetcode.com/problems/word-break/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool calc(string &s, unordered_set<string> &word_dict, int start, vector<int>& dp){
        if(start >= s.size()){
            return true;
        }

        if(dp[start] != -1){
            return dp[start];
        }

        string temp = "";
        for(int i=start; i<s.size(); i++){
            temp = temp+s[i];
            if(word_dict.find(temp)!=word_dict.end()){
                if(calc(s, word_dict, i+1, dp)){
                    dp[start] = 1;
                    return true;
                }
            }
        }
        dp[start] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return calc(s, word_dict, 0, dp);
    }
};