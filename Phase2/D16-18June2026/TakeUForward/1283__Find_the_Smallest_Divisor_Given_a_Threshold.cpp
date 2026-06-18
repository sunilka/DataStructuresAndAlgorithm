/*

1283. Find the Smallest Divisor Given a Threshold

Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44
 

Constraints:

1 <= nums.length <= 5 * 104
1 <= nums[i] <= 106
nums.length <= threshold <= 106

*/

#include<bits/stdc++.h>
using namespace std;

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1, high = *max_element(nums.begin(), nums.end()), ans = -1, n = nums.size();
    while(low <= high){
        int mid = low + (high - low)/2, tans = 0;
        for(int i=0; i<n; i++){
            if(nums[i] % mid == 0) tans+=nums[i]/mid;
            else tans += (nums[i]/mid)+1;
        }
        if(tans <= threshold){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,5,9};
    int threshold = 6;
    int ans = smallestDivisor(nums, threshold);
    cout<<"Printing the answer here "<<ans<<endl;
}


/*

Complexity analysis:

Time complexity: O(NlogM), where N is the number of elements present in the array and the M is the greatest element present in the array.
Space complexity: O(1), we do not use any extra space, hence the space complexity is constant.

*/