/*

152. Maximum Product Subarray

Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Note that the product of an array with a single element is the value of that element.

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any subarray of nums is guaranteed to fit in a 32-bit integer.

*/

#include<bits/stdc++.h>
using namespace std;

int maxProduct1(vector<int>& nums) {
    int n = nums.size();
    int ans = *max_element(nums.begin(), nums.end());

    for(int i=0; i<n; i++){
        int ta = nums[i];
        for(int j=i+1; j<n; j++){
            ta *= nums[j];
            ans = max(ans, ta);
        }
    }
    return ans;
}

/*

Complexity analysis:

Time complexity: O(N^2), where N is the number of elements present in the array.
Space complexity: O(1), we do not use any extra space, hence the space complexity is constant.

*/


int maxProduct(vector<int>& nums) {
    int n = nums.size(), ans = INT_MIN, pp = 1, sp = 1;
    for(int i=0; i<n; i++){
        if(pp == 0) pp = 1;
        if(sp == 0) sp = 1;
        pp *= nums[i];
        sp *= nums[n-i-1];
        ans = max(ans, max(pp, sp));
    }
    return ans;
}

int main(){
    vector<int> nums = {-2,0,-1};
    int ans = maxProduct(nums);
    cout<<"Printing the answer here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(N), where N is the number of elements in the array.
Space complexity: O(1), we do not use any extra space, hence the space complexity is constant.

*/

