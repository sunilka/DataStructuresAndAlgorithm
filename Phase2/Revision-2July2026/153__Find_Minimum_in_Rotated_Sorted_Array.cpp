/*
153__Find_Minimum_in_Rotated_Sorted_Array.cpp
*/

#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums){
    int n = nums.size();
    int low = 0, high = n-1;

    while(low<high){
        int mid = low+(high-low)/2;
        if(nums[mid]>=nums[low]){
            if(nums[high] > nums[mid]){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        else high = mid;
    }
    return nums[low];
}

int main(){
    vector<int> nums={0, 1, 2, 3, 4, 5};
    int ans = findMin(nums);
    cout<<"Printing my min answer here "<<ans<<endl;
}