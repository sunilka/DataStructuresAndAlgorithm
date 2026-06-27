/*

Rotate the array.

*/

#include<bits/stdc++.h>
using namespace std;

void rotate1(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0; // this is an indicator of how many elements we place successfully rotated
    int start_index = 0;

    while(count<n){
        int current_index = start_index;
        int current_element = nums[current_index];

        do{
            int next_index = (current_index+k)%n;
            int temp = nums[next_index];
            nums[next_index] = current_element;
            current_index = next_index; 
            current_element = temp; 
            count+=1;

        }while(current_index!=start_index);
        start_index+=1;
    }
}

void rotate(vector<int>& nums, int k){
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());
}

int main(){
    vector<int> nums = {-1,-100,3,99};
    int k = 2;
    rotate(nums, k);
    cout<<"Printing the rotated array "<<endl;
    for(auto ele: nums) cout<<ele<<" ";
    cout<<endl;
}