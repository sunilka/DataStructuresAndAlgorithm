/*

Floor and Ceil in Sorted Array

Problem Statement: ou're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1]. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x

Examples

Example 1:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
Result: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

Example 2:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
Result: 8 8
Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.
            
*/

#include<bits/stdc++.h>
using namespace std;

int search_floor(vector<int> nums, int target){
    int low = 0, high = nums.size()-1, ans = 0;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] > target) high = mid-1;
        else{
            ans = mid;
            low = mid+1;
        }
    }
    return ans;
}

int search_ceil(vector<int> nums, int target){
    int low = 0, high = nums.size()-1, ans = 0;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] > target){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}

int main(){
    vector<int> nums = {3, 4, 4, 7, 8, 10};
    int target = 8;

    int floor_index = search_floor(nums, target);
    int ceil_val = search_ceil(nums, target);

    cout<<"Printing the floor value "<<nums[floor_index]<<endl;
    cout<<"Printing the ceil value "<<nums[ceil_val]<<endl;
}

/*

Complexity analysis:

Time complexity: O(logN), where N is the number of elements present in the array.
Space complexity: O(1), we are not using any extra space, hence the space complexity is constant.

*/