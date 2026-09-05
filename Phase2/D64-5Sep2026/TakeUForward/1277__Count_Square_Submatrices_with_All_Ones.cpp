/*
1277. Count Square Submatrices with All Ones

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), tot_squares= 0;
        for(int i = 0; i < m; i++) tot_squares += matrix[i][n - 1];
        for(int j = 0; j < n - 1; j++) tot_squares += matrix[m - 1][j];
        for(int i=m-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                if(matrix[i][j] != 0){
                    matrix[i][j] = 1+ min(matrix[i+1][j], min(matrix[i][j+1], matrix[i+1][j+1]));
                    tot_squares+=matrix[i][j];
                }
            }
        }
        return tot_squares;
    }
};

/*
Time complexity: O(M*N), where M is the number of rows present in the given matrix and N is the number 
of cols present in the given matrix.
Space complexity: O(1), we are using the same input matrix though.
*/