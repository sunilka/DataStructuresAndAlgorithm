#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    map<pair<int, int>, int> dp;
    int calc(string s1, string s2, int pointer1, int pointer2){
        if(dp.find({pointer1, pointer2})!=dp.end()){
            return dp[{pointer1, pointer2}];
        }

        if(pointer1 >= s1.length()){
            return 0;
        }

        else if(pointer2 >= s2.length()){
            return 0;
        }

        else if(s1[pointer1] == s2[pointer2]){
            int ans = calc(s1, s2, pointer1+1, pointer2+1) + 1;
            dp[{pointer1, pointer2}] = ans;
            return ans;
        }

        else{
            int ans =  max(
                calc(s1, s2, pointer1+1, pointer2),
                calc(s1, s2, pointer1, pointer2+1)
            );
            dp[{pointer1, pointer2}] = ans;
            return ans;
        }
    }
    int longestCommonSubsequence(string s1, string s2) {
        return calc(s1, s2, 0, 0);
    }
};