/*
Partitions with Given Difference

Given an array arr[] and an integer diff, count the number of ways to partition the array into two subsets such that the difference between their sums is equal to diff.

Note: A partition in the array means dividing an array into two subsets say S1 and S2 such that the union of S1 and S2 is equal to the original array and each element is present in only one of the subsets.

Examples :

Input: arr[] = [5, 2, 6, 4], diff = 3
Output: 1
Explanation: There is only one possible partition of this array. Partition : [6, 4], [5, 2]. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.
Input: arr[] = [1, 1, 1, 1], diff = 0 
Output: 6 
Explanation: We can choose two 1's from indices [0,1], [0,2], [0,3], [1,2], [1,3], [2,3] and put them in sum1 and remaning two 1's in sum2.
Thus there are total 6 ways for partition the array arr. 
Input: arr[] = [3, 2, 7, 1], diff = 4  
Output: 0
Explanation: There is no possible partition of the array that satisfy the given difference. 
Constraint:
1 ≤ arr.size() ≤ 50
0 ≤ diff ≤ 50
0 ≤ arr[i] ≤ 6
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(vector<int>& arr, int& n, int& diff, int& tot_sum, int idx, int s1sum, vector<vector<int>>& dp){
        if(idx >= n){
            int s2sum = tot_sum - s1sum;
            if(s1sum - s2sum == diff) return 1;
            return 0;
        }
        if(dp[idx][s1sum]!=-1) return dp[idx][s1sum];
        int notake = solve(arr, n, diff, tot_sum, idx+1, s1sum, dp);
        int take = solve(arr, n, diff, tot_sum, idx+1, s1sum+arr[idx], dp);
        return dp[idx][s1sum] = (take + notake);
    }
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size(), tot_sum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(n+1, vector<int>(tot_sum+1, -1));
        return solve(arr,n, diff, tot_sum, 0, 0, dp);
    }
};

/*
Time complexity: O(N*tot_sum), where N is the number of elements present in the array and tot_sum is the total sum 
of all the elements present in the array.
Space complexity: O(N*tot_sum) for the DP array and O(N) auxiliary stack space.
*/

/*
Bottom up DP - tabulation method.
*/

class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size(), tot_sum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(n+1, vector<int>(tot_sum+1, 0));
        for(int s1sum=0; s1sum<=tot_sum; s1sum++){
            int s2sum = tot_sum - s1sum;
            if(s1sum - s2sum == diff) dp[n][s1sum] = 1;
        }
        
        for(int idx=n-1; idx>=0; idx--){
            for(int s1sum=tot_sum; s1sum>=0; s1sum--){
                int notake = dp[idx+1][s1sum];
                int take = dp[idx+1][s1sum+arr[idx]];
                dp[idx][s1sum] = (take + notake);
            }
        }
        
        return dp[0][0];
    }
};

/*
Time complexity: O(N*tot_sum), where N is the number of elements present in the array and tot_sum is the total sum 
of all the elements present in the array.
Space complexity: O(N*tot_sum) for the DP array and please note here that we are not using any auxiliary space here.
*/

/*
Space optimization code.
*/

class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size(), tot_sum = accumulate(arr.begin(), arr.end(), 0);
        vector<int> cur(tot_sum+1, 0), next(tot_sum+1, 0);
        for(int s1sum=0; s1sum<=tot_sum; s1sum++){
            int s2sum = tot_sum - s1sum;
            if(s1sum - s2sum == diff) next[s1sum] = 1;
        }
        for(int idx=n-1; idx>=0; idx--){
            for(int s1sum=tot_sum; s1sum>=0; s1sum--){
                int s2sum = tot_sum - s1sum;
                int notake = next[s1sum];
                int take = next[s1sum+arr[idx]];
                cur[s1sum] = (take + notake);
            }
            next = cur;
        }
        
        return next[0];
    }
};