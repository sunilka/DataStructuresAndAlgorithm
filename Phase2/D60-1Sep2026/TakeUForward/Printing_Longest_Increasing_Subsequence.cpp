/*
Printing Longest Increasing Subsequence
Problem Description: Given an array of n integers arr, return the Longest Increasing Subsequence (LIS) that is index-wise lexicographically smallest.
The Longest Increasing Subsequence (LIS) is the longest subsequence where all elements are in strictly increasing order. A subsequence A1 is index-wise lexicographically smaller than another subsequence A2 if, at the first position where A1 and A2 differ, the element in A1 appears earlier in the array than corresponding element in A2.
Examples
Input: arr = [10, 22, 9, 33, 21, 50, 41, 60, 80]
Output: [10, 22, 33, 50, 60, 80]
Explanation: The LIS is [10, 22, 33, 50, 60, 80] and it is the lexicographically smallest.
Input: arr = [1, 3, 2, 4, 6, 5]
Output: [1, 3, 4, 6] 
Explanation: Possible LIS sequences are [1, 3, 4, 6] and [1, 2, 4, 6]. Since [1, 3, 4, 6] is index-wise lexicographically smaller, it is the result.
*/

#include<bits/stdc++.h>
using namespace std;

void lis(vector<int>& arr) {
    int n = arr.size(), maxi_val = 1, maxi_index = 0;;
    vector<int> dp(n, 1), parent(n, -1);
    iota(parent.begin(), parent.end(), 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                if(dp[j]+1 > dp[i]) {
                    dp[i] = dp[j]+1;
                    parent[i] = j;
                }
            }
        }

        if(dp[i] > maxi_val){
            maxi_val = dp[i];
            maxi_index = i;
        }
    }

    vector<int> ans;
    int curr = maxi_index;
    while(parent[curr] != curr){
        ans.push_back(arr[curr]);
        curr = parent[curr];
    }
    ans.push_back(arr[curr]);
    reverse(ans.begin(), ans.end());
}

int main(){
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    lis(arr);
}

/*
Time complexity: O(N^2), where N is the number of elements present in the array.
Space complexity: O(N), for the parent and the DP array.
*/