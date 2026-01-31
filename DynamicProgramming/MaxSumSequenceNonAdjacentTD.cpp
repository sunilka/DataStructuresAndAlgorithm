#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    unordered_map<int, int> dp;
    int calc(vector<int> &arr, int pos){
        if(dp.find(pos)!=dp.end()){
            return dp[pos];
        }
        
        if(pos >= arr.size()){
            return 0;
        }
        
        else{
            int ans = max(
                    calc(arr, pos+2)+arr[pos],
                    calc(arr, pos+1)
                );
            dp[pos] = ans;
            return ans;
        }
    }
    int findMaxSum(vector<int>& arr) {
        return calc(arr, 0);
    }
};