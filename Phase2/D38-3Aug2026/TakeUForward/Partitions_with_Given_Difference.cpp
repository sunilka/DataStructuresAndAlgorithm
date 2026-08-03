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
    int solve(vector<int>& arr, int diff, int tsum, int s1sum, int idx, vector<vector<int>>& dp){
        int n = arr.size();
        if(idx>=n){
            int s2sum = tsum - s1sum;
            if(s1sum - s2sum == diff) return 1;
            return 0;
        }
        if(dp[idx][s1sum] != -1) return dp[idx][s1sum];
        int take = 0;
        if(s1sum >=0){
            take = solve(arr, diff, tsum, s1sum-arr[idx], idx+1, dp);
        }
        int notake = solve(arr, diff, tsum, s1sum, idx+1, dp);
        int ans = take + notake;
        dp[idx][s1sum] = ans;
        return ans;
    }
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int tsum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(n+1, vector<int>(tsum+1, -1));
        return solve(arr, diff, tsum, tsum, 0, dp);
    }
};
/*
Time complexity: O(N*T), where N is the total number of elements present in the array and T is the total sum of the
elements present in the array.
Space complexity:  O(N*T) for DP array and O(N) aux space, where N is the total number of elements present in the array and 
T is the total sum of the elements present in the array.
*/

/*
Bottom up DP.
*/

class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int tsum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(n+1, vector<int>(tsum+1, 0));
        for(int j=tsum; j>=0; j--){
            int s1sum = j;
            int s2sum = tsum - s1sum;
            if(s1sum - s2sum == diff) dp[n][j] = 1;
        }
        
        for(int idx=n-1; idx>=0; idx--){
            for(int s1sum=tsum; s1sum>=0; s1sum--){
                int take = 0;
                if(s1sum - arr[idx] >=0){
                    take = dp[idx+1][s1sum-arr[idx]];
                }
                int notake = dp[idx+1][s1sum];
                int ans = take + notake;
                dp[idx][s1sum] = ans;
            }
        }
        return dp[0][tsum];
    }
};

/*
Time complexity: O(N*T), where N is the total number of elements present in the array and T is the total sum of the
elements present in the array.
Space complexity:  O(N*T) for DP array, where N is the total number of elements present in the array and 
T is the total sum of the elements present in the array.
*/

/*
Space optimized
*/
class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int tsum = accumulate(arr.begin(), arr.end(), 0);
        vector<int> next(tsum+1, 0);
        vector<int> cur(tsum+1, 0);
        for(int j=tsum; j>=0; j--){
            int s1sum = j;
            int s2sum = tsum - s1sum;
            if(s1sum - s2sum == diff) next[j] = 1;
        }
        
        for(int idx=n-1; idx>=0; idx--){
            for(int s1sum=tsum; s1sum>=0; s1sum--){
                int take = 0;
                if(s1sum - arr[idx] >=0){
                    take = next[s1sum-arr[idx]];
                }
                int notake = next[s1sum];
                int ans = take + notake;
                cur[s1sum] = ans;
            }
            next = cur;
        }
        return next[tsum];
    }
};

/*
Time complexity: O(N*T), where N is the total number of elements present in the array and T is the total sum of the
elements present in the array.
Space complexity:  O(T) for DP array, where T is the total sum of the elements present in the array.
*/