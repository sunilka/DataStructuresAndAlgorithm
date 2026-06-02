/*

283. Move Zeroes

Hint
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?

*/

#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size(), p = 0;
    for(int i=0; i<n; i++){
        if(nums[i]!=0){
            nums[p] = nums[i];
            p++;
        }
    }

    // make all elements after p to be 0s
    for(int i=p; i<n; i++) nums[i] = 0;
}

int main(){
    vector<int> nums = {0};
    moveZeroes(nums);
    cout<<"Printing the answer array "<<endl;
    for(auto ele: nums) cout<<ele<<" ";
} 

/*
Complexity analysis:

Time complexity: O(N), where N is the number of elements that are present in the array.
Space complexity: O(1), no extra space used. Hence the space complexity is constant.

*/