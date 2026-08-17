/*
213. House Robber II
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size(), next1 = 0, next2 = 0;
        for(int idx=n-1; idx>=1; idx--){
            int ans = max(next2 + nums[idx], next1);
            next2 = next1;
            next1 = ans;
        }
        int ans1 = next1;

        next1 = 0, next2 = 0;
        for(int idx=n-2; idx>=0; idx--){
            int ans = max(next2 + nums[idx], next1);
            next2 = next1;
            next1 = ans;
        }
        int ans2 = next1;

        return max(ans1, ans2);
    }
};

/*
Time complexity: O(N), where N is the number of houses given (basically the size of the array)
Space complexity: O(1), we are not using any extra space, we are just using the varibales so our space complexity is constant.
*/