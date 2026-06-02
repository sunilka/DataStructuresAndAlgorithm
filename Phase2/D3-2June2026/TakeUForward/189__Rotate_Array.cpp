/*
189. Rotate Array

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?

*/

#include<bits/stdc++.h>
using namespace std;

// Method 1: Pure stimulation code.
void pure_stimulation_code(vector<int>& nums, int k){
    int n = nums.size();
    k = k % n;
    // Pure stimulation code.
    while(k--){
        int lele = nums[n-1];
        nums.insert(nums.begin(), lele);
        nums.pop_back();
    }
}

/*

Complexity analysis:

Time complexity: O(k*n), where K is the number of time we need to rotate and N is the number of elements present inside the array.
Space complexity: O(n), constant space.

*/


// Method 2
void rotate_by_using_extra_space(vector<int>& nums, int k){
    int n = nums.size();
    k = k%n;
    vector<int> dans(n, 0);
    for(int i=0; i<n; i++){
        int nidx = (i+k)%n;
        dans[nidx] = nums[i];
    }

    // Override the values of nums
    for(int i=0; i<nums.size(); i++) nums[i] = dans[i];
}

/* 

Analysis of the time and space complexity of this:

1) Time complexity : O(N), where N is the number of elements present in the array.
2) Space complexity: O(N), where N is the number of elements present in the array.

*/

void print_array(vector<int>& nums){
    cout<<"Printing here of debugging "<<endl;
    for(auto ele: nums) cout<<ele<<" ";
    cout<<endl;
}

// Method 3: Without using extra space
void rotate(vector<int>& nums, int k){
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());
}

/*
Complexity anaylsis:

Time complexity: O(N), where N is the number of elements present in the array, cause the reverse operation takes O(N) time.
Space complexity: O(1), constant space. 

*/


int main(){
    vector<int> nums ={1,2,3,4,5,6,7};
    int k = 3; 
    rotate(nums, k);

    cout<<"Printing the rotated array "<<endl;
    for(auto ele: nums) cout<<ele<<" ";
    cout<<endl;
}