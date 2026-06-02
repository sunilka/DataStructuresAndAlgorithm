/*

Find Second Smallest and Second Largest Element in an array


Problem Statement: Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.

Examples
Example 1:
Input:
 [1, 2, 4, 7, 7, 5]  
Output:
  
Second Smallest : 2  
Second Largest : 5  
Explanation:
  The elements are sorted as 1, 2, 4, 5, 7, 7.  
Hence, the second smallest element is 2, and the second largest element is 5.

Example 2:
Input:
 [1]  
Output:
  
Second Smallest : -1  
Second Largest : -1  
Explanation:
  Since there is only one element in the array, it is both the largest and smallest element.  
Therefore, there is no second smallest or second largest element present.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 2, 4, 7, 7, 5};
    int maxi = INT_MIN, mini = INT_MAX, smaxi = INT_MIN, smini = INT_MAX;
    for(auto ele: arr){
        if(ele > maxi) maxi = ele;
        if(ele < mini) mini = ele;
    }

    for(auto ele: arr){
        if(ele < maxi && ele > smaxi) smaxi = ele;
        if(ele > mini && ele < smini) smini = ele;
    }

    if(smaxi == INT_MIN) smaxi = -1;
    if(smini == INT_MAX) smini = -1;
    cout<<"Second max element is "<<smaxi<<endl;
    cout<<"Second min element is "<<smini<<endl;
}

/*

Complexity analysis:

Time complexity = O(N) where N is the number of elements that is present in the array.
Space complexity = O(1) constant space, cause we are just using 4 variables. 

*/