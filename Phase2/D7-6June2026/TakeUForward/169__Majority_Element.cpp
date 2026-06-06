/*
169. Majority Element

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.


Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
The input is generated such that a majority element will exist in the array.
 

Follow-up: Could you solve the problem in linear time and in O(1) space?

*/

#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int ele = nums[0], c = 1, n = nums.size();
    for(int i=1; i<n; i++){
        if(nums[i] != ele){
            if(c == 0) ele = nums[i], c=1;
            else c-=1;
        }
        else c++;
    }
    return ele;
}

int main(){
    vector<int> nums = {3,2,3};
    int ans = majorityElement(nums);
    cout<<"Printing the majority element here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(N), where N is the number of elements that is present in the array.
Space complexity: O(1), we do not use any extra space, hence space complexity is constant. 

*/