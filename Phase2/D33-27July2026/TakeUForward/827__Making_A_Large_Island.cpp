/*
827. Making A Large Island

You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> dirs = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };

    int bfs(vector<vector<int>>& grid, vector<vector<int>>& island_ids, int i, int j, int id){
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        island_ids[i][j] = id;
        
        int area = 0;

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            area++;

            for(int k = 0; k < dirs.size(); k++){
                int nr = r + dirs[k].first, nc = c + dirs[k].second;
                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if(grid[nr][nc] == 0) continue;
                if(island_ids[nr][nc] > -1) continue; 
                
                island_ids[nr][nc] = id;
                q.push({nr, nc});
            } 
        }
        return area;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), id = 0;
        vector<vector<int>> island_ids(m, vector<int>(n, -1));
        unordered_map<int, int> island_sizes;
        int max_area = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && island_ids[i][j] == -1){
                    int size = bfs(grid, island_ids, i, j, id);
                    island_sizes[id] = size;
                    max_area = max(max_area, size); 
                    id++;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> neighbor_ids;
                    
                    for(int k = 0; k < dirs.size(); k++){
                        int nr = i + dirs[k].first, nc = j + dirs[k].second;
                        if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                            if(island_ids[nr][nc] != -1){
                                neighbor_ids.insert(island_ids[nr][nc]);
                            }
                        }
                    }

                    int current_area = 1; 
                    for(int neighbor_id : neighbor_ids){
                        current_area += island_sizes[neighbor_id];
                    }

                    max_area = max(max_area, current_area);
                }
            }
        }

        return max_area;
    }
};

/*
Time complexity: O(m*n), where m is the number of rows and n is the number of the columns.
Space complexity: O(m*n), where m is the number of rows and n is the number of the columns.
*/