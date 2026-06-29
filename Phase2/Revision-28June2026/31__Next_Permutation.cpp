/*
Next permutation.
*/

#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int pivot = -1;

    for(int i=n-2; i>=0; i--){
        if(nums[i] < nums[i+1]){
            pivot=i;
            break;
        }
    }

    if(pivot==-1){
        reverse(nums.begin(), nums.end());
        return;
    }

    // Find the next greater element to swap with pivot.
    for(int i=n-1; i>pivot; i--){
        if(nums[i] > nums[pivot]){
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    reverse(nums.begin()+pivot+1, nums.end());
}

int main(){
    vector<int> nums; 
    cout<<"Printing the answer here "<<endl;
    for(auto ele: nums) cout<<ele<<" ";
    cout<<endl;
}