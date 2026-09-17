/*
51. N-Queens
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool can_place_queen(vector<vector<char>>& board, int row, int col, int n) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

    void solve(int n, int idx, vector<vector<char>>& board, vector<vector<string>>& ans) {
        if (idx == n) {
            vector<string> tans;
            for (int i = 0; i < n; i++) {
                string cans = "";
                for (int j = 0; j < n; j++) {
                    cans += board[i][j];
                }
                tans.push_back(cans);
            }
            ans.push_back(tans);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (can_place_queen(board, idx, j, n)) {
                board[idx][j] = 'Q';
                solve(n, idx + 1, board, ans); 
                board[idx][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        solve(n, 0, board, ans);
        return ans;
    }
};

/*
Time complexity: O(N!*N), where N is the number of queens that are to be placed.
Space complexity: O(N) auxilioary stack space because of the recursion.
*/