/*

Kadane's Algorithm : Maximum Subarray Sum in an Array

Problem Statement: Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.

A subarray is a contiguous non-empty sequence of elements within an array.

Examples
Example 1:
Input:
 nums = [2, 3, 5, -2, 7, -4]  
Output:
 15  
Explanation:
 The subarray from index 0 to index 4 has the largest sum = 15, which is the maximum sum of any contiguous subarray.

Example 2:
Input:
 nums = [-2, -3, -7, -2, -10, -4]  
Output:
 -2  
Explanation:
 The largest sum is -2, which comes from taking the element at index 0 or index 3 as the subarray. Since all numbers are negative, the subarray with the least negative number gives the largest sum.

*/

#include<bits/stdc++.h>
using namespace std;

int max_subarray_sum(vector<int> nums){
    int p = 0, ans = INT_MIN, ps = 0, si = -1, ei = -1, n = nums.size();
    for(int i=0; i<n; i++){
        ps = max(nums[i], nums[i]+ps);
        ans = max(ans, ps);
    }
    return ans;
}


vector<int> max_subarray_sum_2(vector<int> nums){
    int p = 0, ans = INT_MIN, ps = 0, si = 0, ei = 0, n = nums.size(), cs=0;
    for(int i=0; i<n; i++){
        if(nums[i] > nums[i]+ps){
            cs = i;
            ps = nums[i];
        }
        else{
            ps = nums[i] + ps;
        }
        if(ps > ans){
            ans = ps;
            si = cs;
            ei = i;
        }
    }

    return {ans, si, ei};
}


int main(){
    vector<int> nums = {2, 3, 5, -2, 7, -4};
    vector<int> ans = max_subarray_sum_2(nums);
    cout<<"Printing max subarray sum over here "<<ans[0]<<endl;
    cout<<"Start index "<<ans[1]<<endl;
    cout<<"End index "<<ans[2]<<endl;
}

/*

Complexity analysis:

Time complexity = O(N) where N is the number of elements present in the array.
Space complexity = O(1), we just have 3 varibales, so the space complexity is constant.


*/