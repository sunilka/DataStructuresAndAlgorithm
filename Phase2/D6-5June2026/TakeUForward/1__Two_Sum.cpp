/*

1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    vector<int> ans;
    int n = nums.size();
    for(int i=0; i<n; i++){
        int t = target - nums[i];
        if(m.count(t)){
            ans.push_back(i);
            ans.push_back(m[t]);
        }
        m[nums[i]] = i;
    }
    return ans;
}

int main(){
    vector<int> nums = {3,3};
    int target = 6;

    vector<int> ans = twoSum(nums, target);
    cout<<"Printing the answer here "<<endl;
    for(auto ele: ans) cout<<ele<<" ";
    cout<<endl;
}

/*
Complexity Analysis:

Time complexity: O(N) where N is the number of elements present in the array.
Space complexity: O(N) where N is the number of elements present in the array. 

*/