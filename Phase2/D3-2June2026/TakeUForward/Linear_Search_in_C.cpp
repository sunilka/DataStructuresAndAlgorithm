/*

Linear Search in C

Problem Statement: Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.

Examples
Example 1:
Input:
 arr[] = 1 2 3 4 5, num = 3  
Output:
 2  `
Explanation:
 3 is present at the 2nd index of the array.

Example 2:
Input:
 arr[] = 5 4 3 2 1, num = 5  
Output:
 0  
Explanation:
 5 is present at the 0th index of the array.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int f = 3;
    int n = arr.size();
    for(int i=0; i<n; i++){
        if(arr[i] == f){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}

/*

Complexity analysis:

Time complexity: O(N), where N is the number of elements that is present in the array.
Space complexity: O(1), we just use a varibale and no extra space, so the space complexity is constant.

*/