/*
4 sum revision.
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    unordered_map<int, int> m; 
    vector<vector<int>> ans;
    for(int i=0; i<n; i++) m[nums[i]] = i;
    
    for(int i=0; i<n; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;

        for(int j=i+1; j<n; j++){
            if(j>i+1 && nums[j] == nums[j-1]) continue;

            for(int k=j+1; k<n; k++){
                if(k>j+1 && nums[k] == nums[k-1]) continue;
                long long req = (long long)target - nums[i] - nums[j] - nums[k];
                if (req >= INT_MIN && req <= INT_MAX){
                    if(m.count(req)){
                        int idx = m[req];
                        if(idx > k){
                            ans.push_back({nums[i], nums[j], nums[k], int(req)});
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums;
    int target;
    vector<vector<int>> ans = fourSum(nums, target);
    cout<<"Printing the answer here "<<endl;
    for(auto v: ans){
        for(auto e: v) cout<<e<<" ";
    }
    cout<<endl;
}