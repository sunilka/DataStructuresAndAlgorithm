/*

130. Surrounded Regions

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:
In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.

*/

#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(vector<vector<char>>& board, int sr, int sc){
    int m = board.size(), n = board[0].size();
    cout<<"called here "<<sr<<" "<<sc<<endl;
    board[sr][sc] = 'D';
    for(int i=0; i<dirs.size(); i++){
        int nr = sr+dirs[i].first, nc = sc+dirs[i].second;
        if(nr <0 || nr >=m || nc <0 || nc>=n) continue;
        if(board[nr][nc] != 'O') continue;
        dfs(board, nr, nc);
    }
}

void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();

    // check for the top edge.
    for(int i=0; i<n; i++){
        if(board[0][i] == 'O') dfs(board, 0, i);
    }

    // Check fpr the right edge
    for(int i=0; i<m; i++){
        if(board[i][n-1] == 'O') dfs(board, i, n-1);
    }

    // Check for the bottom edge
    for(int i=0; i<n; i++){
        if(board[m-1][i] == 'O'){
            dfs(board, m-1, i);
        }
    } 

    // Check fo the left edge
    for(int i=0; i<m; i++){
        if(board[i][0] == 'O') dfs(board, i, 0);
    }

    // Replace '0' with X and 'D' with '0'
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == 'X') continue;
            else if(board[i][j] == 'D') board[i][j] = 'O';
            else board[i][j] = 'X';
        }
    }
}

int main(){
    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    solve(board);
    cout<<"Printing the answer here "<<endl;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

/*

Complexity analysis:

Time complexity: O(2(m+n) + (m*n) + (m*n)) = O(m*n), where m is the number of rows and n is the number of cols in the given board.
Space complexity: O(m*n), where m is the number of rows and n is the number of cols in the given board.

*/