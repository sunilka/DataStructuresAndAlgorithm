// https://leetcode.com/problems/largest-rectangle-in-histogram/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> PSE(n);
        vector<int> NSE(n);

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            PSE[i] = st.empty() ? -1: st.top();
            st.push(i);
        }
        st = stack<int>();

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            NSE[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            int area = heights[i] * (NSE[i] - PSE[i] - 1);
            ans = max(area, ans);
        }
        return ans;
    }
};