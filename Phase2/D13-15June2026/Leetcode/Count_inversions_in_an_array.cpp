/*

Count inversions in an array

Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).

Inversion of an array: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

Examples
Example 1:
Input Format: N = 5, array[] = {1,2,3,4,5}
Result: 0
Explanation: we have a sorted array and the sorted array has 0 inversions as for i < j you will never find a pair such that A[j] < A[i]. More clear example: 2 has index 1 and 5 has index 4 now 1 < 5 but 2 < 5 so this is not an inversion.

Example 2:
Input Format: N = 5, array[] = {5,4,3,2,1}
Result: 10
Explanation: we have a reverse sorted array and we will get the maximum inversions as for i < j we will always find a pair such that A[j] < A[i]. Example: 5 has index 0 and 3 has index 2 now (5,3) pair is inversion as 0 < 2 and 5 > 3 which will satisfy out conditions and for reverse sorted array we will get maximum inversions and that is (n)*(n-1) / 2.For above given array there is 4 + 3 + 2 + 1 = 10 inversions.

Example 3:
Input Format: N = 5, array[] = {5,3,2,1,4}
Result: 7
Explanation: There are 7 pairs (5,1), (5,3), (5,2), (5,4),(3,2), (3,1), (2,1) and we have left 2 pairs (2,4) and (1,4) as both are not satisfy our condition.

*/

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums, int low, int mid, int high, int &ans){
    vector<int> left, right;
    for(int i=low; i<=mid; i++) left.push_back(nums[i]);
    for(int i=mid+1; i<=high; i++) right.push_back(nums[i]);

    int i=0, j=0, p = low;
    while(i<left.size() && j<right.size()){
        if(left[i] <= right[j]){
            nums[p] = left[i];
            i++;
        }
        else{
            // hey, there is an inversion over here, we go to count this inversion towards the answer
            ans += (left.size()-i);
            nums[p] = right[j];
            j++;
        }
        p++;
    }

    while(i<left.size()) nums[p++] = left[i++];
    while(j<right.size()) nums[p++] = right[j++];
}

void mergeSort(vector<int>& nums, int low, int high, int &ans){
    if(low<high){
        int mid = low + (high - low)/2;
        mergeSort(nums, low, mid, ans);
        mergeSort(nums, mid+1, high, ans);
        merge(nums, low, mid, high, ans);
    }
}

int countInversions(vector<int>& nums){
    int ans = 0;
    mergeSort(nums, 0, nums.size()-1, ans);
    return ans;
}

int main(){
    vector<int> nums;
    int ans = countInversions(nums);
    cout<<"Printing the number of inversions over here "<<ans<<endl;
}

/*

Complexity Analysis:

Time complexity: O(NlogN), where N is the number of elememts present in the array.
Space complexity: O(N+logN) = O(N), we are using left and the right temp arrays and for the recurrsion stack we are using the space of log N. Where N is the number of elements present 
in the array.

*/