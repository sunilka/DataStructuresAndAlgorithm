/*
84. Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n, n), pse(n, -1);
        stack<int> s;
        for(int i = 0; i < n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            if(!s.empty()) pse[i] = s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = n - 1; i >= 0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            if(!s.empty()) nse[i] = s.top();
            s.push(i);
        }
        int max_area = 0;
        for(int i = 0; i < n; i++){
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            max_area = max(max_area, area);
        }
        
        return max_area;
    }
};

/*
Time complexity: O(N), where N is the number of elements present in the given array.
Space complexity: O(N)
*/