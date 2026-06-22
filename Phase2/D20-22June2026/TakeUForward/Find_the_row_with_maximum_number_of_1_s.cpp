/*

Find the row with maximum number of 1's

10

Problem Statement: You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order. Your task is to find the index of the row with the maximum number of ones. Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1

Examples
Example 1:
Input Format: n = 3, m = 3, 
mat[] = 
1 1 1
0 0 1
0 0 0
Result: 0
Explanation: The row with the maximum number of ones is 0 (0 - indexed).

Example 2:
Input Format: n = 2, m = 2 , 
mat[] = 
0 0
0 0
Result: -1
Explanation:  The matrix does not contain any 1. So, -1 is the answer.

*/

#include<bits/stdc++.h>
using namespace std;

int rowWithMax1s1(vector<vector<int>> &arr) {
    int r = arr.size(), c = arr[0].size(), ans = -1, pao = arr[0].size();

    for(int i=0; i<r; i++){
        int low = 0, high = c-1, tno = c;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(arr[i][mid] == 1){
                cout<<"Yesss "<<mid<<" "<<arr[i][mid]<<endl;
                tno = min(tno, mid);
                high = mid-1;
            }
            else low = mid+1;
        }     

        if(pao > tno){
            ans = i;
            pao = tno;
        }
    }
    return ans;
}

/*

Complexity analysis:

Time complexity: O(rlogc), where r is the number of rows and c is the number of columns present in the given array.
Space complexity: O(1), we are not using any extra space, hence the space complexity is constant.

*/

/*

The above we are using binary search to come to the answer, but we have another techique to solve such 2D arrays, which is called staircase search.
We will implement the staircase search in the below implementation.

*/

int rowWithMax1s(vector<vector<int>> &arr) {
    int r = arr.size(), c = arr[0].size();
    int rp = 0, cp = c - 1, ans = -1;

    while(rp < r && cp>=0){
        if(arr[rp][cp] == 1){
            ans = rp;
            cp-=1;
        }
        else rp+=1;
    }
    return ans;
}

int main(){
    vector<vector<int>> arr = {{0,1,1,1}, {0,0,1,1}, {1,1,1,1}, {0,0,0,0}};
    int ans = rowWithMax1s(arr);
    cout<<"Printing my answer here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(r+c), where the r is the number of rows and c is the number of columns present in the given array.
Space complexity: O(1), we are not using any extra space, hence the space complexity is constant.

*/

