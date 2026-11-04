/*
2104. Sum of Subarray Ranges
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
Example 2:

Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.
 

Constraints:

1 <= nums.length <= 1000
-109 <= nums[i] <= 109
 

Follow-up: Could you find a solution with O(n) time complexity?
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long min_sum = 0;
        vector<int> left_min(n), right_min(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            left_min[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            right_min[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        vector<int> left_max(n), right_max(n);
        while(!st.empty()) st.pop();
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            left_max[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            right_max[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        long long total_range_sum = 0;
        for(int i = 0; i < n; i++) {
            long long max_count = (long long)left_max[i] * right_max[i];
            long long min_count = (long long)left_min[i] * right_min[i];
            
            total_range_sum += (max_count - min_count) * nums[i];
        }
        return total_range_sum;
    }
};

/*
Time complexity: O(N), where N is the number of elements present in the given array.
Space complexity: O(N)
*/