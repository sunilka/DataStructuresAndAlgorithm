/*
Count the number of subarrays with the given xor k.
*/

#include<bits/stdc++.h>
using namespace std;

int calculateXORs(vector<int>& nums, int k){
    unordered_map<int, int> m;
    m[0] = 1;
    int rpx = 0, ans = 0;
    for(auto num: nums){
        rpx = num^rpx;
        int target = k^rpx;
        if(m.count(target)) ans += m[target];
        m[rpx]++;
    }
    return ans;
}

int main(){
    vector<int> nums;
    int k;
    int ans = calculateXORs(nums, k);
    cout<<"Printing the answer here "<<ans<<endl;
}