/*
Find nth root of m

You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then return -1.

Examples :

Input: n = 3, m = 8
Output: 2
Explanation: 23 = 8
Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not integer.
Input: n = 4, m = 16
Output: 2
Explanation: 24 = 16
Constraints:
1 ≤ n ≤ 9
0 ≤ m ≤ 20

*/


#include<bits/stdc++.h>
using namespace std;

int nthRoot(int n, int m) {
    if(m == 0) return 0;
    if(m == 1) return 1;

    int low = 2, high = m;
    while(low<=high){
        int mid = low + (high - low)/2;
        int tans = 1;
        for(int i=0; i<n; i++){
            tans = tans * mid;
            if (tans > m) break;
        }
        if(tans == m) return mid;

        if(tans > m) high = mid-1;
        else low = mid+1;
    } 
    return -1;
    
}

int main(){
    int n=4, m=16;
    int ans = nthRoot(n, m);
    cout<<"Printing the answer here "<<ans<<endl;
}

/* 

Complexity analysis:

Time complexity: O(NLogM), where N and M are the given numbers.
Space complexity: O(1), we are not using any extra space, hence the space complexity is constant.

*/