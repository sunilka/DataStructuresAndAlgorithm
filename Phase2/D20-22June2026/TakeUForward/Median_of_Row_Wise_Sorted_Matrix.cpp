/*

Median in a row-wise sorted Matrix

Given a row-wise sorted matrix mat[][] of size n*m, where the number of rows and columns is always odd. Return the median of the matrix.

Examples:

Input: mat[][] = [[1, 3, 5], 
                [2, 6, 9], 
                [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median.
Input: mat[][] = [[2, 4, 9],
                [3, 6, 7],
                [4, 7, 10]]
Output: 6
Explanation: Sorting matrix elements gives us [2, 3, 4, 4, 6, 7, 7, 9, 10]. Hence, 6 is median.
Input: mat = [[3], [4], [8]]
Output: 4
Explanation: Sorting matrix elements gives us [3, 4, 8]. Hence, 4 is median.
Constraints:
1 ≤ n, m ≤ 400
1 ≤ mat[i][j] ≤ 2000

*/

#include<bits/stdc++.h>
using namespace std;

int countLessEqual(const vector<int> &arr, int value){
    return upper_bound(arr.begin(), arr.end(), value) - arr.begin();
}

int median(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    int low = mat[0][0], high = mat[0][n-1];
    
    for(int i = 0; i < m; i++){
        low = min(low, mat[i][0]);
        high = max(high, mat[i][n-1]);
    }

    while(low <= high){
        int mid = low + (high - low) / 2;
        int count = 0;
        
        for(int i = 0; i < m; i++){
            count += countLessEqual(mat[i], mid); 
        }

        if(count < (m * n + 1) / 2) 
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return low;
}

int main(){
    vector<vector<int>> mat;
    int ans = median(mat);
    cout<<"Printing the answer here "<<ans<<endl;
}

/* 

Complexity analysis:

Time complexity: O(r*logc*log(max-min)), where max is the maximum element present in the array and the min is the minimum element present in the array, c is the number of cols present
Space complexity: O(1), we are not using any extra space, hence the space complexity is constant.

*/