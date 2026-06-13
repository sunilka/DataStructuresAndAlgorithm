/*

493. Reverse Pairs

Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1

*/

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums, int low, int mid, int high, int &count){
    vector<int> left, right;
    for(int i=low; i<=mid; i++) left.push_back(nums[i]);
    for(int i=mid+1; i<=high; i++) right.push_back(nums[i]);

    int j = 0;
    for(int i=0; i<left.size(); i++){
        while(j < right.size() && left[i] > 2LL * right[j]){
            j++;
        }
        count += j;
    }

    int left_pointer = 0, right_pointer = 0, pointer = low;
    while(left_pointer < left.size() && right_pointer < right.size()){
        if(left[left_pointer] < right[right_pointer]) nums[pointer++] = left[left_pointer++];
        else nums[pointer++] = right[right_pointer++];
    }

    while(left_pointer<left.size()) nums[pointer++] = left[left_pointer++];
    while(right_pointer < right.size()) nums[pointer++] = right[right_pointer++];
}

void mergesort(vector<int>& nums, int low, int high, int& count){
    if(low<high){
        int mid = low + (high - low)/2;
        mergesort(nums, low, mid, count);
        mergesort(nums, mid+1, high, count);
        merge(nums, low, mid, high, count);
    }
}

int reversePairs(vector<int>& nums) {
    int count = 0;
    mergesort(nums, 0, nums.size()-1, count);
    return count;
}

int main(){
    vector<int> nums = {1,3,2,3,1};
    int ans = reversePairs(nums);
    cout<<"Printing the answer here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity; O(NlogN), where N is the numeber of elements present in the array.
Space complexity: O(N+N), where N is the number of elements present in the array.


*/