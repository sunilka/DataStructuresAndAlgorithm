/*
79. Word Search
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool solve(vector<vector<char>>& board, int& m, int& n, string& word, int& wn, int idx, int i, int j){
        if(idx == wn) return true;
        if(i >= m || i < 0 || j >= n || j < 0) return false;
        if(board[i][j] != word[idx]) return false;
        char temp = board[i][j];
        board[i][j] = '#'; 
        for(int k = 0; k < dirs.size(); k++){
            if(solve(board, m, n, word, wn, idx + 1, i + dirs[k].first, j + dirs[k].second)) {
                board[i][j] = temp;
                return true;
            }
        }
        board[i][j] = temp; 
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(), wn = word.size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    if(solve(board, m, n, word, wn, 0, i, j)) return true;
                }
            }
        }
        return false;
    }
};

/*
Time complexity: O(M*N*3^L), where M is the number of rows and N is the number of columns present in the given matrix and L is
the length of the string given.
Space complexity: O(L) where L is the length of the string given.
*/