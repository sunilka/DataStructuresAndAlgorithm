/*

Longest Subarray with given Sum K(Positives)

Problem Statement: Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

Examples
Example 1:
Input:
 nums = [10, 5, 2, 7, 1, 9], k = 15  
Output:
 4  
Explanation:
 The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.

Example 2:
Input:
 nums = [-3, 2, 1], k = 6  
Output:
 0  
Explanation:
 There is no sub-array in the array that sums to 6. Therefore, the output is 0.

*/

#include<bits/stdc++.h>
using namespace std;


// Solving with extra space 
int longestSubarrayWithKSumWithExtaSpace(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int ps = 0, n = nums.size(), ans = 0;
    for(int i=0; i<n; i++){
        ps += nums[i];
        int t = ps - k;
        if(ps == k) ans = max(ans, i+1);
        if(m.count(t)) ans = max(ans, i-m[t]);
        if (m.find(ps) == m.end()) m[ps] = i;
    }
    return ans;
}
/*

Complexity analysis:

Time complexity: O(N) -> Where N is the number of elements present in the array.
Space complexity: O(N) -> Where N is the number of elements present in the array.

*/

int longestSubarrayWithKSum(vector<int>& nums, int k) {
    int p1 = 0, p2 = 0, ps = 0, n = nums.size(), ans=0;
    while(p2<n){
        ps+=nums[p2];
        while(p1<=p2 && ps>k){
            ps-=nums[p2];
            p1++;
        }
        if(ps == k) ans = max(ans, p2-p1+1);
        p2++;
    }
    return ans;
}


// 2, 3, 100, 1, 1, 1, 2  k = 5
int main(){
    vector<int> nums = {2, 3, 100, 1, 1, 1, 2};
    int k = 5;
    int ans = longestSubarrayWithKSum(nums, k);
    cout<<"Printing the answer here "<<ans<<endl;
}

/*
Complexity Analysis:

Time complexity : O(N), where N is the number of elements that is present in the array.
Space complexity: O(1), constant space. 

*/