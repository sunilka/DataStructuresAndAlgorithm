// https://leetcode.com/problems/top-k-frequent-elements/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]+=1;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it: m){
            pq.push({it.second, it.first});
        }

        vector<int> ans;
        while(k--){
            pair<int, int> ele = pq.top();
            ans.push_back(ele.second);
            pq.pop();
        }
        return ans;
    }
};