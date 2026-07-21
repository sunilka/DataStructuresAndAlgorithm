/*
1631. Path With Minimum Effort

You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.


Example 1:
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.\

Example 2:
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

Example 3:
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
 

Constraints:

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});
        
        int ans = INT_MAX;

        while(!pq.empty()){
            auto info = pq.top();
            pq.pop();
            int max_effort = info.first, r = info.second.first, c = info.second.second;
    
            if (visited[r][c]) continue;
            visited[r][c] = true;

            if(r == m-1 && c == n-1) return max_effort;

            for(int i=0; i<dirs.size(); i++){
                int nr = r + dirs[i].first, nc = c + dirs[i].second;
                if(nr>=m || nr<0 || nc>=n || nc<0) continue;
                if(visited[nr][nc] == true) continue;
                int me = max(abs(heights[nr][nc] - heights[r][c]), max_effort);
                pq.push({me, {nr, nc}});
            }
        }
        return ans;
    }
};

/*
Time complexity: O(m * n * log(m * n)), where m is the number of rows in the graph and n is the number of cols in the graph.
Space complexity: O(m*n), where m is the number of rows in the graph and n is the number of cols in the graph.
*/