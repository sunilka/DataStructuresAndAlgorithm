/*

Count the number of subarrays with given xor K

Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.

Examples
Input: A = [4, 2, 2, 6, 4] , k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
Input: A = [5, 6, 7, 8, 9], k = 5
Output: 2
Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]


*/

#include<bits/stdc++.h>
using namespace std;

int countXOR(vector<int>& nums, int &k){
    unordered_map<int, int> mp;
    mp[0] = 1;
    int rpx = 0, ans = 0;
    for(auto num: nums){
        rpx = rpx ^ num;
        int target = rpx ^ k;
        if(mp.count(target)) ans+=mp[target];
        mp[rpx]++;
    }
    return ans;
}

int main(){
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = countXOR(nums, k);
    cout<<"Printing the answere here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(N), where N is the number of elements present in the array.
Space complexity: O(N), where N is the number of elements present in the array.

*/