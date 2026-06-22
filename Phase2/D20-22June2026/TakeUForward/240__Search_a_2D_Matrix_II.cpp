/*

240. Search a 2D Matrix II

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 

Example 1:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

Example 2:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
 
Constraints:

m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matrix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109

*/


#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size(), col = matrix[0].size();
    int r = 0, c = col-1;
    while(r<row && c>=0){
        if(matrix[r][c] == target) return true; 
        else if(matrix[r][c] > target) c-=1;
        else r+=1;
    }
    return false;
}

int main(){
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    bool ans = searchMatrix(matrix, target);
    cout<<"Printing the answer here "<<ans<<endl;
}

/*

Staircase search

Complexity analysis:

Time complexity: O(r+c), where r is the number of rows and the c is the number of cols present in the given array.
Space complexity: O(1), we are not using any extra space, hence the space complexity is constant.

*/
