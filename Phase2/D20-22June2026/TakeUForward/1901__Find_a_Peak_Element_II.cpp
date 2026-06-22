/*

1901. Find a Peak Element II

A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.


Example 1:

Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
Example 2:

Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
 
Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 500
1 <= mat[i][j] <= 105
No two adjacent cells are equal.

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> findPeakGrid1(vector<vector<int>>& mat) {
    int row = mat.size(), col = mat[0].size();
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            int te = i == 0? -1: mat[i-1][j];
            int le = j == 0? -1: mat[i][j-1];
            int re = j == col-1? -1: mat[i][j+1];
            int de = i == row-1? -1: mat[i+1][j];
            int ce = mat[i][j];

            if(ce > te && ce > le && ce > re && ce > de) return {i, j};
        }
    }

    return {-1, -1};
}

/*

Complexity analysis:

1) Time complexity: O(m*n), where m is the number of rows present in the array, and n is the number of cols present in the array.
2) Space complexity: O(1), we are not using any extra space, hence the space complexity is constant.

*/

int findMaxRowInColumn(vector<vector<int>>& mat, int col, int rows) {
    int max_val = -1;
    int max_row_idx = -1;
    for(int i = 0; i < rows; i++) {
        if(mat[i][col] > max_val) {
            max_val = mat[i][col];
            max_row_idx = i;
        }
    }
    return max_row_idx;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    int low = 0, high = n - 1;
    
    while(low <= high) {
        int mid_col = low + (high - low) / 2;
        int max_row = findMaxRowInColumn(mat, mid_col, m);
        int left_neighbor = (mid_col - 1 >= 0) ? mat[max_row][mid_col - 1] : -1;
        int right_neighbor = (mid_col + 1 < n) ? mat[max_row][mid_col + 1] : -1;
        int current_element = mat[max_row][mid_col];
        
        if(current_element > left_neighbor && current_element > right_neighbor) {
            return {max_row, mid_col};
        }
        else if(right_neighbor > current_element) {
            low = mid_col + 1;
        }
        else {
            high = mid_col - 1;
        }
    }
    return {-1, -1};
}

int main(){
    vector<vector<int>> mat = {{10,20,15},{21,30,14},{7,16,32}};
    vector<int> ans = findPeakGrid(mat);
    cout<<"Printing the answer here "<<ans[0]<<" "<<ans[1]<<endl;
}


/*

Gradient ascent. 

Complexity analysis:

Time complexity: O(rlogc), where r is the number of rows and the c is the number of cols present in the array.
Space complexity: O(1), we are not using any extra space, hence the space complexity is constant.

*/
