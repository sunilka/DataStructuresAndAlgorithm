// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    map<pair<int, int>, bool> dp;
    bool calc(vector<int> &arr, int sum, int carrying_sum,int pos){
        if(dp.find({pos, carrying_sum})!=dp.end()){
            return dp[{pos, carrying_sum}];
        }
        
        if(pos >= arr.size()){
            if(carrying_sum == sum){
                return true;
            }
            return false;
        }
        
        else if(carrying_sum == sum){
            return true;
        }
        
        else if(carrying_sum > sum){
            return false;
        }
        
        else{
            bool ans = calc(arr, sum, carrying_sum+arr[pos], pos+1) || calc(arr, sum, carrying_sum, pos+1);
            dp[{pos, carrying_sum}] = ans;
            return ans;
        }
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        sort(arr.begin(), arr.end());
        return calc(arr, sum, 0, 0);
    }
};