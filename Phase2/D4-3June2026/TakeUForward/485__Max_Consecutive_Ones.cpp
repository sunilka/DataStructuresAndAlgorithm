/*

485. Max Consecutive Ones

Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {1,0,1,1,0,1};
    int cs = 0, p = 0, n = nums.size(), ans = INT_MIN;
    while(p<n){
        ans = max(ans, cs);
        if(nums[p] == 1) cs += 1;
        else cs = 0;
        p++;
    }
    ans = max(cs, ans);
    cout<<"printing the answer here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(N) where N represents the number of elements in the array.
Space complexity: O(1), constant space, we do not use any extra space.

*/