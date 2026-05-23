// https://leetcode.com/problems/climbing-stairs/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int, int> m;
    int climbStairs(int n) {
        if(m.find(n)!=m.end()){
            return m[n];
        }
        if(n<0){
            return 0;
        }
        else if(n==0){
            return 1;
        }
        else{
            int ans  = climbStairs(n-1)+climbStairs(n-2);
            m[n] = ans;
            return ans;
        }
    }
};