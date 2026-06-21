/*
4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

*/

#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
    int n1 = nums1.size(), n2 = nums2.size(), low = 0, high = n1;
    while(low <= high){
        int cut1 = (low+high)/2;
        int cut2 = (n1+n2+1)/2 - cut1;

        int l1 = cut1 == 0? INT_MIN: nums1[cut1-1];
        int l2 = cut2 == 0? INT_MIN: nums2[cut2-1];

        int r1 = cut1 == n1? INT_MAX: nums1[cut1];
        int r2 = cut2 == n2? INT_MAX: nums2[cut2];

        if(l1 <= r2 && l2<=r1){
            if( (n1+n2)%2 == 0) return (max(l1, l2) + min(r1, r2))/2.0;
            else return max(l1, l2);
        }

        else if(l1>r2) high = cut1-1;
        else low = cut1+1; 
    }
    return 0.0;
}

int main(){
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    double ans = findMedianSortedArrays(nums1, nums2);
    cout<<"Printing the answer here "<<double(ans)<<endl;
}

/*

Complexity analysis:

Time complexity: O(log(min(n1, n2))), where n1 represents the size of the first array and n2 represents the size of second array.
Space complexity: O(1), we are not using any extra space, hence the space complexity is constant.s

*/