/*
85. Maximal Rectangle
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
 

Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= rows, cols <= 200
matrix[i][j] is '0' or '1'.
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int r = matrix.size(), c = matrix[0].size();
        vector<int> heights(c, 0);
        int max_ans = 0;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(i == 0) {
                    heights[j] = matrix[i][j] - '0'; 
                } else {
                    if(matrix[i][j] == '0') {
                        heights[j] = 0;
                    } else {
                        heights[j] = heights[j] + 1;
                    }
                }
            }
            max_ans = max(max_ans, largestRectangleArea(heights)); 
        }
        return max_ans;
    }
};

/*
Time complexity: O(M*N*N)
Space complexity: O(N)
*/