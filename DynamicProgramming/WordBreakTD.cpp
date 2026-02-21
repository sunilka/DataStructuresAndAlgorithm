// https://leetcode.com/problems/word-break/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<pair<int, string> , bool> dp;
    bool calc(string s, string cur_string, int pos, set<string> wordDict){
        if(dp.find({pos, cur_string}) != dp.end()){
            return dp[{pos, cur_string}];
        }
        
        if(pos >= s.length()){
            if(cur_string != ""){
                if(wordDict.find(cur_string) == wordDict.end()){
                    return false;
                }
                else{
                    return true;
                }
            }
            return false;
        }
        else if(cur_string == ""){
            int ans = calc(s, cur_string+s[pos], pos+1, wordDict);
            dp[{pos, cur_string}] = ans;
            return ans;
        }

        else if(wordDict.find(cur_string) != wordDict.end()){
            int ans = calc(s, "", pos, wordDict) || calc(s, cur_string+s[pos], pos+1, wordDict);
            dp[{pos, cur_string}] = ans;
            return ans;
        }
        else{
            int ans = calc(s, cur_string+s[pos], pos+1, wordDict);
            dp[{pos, cur_string}] = ans;
            return ans;
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> word_dict;
        for(auto it: wordDict){
            word_dict.insert(it);
        }
        return calc(s, "", 0, word_dict);
    }
};