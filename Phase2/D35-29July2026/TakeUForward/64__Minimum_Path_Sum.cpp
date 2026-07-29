/*
64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}};
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, grid[0][0]});
        dist[0][0] = grid[0][0];
        while(!q.empty()){
            auto info = q.front();
            int r = info.first.first, c = info.first.second, v = info.second;
            q.pop();
            for(auto dir: dirs){
                int nr = r+dir.first, nc = c+dir.second;
                if(nr<0 || nr>=m || nc<0 || nc>=n) continue;
                if(dist[nr][nc] > v + grid[nr][nc]){
                    dist[nr][nc] = v + grid[nr][nc];
                    q.push({{nr, nc}, dist[nr][nc]});
                }
            }
        }
        return dist[m-1][n-1];
    }
};

/*
Time complexity: O(2^(m+n))
Space complexity: O(m*n)
*/

/*
Using Dijikstra's algorithm
*/

class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}};
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];
        while(!pq.empty()){
            auto info = pq.top();
            int d = info.first, r = info.second.first, c = info.second.second;
            pq.pop();
            if(r == m-1 && c == n-1) return d;
            if(dist[r][c] < d) continue;
            for(int i=0; i<dirs.size(); i++){
                int nr = r+dirs[i].first, nc = c+dirs[i].second;
                if(nr<0 || nr>=m || nc<0 || nc>=n) continue;
                if(dist[nr][nc] > d+grid[nr][nc]){
                    dist[nr][nc] = d+grid[nr][nc];
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }
        return -1;
    }
};

/*
Time complexity: O(ElogV) = O(m*n(log (m*n)))
Space complexitt: O(m*n)
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i==m-1 && j==n-1){
                    dist[i][j] = grid[i][j];
                    continue;
                }
                if(i==m-1){
                    dist[i][j] = grid[i][j] + dist[i][j+1];
                    continue;
                }
                if(j==n-1){
                    dist[i][j] = grid[i][j] + dist[i+1][j];
                    continue;
                }
                else{
                    dist[i][j] = min(
                        grid[i][j] + dist[i][j+1],
                        grid[i][j] + dist[i+1][j]
                    );
                }
            }
        }
        return dist[0][0];
    }
};

/*
Time complexity: O(m*n)
Space complexity: O(m*n)
*/

/*
Space optimization
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> next(n, 0), cur(n, 0);
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i==m-1 && j==n-1) cur[j] = grid[i][j];
                else if(i==m-1) cur[j] = grid[i][j] + cur[j+1];
                else if(j==n-1) cur[j] = grid[i][j] + next[j];
                else cur[j] = min(grid[i][j] + cur[j+1], grid[i][j] + next[j]);
            }
            next = cur;
        }
        return cur[0];
    }
};

/*
Time complexity: O(m*n)
Space complexity: O(m)
*/