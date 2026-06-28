/*
Longest subarray with given sum K.
*/

#include<bits/stdc++.h>
using namespace std;

int longestSubarray2(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int sum = 0, n = nums.size(), ans = INT_MIN;
    for(int i=0; i<n; i++){
        sum += nums[i];
        if(sum == k) ans = max(ans, i+1);
        int req = sum - k;
        if(m.find(req) != m.end()) ans = max(ans, abs(m[req] - i));
        if(m.find(sum) == m.end()) m[sum] = i;
    }
    return ans == INT_MIN? 0: ans;
}

// Since the elements that are given to us are positive, we know that we we 
// reach a point when the sum we are carrying becomes greater than the needed sum
// k, then we will have to just remove elements that we have taken.
// Since, this a question where we have to find the sub-array sum, it is know
// that we have to keep the concept of window here. 
int longestSubarray(vector<int>& nums, int k) {
    int left = 0, right = 0, n = nums.size(), ans = 0, sum = 0;
    
    while(right<n){
        sum+=nums[right];

        while(left<=right && sum>k){
            sum-=nums[left];
            left++;
        }

        if(sum == k) ans = max(ans, right-left+1);
        right++;
    }
    return ans;
}

int main(){
    vector<int> nums = {10, 5, 2, 7, 1, -10};
    int k=15;
    int ans = longestSubarray(nums, k);
    cout<<"Printing my answer here "<<ans<<endl;
}

