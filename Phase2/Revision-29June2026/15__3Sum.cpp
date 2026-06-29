/*
3 sum problem
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    unordered_map<int, int> s;
    for(int i=0; i<n; i++) s[nums[i]] = i;

    for(int i=0; i<n; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;

        for(int j=i+1; j<n; j++){
            if(j>i+1 && nums[j] == nums[j-1]) continue;

            int rsum = -1 * (nums[i] + nums[j]);
            if(s.count(rsum)){
                int idx = s[rsum];
                if(idx > j) ans.push_back({nums[i], nums[j], rsum});
            }
        }   
    }
}

int main(){
    vector<int> nums = {0,1,1};
    vector<vector<int>> ans = threeSum(nums);
    for(auto v: ans){
        for(auto e: v) cout<<e<<" ";
        cout<<endl;
    }
    cout<<endl;
}