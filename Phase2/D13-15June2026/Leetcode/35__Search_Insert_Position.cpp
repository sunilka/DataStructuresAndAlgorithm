/*

35. Search Insert Position

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104

*/

#include<bits/stdc++.h>
using namespace std;

int searchInsert1(vector<int>& nums, int target) {
    return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}

int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1, ans = nums.size()-1;

    while(low<=high){
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
    vector<int> nums = {1,3,5,6};
    int target = 7;
    int ans = searchInsert(nums, target);
    cout<<"Printing the answer here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(logN), where N is the number of elements present in the array.
Space complexity: O(1), we are not using any extra space, hence the space complexity is constant.

*/