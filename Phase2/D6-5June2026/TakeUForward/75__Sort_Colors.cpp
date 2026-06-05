/*

75. Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?

*/

#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int z=0, o=0, t=0;
    for(auto ele: nums){
        if(ele == 0) z++;
        else if(ele == 1) o++;
        else t++;
    }
    int index = 0;
    for(int i=0; i<z; i++) nums[index++] = 0;
    for(int j=0; j<o; j++) nums[index++] = 1;
    for(int k=0; k<t; k++) nums[index++] = 2;
}

int main(){
    vector<int> nums ={2,0,2,1,1,0};
    sortColors(nums);
    cout<<"Printing the answer here "<<endl;
    for(auto ele: nums) cout<<ele<<" ";
    cout<<endl;
}


/*

Complexity analysis:

Time complexity: O(N), where N is the number of elements present in the array.
Space complexity: O(1), we are using just 3 variables, so space is constant. 

*/