/*
Longest Increasing Subsequence

Given an array arr[] of non-negative integers, find the length of the Longest Strictly Increasing Subsequence (LIS). A subsequence is strictly increasing if each element in the subsequence is strictly less than the next element.

Examples:

Input: arr[] = [5, 8, 3, 7, 9, 1]
Output: 3
Explanation: The longest strictly increasing subsequence could be [5, 7, 9], which has a length of 3.
Input: arr[] = [10, 6, 3, 11, 7, 15]
Output: 3
Explanation: One of the possible longest strictly increasing subsequences is [10, 11, 15], which has a length of 3.
Input: arr[] = [3, 10, 2, 1, 20]
Output: 3
Explanation: The longest strictly increasing subsequence could be [3, 10, 20], which has a length of 3.
Constraints:

1 ≤ arr.size() ≤ 103
0 ≤ arr[i] ≤ 106
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lis(vector<int>& arr) {
        vector<int> tails;
        int n = arr.size();
        for(auto ele: arr){
            auto it = lower_bound(tails.begin(), tails.end(), ele);
            if(it == tails.end()) tails.push_back(ele);
            else *it = ele;
        }
        return tails.size();
    }
};

/*
Time complexity: O(NlogN), where N is the number of elements present in the array.
Space complexity: O(N), where N is the number of elements present in the array.
*/