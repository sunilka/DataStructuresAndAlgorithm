/*
120. Triangle
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 
Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 
Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        for(int i=m-1; i>=0; i--){
            for(int j=0; j<triangle[i].size(); j++){
                if (i == m - 1) dist[i][j] = triangle[i][j];
                else dist[i][j] = triangle[i][j] + min(dist[i+1][j], dist[i+1][j+1]);
            }
        }
        return dist[0][0];
    }
};

/*
Time complexity: O(N^2)
Space complexity: O(N^2)
*/

/*
Space optimized version
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<int> cur(n, 0), next(n, 0);
        for(int i=m-1; i>=0; i--){
            for(int j=0; j<triangle[i].size(); j++){
                if (i == m - 1) cur[j] = triangle[i][j];
                else cur[j] = triangle[i][j] + min(next[j], next[j+1]);
            }
            next = cur;
        }
        return cur[0];
    }
};

/*
Time complexity: O(N^2), where N is the number of rows in the triangle.
Space complexity: O(N), where N is the number of rows in the triangle.
*/