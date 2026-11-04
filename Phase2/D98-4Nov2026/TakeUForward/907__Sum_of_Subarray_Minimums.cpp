/*
907. Sum of Subarray Minimums
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;
        long long MOD = 1e9 + 7;
    
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        while(!st.empty()) {
            st.pop();
        }
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        long long total_sum = 0;
        for (int i = 0; i < n; ++i) {
            long long count = (long long)left[i] * right[i] % MOD;
            total_sum = (total_sum + count * arr[i]) % MOD;
        }
        
        return total_sum;
    }
};

/*
Time complexity: O(N), where N is the number of elements present in the given array.
Space complexity: O(N), where N is the number of elements present in the given array.
*/