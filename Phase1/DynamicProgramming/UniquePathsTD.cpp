// https://leetcode.com/problems/unique-paths/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<pair<int, int>, int> dp;
    int calc(int m, int n, int cur_x, int cur_y){
        if(dp.find({cur_x, cur_y})!=dp.end()){
            return dp[{cur_x, cur_y}];
        }

        if(cur_x == m-1 && cur_y == n-1){
            return 1;
        }

        else if(cur_x < 0 || cur_x >= m || cur_y < 0 || cur_y >= n){
            return 0;
        }

        else{
            int ans1 = calc(m, n, cur_x+1, cur_y);
            int ans2 = calc(m, n, cur_x, cur_y+1);
            int ans = ans1 + ans2;
            dp[{cur_x, cur_y}] = ans;
            return ans;
        }

    }
    int uniquePaths(int m, int n) {
        return calc(m, n, 0, 0);
    }
};