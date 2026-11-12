/*
1004. Max Consecutive Ones III
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length
*/

#include<bits/stdc++.h>
using namespace std;    

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0, high = 0, n = nums.size(), zeros = 0, ans = 0;
        while (high < n) {
            if (nums[high] == 0) zeros++;
            while (zeros > k) {
                if (nums[low] == 0) zeros--;
                low++;
            }
            ans = max(ans, high - low + 1);
            high++;
        }
        return ans;
    }
};

/*
Time complexity: O(N), where N is the number of elements in the nums array.
Space complexity: O(1).
*/