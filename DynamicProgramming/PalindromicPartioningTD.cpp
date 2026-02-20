// https://leetcode.com/problems/palindrome-partitioning/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPlaindrome(string s){
        string temps = s;
        reverse(temps.begin(), temps.end());
        return s == temps;
    }

    void calc(string s, vector<vector<string>> &ans, vector<string> running_ans, string running_string, int pos){
        if(pos == s.size()){
            if(running_string != "" && isPlaindrome(running_string)){
                running_ans.push_back(running_string);
                ans.push_back(running_ans);
            }
            return;
        }

        if(running_string == ""){
            running_string += s[pos];
            calc(s, ans, running_ans, running_string, pos+1);
        }
        else{
            if(isPlaindrome(running_string)){
                calc(s, ans, running_ans,running_string + s[pos], pos+1);
                running_ans.push_back(running_string);
                string temp_running_string(1, s[pos]);  
                calc(s, ans, running_ans,
                     temp_running_string, pos+1);
            }
            else{
                calc(s, ans, running_ans, running_string + s[pos], pos+1);
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> running_ans;
        calc(s, ans, running_ans, "", 0);
        return ans;
    }
};