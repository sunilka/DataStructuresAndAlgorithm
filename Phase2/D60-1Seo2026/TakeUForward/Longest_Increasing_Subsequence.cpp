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
        int n = arr.size();
        vector<int> dp(n, 1);
        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(arr[i] > arr[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

/*
Time complexity: O(N*N), where N is the number of elements present in the array arr. 
Space complexity: O(N) for the DP array.
*/

/*
Binary search solution.
*/

class Solution {
  public:
    int lis(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        ans.push_back(arr[0]);
        for(int i=1; i<n; i++){
            auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
            if(it!=ans.end()) *it = arr[i];
            else ans.push_back(arr[i]);
        }
        return ans.size();
    }
};

/*
Time complexity: O(N*logN), where N is the number of elements present in the given array.
Space complexity: O(N) for the answer array.
*/