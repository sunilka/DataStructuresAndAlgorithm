/*

Problem Statement: Given two sorted arrays a and b of size m and n respectively. Find the kth element of the final sorted array.

Examples
Example 1:
Input:
 a = [2, 3, 6, 7, 9], b = [1, 4, 8, 10], k = 5  
Output:
 6  
Explanation:
 The final sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.

Example 2:
Input:
 a = [100, 112, 256, 349, 770], b = [72, 86, 113, 119, 265, 445, 892], k = 7  
Output:
 256  
Explanation:
 The final sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892]. The 7th element of this array is 256.

*/

#include<bits/stdc++.h>
using namespace std;

int findKthElement(vector<int>& nums1, vector<int> nums2, int k){
    if(nums1.size() > nums2.size()) return findKthElement(nums2, nums1, k);

    int m = nums1.size(), n = nums2.size();
    int low = max(0, k-n), high = min(k, m);
    while(low<=high){
        int mid1 = low + (high - low)/2;
        int mid2 = k - mid1;

        int l1 = (mid1>0) ? nums1[mid1-1]: INT_MIN;
        int l2 = (mid2>0) ? nums2[mid2-1]: INT_MIN;
        int r1 = (mid1<m) ? nums1[mid1]: INT_MAX;
        int r2 = (mid2<n) ? nums2[mid2]: INT_MAX;
        
        if(l1<=r2 && l2<=r1) return max(l1, l2);
        else if(l1 > r2) high = mid1-1;
        else low = mid1+1;
    }
    return 1;
}


int main(){
    vector<int> nums1 = {2, 3, 6, 7, 9};
    vector<int> nums2 = {1, 4, 8, 10};
    int k = 5;
    int ans = findKthElement(nums1, nums2, k);
    cout<<"Printing my k here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(log(min(m, n))), where m is the number of elements present in the first array and n is the number of elements present in the second array.s
Space complexity: O(1), we are not using any extra space, hence the space complexity is constant.

*/