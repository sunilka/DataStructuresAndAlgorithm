/*

73. Set Matrix Zeroes

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int r = matrix.size(), c = matrix[0].size();
    bool set_1st_row_zero = false, set_1st_col_zero = false;
    for(int j=0; j<c; j++){
        if(matrix[0][j] == 0) set_1st_row_zero = true;
    }

    for(int i=0; i<r; i++){
        if(matrix[i][0] == 0) set_1st_col_zero = true;
    }


    for(int i=1; i<r; i++){
        for(int j=1; j<c; j++){
            if(matrix[i][j] == 0){
                cout<<"Printing the value of the i j "<<i<<" "<<j<<endl;
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Now we are going to go over the elements and fix each elements using the markers set
    for(int i=1; i<r; i++){
        for(int j=1; j<c; j++){
            if(matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
        }
    }

    if(set_1st_row_zero){
        for(int j=0; j<c; j++) matrix[0][j] = 0;
    }

    if(set_1st_col_zero){
        for(int i=0; i<r; i++) matrix[i][0] = 0;
    }

}

int main(){
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(matrix);
    cout<<"Printing the answer array here "<<endl;
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

/*

Complexity analysis:

Time complexity: O(N*M), where N is the number of rows and M is the number of columns.
Space complexity: O(1), we do not use an extra space, so the space complexity is constant

*/