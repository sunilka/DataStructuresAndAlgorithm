/*
Subset Sum Problem

Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: There is no subset with target sum 30.
Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
Constraints:
1 <= arr.size() <= 200
1<= arr[i] <= 200
1<= sum <= 104
*/

#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>& arr, int n, int target , int csum, int idx){
    if(csum == target) return true;
    if(idx >= n) return false;
    if(csum > target) return false;
    bool take = solve(arr, n, target, csum + arr[idx], idx+1);
    bool notake = solve(arr, n, target, csum, idx+1);
    return (take || notake);
}
bool isSubsetSum(vector<int>& arr, int sum) {
    return solve(arr, arr.size(), sum, 0, 0);        
}

int main(){
    vector<int> arr = {100,1,2,3};
    cout<<"Printing the answer here "<<endl;
    cout<<isSubsetSum(arr, 5);
}

/*
Time complexity: O(2^(N))
Space complexity: Auxillary stack space of O(N).
*/

/*
Top down DP.
*/

class Solution {
  public:
    bool solve(vector<int>& arr, int n, int target , int csum, int idx, vector<vector<int>>& dp){
        if(csum == target) return true;
        if(idx >= n) return false;
        if(csum > target) return false;
        if(dp[idx][csum] != -1) return dp[idx][csum];
        bool take = solve(arr, n, target, csum + arr[idx], idx+1, dp);
        bool notake = solve(arr, n, target, csum, idx+1, dp);
        bool ans = (take || notake);
        dp[idx][csum] = ans;
        return ans;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return solve(arr, arr.size(), sum, 0, 0, dp);        
    }
};

/*
Time complexity: O(N*T), where N is the number of elements in the given array and T is the target sum.
Space complexity: : O(N×T) for the DP matrix + O(N) recursion call stack space.
*/


/* Bottom up DP*/

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        
        for(int i=0; i<=n; i++) dp[i][sum] = true;
        
        for(int idx=n-1; idx>=0; idx--){
            for(int csum=sum-1; csum>=0; csum--){
                bool take = false;
                if(csum+arr[idx] <= sum){
                    take = dp[idx + 1][csum + arr[idx]];
                }
                bool notake = dp[idx + 1][csum];
                dp[idx][csum] = (take || notake);
            }
        }
        return dp[0][0];
    }
};

/*
Time complexity: O(N*T), where N is the number of elements in the given array and T is the target sum.
Space complexity: : O(N×T) for the DP matrix.
*/

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> next(sum+1, false);
        vector<bool> cur(sum+1, false);
        
        next[sum] = true;
        cur[sum] = true;
        
        for(int idx=n-1; idx>=0; idx--){
            for(int csum=sum-1; csum>=0; csum--){
                bool take = false;
                if(csum+arr[idx] <= sum){
                    take = next[csum + arr[idx]];
                }
                bool notake = next[csum];
                cur[csum] = (take || notake);
            }
            next=cur;
        }
        return cur[0];
    }
};

/*
Time complexity: O(N*T), where N is the number of elements in the given array and T is the target sum.
Space complexity: : O(T) for the DP matrix.
*/