/*

34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

*/

#include<bits/stdc++.h>
using namespace std;

int getMinIndex(vector<int>& nums, int target){
    int low = 0, high = nums.size()-1, ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target) ans = mid;
        if(nums[mid] == target || nums[mid] > target) high = mid-1;
        else low = mid+1;
    }
    return ans;
}

int getMaxIndex(vector<int>& nums, int target){
    int low = 0, high = nums.size()-1, ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target) ans = mid;
        if(nums[mid] == target || nums[mid] < target) low = mid+1;
        else high = mid-1;
    }
    return ans;
}


vector<int> searchRange(vector<int>& nums, int target) {
    int mini = getMinIndex(nums, target);
    int maxi = getMaxIndex(nums, target);
    return {mini, maxi};
}

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> ans = searchRange(nums, target);
    cout<<"Printing the answer here "<<ans[0]<<" "<<ans[1]<<endl;
}

/*

Complexity analysis:

Time complexity: O(logN)+O(logN) = O(logN), where N is the number of elements present in the array.
Space complexity: O(1), we do not use any extra space, hence the space complexity is constant.

*/