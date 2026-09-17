/*
Rat in a Maze
Given a binary matrix maze[][] of size n × n containing values 0 and 1, find all possible paths for a rat to travel from the source cell (0, 0) to the destination cell (n - 1, n - 1). The rat can move in four directions: up(U), down(D), left(L), and right(R).

1 represents an open cell through which the rat can move.
0 represents a blocked cell that cannot be traversed.
The rat can move only through open cells and cannot visit the same cell more than once in a path. Return all valid paths as strings consisting of 'U', 'D', 'L', and 'R', representing the sequence of moves taken by the rat.

Note: Return the paths in lexicographically increasing order. If no valid path exists, return an empty list.

Examples:

Input: maze[][] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}}
Output: ["DDRDRR", "DRDDRR"]
Explanation: There are two valid paths from the source cell (0, 0) to the destination cell (3, 3).

Input: maze[][] = [[1, 0], [1, 0]]
Output: []
Explanation: No path exists as the destination cell (1, 1) is blocked.
Constraints:
2 ≤ n ≤ 5
0 ≤ maze[i][j] ≤ 1
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    vector<char> dirChar = {'D', 'L', 'R', 'U'};

    void solve(vector<vector<int>>& maze, int n, int r, int c, string& currentPath, vector<string>& ans) {
        if (r == n - 1 && c == n - 1) {
            ans.push_back(currentPath);
            return;
        }

        maze[r][c] = 0;

        for (int i = 0; i < 4; i++) {
            int nextR = r + dirs[i].first;
            int nextC = c + dirs[i].second;
            if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < n && maze[nextR][nextC] == 1) {
                currentPath.push_back(dirChar[i]);
                solve(maze, n, nextR, nextC, currentPath, ans);
                currentPath.pop_back(); 
            }
        }
        maze[r][c] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        int n = maze.size();
        if (n == 0 || maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
            return ans;
        }
        string currentPath = "";
        solve(maze, n, 0, 0, currentPath, ans);
        return ans;
    }
};

/*
Time complexity: O(3^(N^2)), where N is the maze size
Space complexity: O(N^2)
*/

