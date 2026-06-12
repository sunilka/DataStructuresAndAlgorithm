/*

18. 4Sum

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

*/


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    unordered_map<int, int> m;
    vector<vector<int>> ans;
    int n = nums.size();
    for(int i=0; i<n; i++) m[nums[i]] = i;

    for(int i=0; i<n; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;

        for(int j=i+1; j<n; j++){
            if(j>i+1 && nums[j] == nums[j-1]) continue;

            for(int k=j+1; k<n; k++){
                if(k>j+1 && nums[k] == nums[k-1]) continue;

                long long remaining = (long long)target - nums[i] - nums[j] - nums[k];
                if (remaining >= INT_MIN && remaining <= INT_MAX) {
                    int rsum = (int)remaining;
                    if(m.count(rsum) && m[rsum] > k) {
                        ans.push_back({nums[i], nums[j], nums[k], rsum});
                    }
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {2,2,2,2,2}; 
    int target=8;
    vector<vector<int>> ans = fourSum(nums, target);
    cout<<"Printing the answer here "<<endl;
    for(auto ele: ans){
        for(auto e: ele) cout<<e<<" ";
        cout<<endl;
    }
}

/*

Complexity analysis:

Time complexity: O(NlogN + N^3) = O(N^3), where N is the number of elements present in the array.
Space complexity: O(N), we are using extra space for storing the elements in the unordered map. 

*/