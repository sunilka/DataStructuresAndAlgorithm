/*

Finding Sqrt of a number using Binary Search

Problem Statement: You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).

Examples
Input: N = 36
Output: 6
Explanation: Square root of 36 is 6. 
Input: N = 28
Output: 5
Explanation: Square root of 28 is approximately 5.292. So, the floor value will be 5. 

*/

#include<bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
    int low = 1, high = n, ans = 0;

    while(low<=high){
        int mid = low + (high - low)/2;
        if(mid*mid == n) return mid;
        if(mid*mid < n){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    int n=5;
    int ans = floorSqrt(n);
    cout<<"Printing the answer here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(logN), where N is the given number.
Space complexity: O(1), we are not using any extra space, hence the space complexity is constant.

*/