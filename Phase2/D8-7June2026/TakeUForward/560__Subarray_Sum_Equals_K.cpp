/*

560. Subarray Sum Equals K

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107


*/

#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int ps = 0, ans = 0, n = nums.size();
    unordered_map<int, int> mp;
    mp[0]=1;
    for(auto ele: nums){
        ps += ele;
        int req = ps - k;
        if(mp.count(req)){
            ans+=mp[req];
        }
        mp[ps]++;
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,1,2,1};
    int k = 3;
    int ans = subarraySum(nums, k);
    cout<<"Printing the answer here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(N) where N is the number of elements in the array.
Space complexity: O(N) where N is the number of elements in the array.

*/