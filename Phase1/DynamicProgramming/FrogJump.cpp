// https://leetcode.com/problems/frog-jump/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<pair<int,int>, bool> dp;
    bool calc(set<int> &stones, int last_stone_position, int cur_position, int last_jump_size){
        if(dp.find({cur_position, last_jump_size}) != dp.end()){
            return dp[{cur_position, last_jump_size}];
        }
        if(cur_position == last_stone_position){
            return true;
        }

        else if(cur_position > last_stone_position){
            return false;
        }

        else if(cur_position < *min_element(stones.begin(), stones.end())){
            return false;
        }

        else if(stones.find(cur_position) == stones.end()){
            return false;
        }

        else if(last_jump_size == 0){
            int ans = calc(stones, last_stone_position, cur_position+1, 1);
            dp[{cur_position, last_jump_size}] = ans;
            return ans;
        }

        else{
            int ans =  (
                calc(stones, last_stone_position, cur_position+last_jump_size, last_jump_size) ||
                calc(stones, last_stone_position, cur_position+last_jump_size+1, last_jump_size+1) ||
                calc(stones, last_stone_position, cur_position+last_jump_size-1, last_jump_size-1)
            );
            dp[{cur_position, last_jump_size}] = ans;
            return ans;

        }
    }
    bool canCross(vector<int>& stones) {
        set<int> s;
        for(int i=0; i<stones.size(); i++){
            s.insert(stones[i]);
        }
        return calc(s, *max_element(stones.begin(), stones.end()), 0, 0);
    }
};