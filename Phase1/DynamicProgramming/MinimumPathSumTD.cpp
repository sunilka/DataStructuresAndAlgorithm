// https://leetcode.com/problems/minimum-path-sum/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<pair<int, int>, int> dp;
    int calc(vector<vector<int>> &grid, int cur_x, int cur_y){
        if(dp.find({cur_x, cur_y}) != dp.end()){
            return dp[{cur_x, cur_y}];
        }

        if(cur_x == grid.size()-1 && cur_y == grid[0].size()-1){
            return grid[cur_x][cur_y];
        }

        else if(cur_x <0 || cur_x >= grid.size() || cur_y <0 || cur_y >= grid[0].size()){
            return INT_MAX-7000;
        }

        else{
            int ans = min(
                calc(grid, cur_x + 1, cur_y) + grid[cur_x][cur_y],
                calc(grid, cur_x, cur_y+1)+ grid[cur_x][cur_y]
            );
            dp[{cur_x, cur_y}] = ans;
            return ans;
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        return calc(grid, 0, 0);
    }
};