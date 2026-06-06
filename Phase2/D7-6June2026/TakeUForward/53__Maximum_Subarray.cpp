/*

53. Maximum Subarray

Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle

*/

#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int ps = nums[0], ans = ps, n = nums.size();
    for(int i=1; i<n; i++){
        ans = max(ans, ps);
        ps = max(nums[i], nums[i]+ps);
    }
    ans = max(ans, ps);
    return ans;
}

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = maxSubArray(nums);
    cout<<"Printing the max subarray sum here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(N), where N is the number of elements present in array.
Space complexity: O(1), we are just using a variable for store the ps, and hence the space complexity is constant.

*/