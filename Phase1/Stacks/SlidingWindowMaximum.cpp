// https://leetcode.com/problems/sliding-window-maximum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq; // this priority queue is going to have pair < element, index >
        vector<int> ans;
        for(int i=0; i<k; i++){
            pq.push({nums[i], i});
        }
        for(int i=k; i<nums.size()+1; i++){
            int start_index = i-k; 
            int end_index = i-1; 
            while(pq.top().second>end_index || pq.top().second<start_index){
                pq.pop();
            }
            ans.push_back(pq.top().first);
            if(i<nums.size()){
                pq.push({nums[i], i});
            }
        }
        return ans;
    }
};