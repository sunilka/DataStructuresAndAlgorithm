// https://www.geeksforgeeks.org/problems/geeks-training/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    map<pair<int, int>, int> dp;
    int calc(vector<vector<int>>& mat, int pos, int prev_done_activity_index){
        if(dp.find({pos, prev_done_activity_index})!=dp.end()){
            return dp[{pos, prev_done_activity_index}];
        }
        
        if(pos >= mat.size()){
            return 0;
        }
        
        else{
            int ans = INT_MIN;
            for(int i=0; i<3; i++){
                if(i!=prev_done_activity_index){
                    ans = max(ans, calc(mat, pos+1, i) + mat[pos][i]);
                }                
            }
            dp[{pos, prev_done_activity_index}] = ans;
            return ans;
        }
    }
    int maximumPoints(vector<vector<int>>& mat) {
        return calc(mat, 0, -1);
    }
};