/*

74. Search a 2D Matrix

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 
Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

*/


#include<bits/stdc++.h>
using namespace std;

bool searchMatrix1(vector<vector<int>>& matrix, int target) {
    int row = matrix.size(), col = matrix[0].size();
    int r = 0, c = col-1;
    while(r<row && c>=0){
        if(matrix[r][c] == target) return true; 
        else if(matrix[r][c] > target) c-=1;
        else r+=1;
    }
    return false;
}

/*

Staircase search

Complexity analysis:

Time complexity: O(r+c), where r is the number of rows and the c is the number of cols present in the given array.
Space complexity: O(1), we are not using any extra space, hence the space complexity is constant.

*/


bool searchMatrix2(vector<vector<int>>& matrix, int target){
    int row = matrix.size(), col = matrix[0].size();
    int sr = -1;

    // First we will get the row in which the value might lie in
    int low = 0, high = row-1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(matrix[mid][0] == target) return true;
        else if(matrix[mid][0] > target) high = mid-1;
        else low = mid+1;
    }
    sr = high;

    if (sr < 0) return false;

    low = 0, high = col-1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(matrix[sr][mid] == target) return true;
        else if(matrix[sr][mid] > target) high = mid-1;
        else low = mid+1;
    }
    return false;
}


/*

Complexity analysis:

Time complexity: O(logr+logc) = O(log(r*c)), where r is the number of rows present in the array and c is the number of cols present in the array.
Space complexity: O(1), we are not using any extra space, hence the space complexity is constant. 

*/


bool searchMatrix(vector<vector<int>>& matrix, int target){
    int m = matrix.size(), n = matrix[0].size();
    int low = 0, high = (n*m)-1;
    while(low<=high){
        int mid = low+(high - low)/2;
        int r = mid/n;
        int c = mid%n;

        if(matrix[r][c] == target) return true;
        else if(matrix[r][c] < target) low = mid + 1;  
        else high = mid - 1; 
    }
    return false;
}

/*

Complexity analysis:

Time complexity: O(log(r*c)), where r is the number of rows present in the array and c is the number of cols present in the array.
Space complexity: O(1), we are not using any extra space, hence the space complexity is constant. 

*/


int main(){
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    bool ans = searchMatrix(matrix, target);
    cout<<"Printing the answer here "<<ans<<endl;
}