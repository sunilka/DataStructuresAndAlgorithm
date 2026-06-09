/*

48. Rotate Image

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000

*/

#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    // Transpose of the matrix;
    int r = matrix.size(), c = matrix[0].size();
    for(int i=0; i<r; i++){
        for(int j=0; j<i; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c/2; j++){
            swap(matrix[i][j], matrix[i][c-j-1]);
        }
    }
}

int main(){
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    rotate(matrix);
    int r = matrix.size(), c = matrix[0].size();

    cout<<"Printing the answer matrix here "<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

/*

Complexity analysis:

Time complexity: O(N*M) where N is the number of row and M is number of col present in the matrix.
Space complexity: O(1), we do not use any extra space, hence the space complexity is constant.
*/