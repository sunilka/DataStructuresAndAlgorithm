/*
Longest Bitonic Subsequence
Given an array of positive integers. Find the maximum length of Bitonic subsequence.  A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing. Return the maximum length of bitonic subsequence.
 
Note : A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence

Examples :

Input: n = 5, nums[] = [1, 2, 5, 3, 2]
Output: 5
Explanation: The sequence [1, 2, 5] is increasing and the sequence [3, 2] is decreasing so merging both we will get length 5.
Input: n = 8, nums[] = [1, 11, 2, 10, 4, 5, 2, 1]
Output: 6
Explanation: The bitonic sequence [1, 2, 10, 4, 2, 1] has length 6.
Input: n = 3, nums[] = [10, 20, 30]
Output: 0
Explanation: The decreasing or increasing part cannot be empty.
Input: n = 3, nums[] = [10, 10, 10]
Output: 0
Explanation: No strictly increasing or decreasing sequence exists.
Constraints:
1 ≤ length of array ≤ 103
1 ≤ arr[i] ≤ 104
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        vector<int> increasing(n, 1), decreasing(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i] && increasing[i] < increasing[j] + 1) increasing[i] = increasing[j] + 1;
            }
        }
        
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(nums[j] < nums[i] && decreasing[i] < decreasing[j] + 1) decreasing[i] = decreasing[j] + 1;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (increasing[i] > 1 && decreasing[i] > 1) {
                ans = max(ans, increasing[i] + decreasing[i] - 1);
            }
        }
        return ans;
    }
};


/*
Time complexity: O(N^2), where N is the number of elements present in the array.
Space complexity: O(N)
*/