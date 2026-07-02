/*
540__Single_Element_in_a_Sorted_Array.cpp
*/

#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    // Check the first and the last element first
    int n = nums.size();
    if(nums[0]!=nums[1]) return nums[0];
    if(nums[n-1]!=nums[n-2]) return nums[n-1];

    int low = 1, high = n-2;
    while(low<=high){
        int mid=low+(high - low)/2;
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
        if(mid%2 == 0){
            if(nums[mid] == nums[mid+1]) low = mid+2;
            else high = mid-1;
        }
        else{
            if(nums[mid] == nums[mid-1]) low = mid+1;
            else high = mid-1;
        }
    }
    return nums[low];
}

int main(){
    vector<int> nums={3,3,7,7,10,11,11};
    int ans = singleNonDuplicate(nums);
    cout<<"Printing my answer here "<<ans<<endl;
}