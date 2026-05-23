// https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        stack<int> s;
        vector<int> ans;
        ans.push_back(-1);
        s.push(arr[arr.size() - 1]);
        
        for(int i=arr.size()-2; i>=0; i--){
            if(s.empty()){
                ans.push_back(-1);
                s.push(arr[i]);
            }
            
            else{
                while(!s.empty() && s.top() >= arr[i]){
                    s.pop();
                }
                
                if(!s.empty()){
                    ans.push_back(s.top());
                    s.push(arr[i]);
                }
                else{
                    ans.push_back(-1);
                    s.push(arr[i]);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};