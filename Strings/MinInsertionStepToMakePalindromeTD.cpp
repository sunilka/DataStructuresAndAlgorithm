// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<pair<int, int>, int> dp;
    int calc(const string &s, int left, int right){
        if(dp.find({left, right}) != dp.end()){
            return dp[{left, right}];
        }

        if(left >= right){
            return 0;
        }

        if(s[left] == s[right]){
            return dp[{left, right}] = calc(s, left+1, right-1);
        }

        return dp[{left, right}] = 1 + min(
            calc(s, left+1, right),
            calc(s, left, right-1)
        );
    }

    int minInsertions(string s) {
        dp.clear();
        return calc(s, 0, s.size()-1);
    }
};