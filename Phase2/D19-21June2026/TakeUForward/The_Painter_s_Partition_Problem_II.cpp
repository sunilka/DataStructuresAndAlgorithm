/*

The Painter's Partition Problem-II

Given an array arr[] where each element denotes the length of a board, and an integer k representing the number of painters available. Each painter takes 1 unit of time to paint 1 unit length of a board.

Determine the minimum amount of time required to paint all the boards, under the constraint that each painter can paint only a contiguous sequence of boards (no skipping or splitting allowed).

Examples:

Input: arr[] = [5, 10, 30, 20, 15], k = 3
Output: 35
Explanation: The optimal allocation of boards among 3 painters is - 
Painter 1 → [5, 10] → time = 15
Painter 2 → [30] → time = 30
Painter 3 → [20, 15] → time = 35
Job will be done when all painters finish i.e. at time = max(15, 30, 35) = 35
Input: arr[] = [10, 20, 30, 40], k = 2
Output: 60
Explanation: A valid optimal partition is - 
Painter 1 → [10, 20, 30] → time = 60
Painter 2 → [40] → time = 40
Job will be complete at time = max(60, 40) = 60
Input: arr[] = [100, 200, 300, 400], k = 1
Output: 1000
Explanation: There is only one painter, so the painter must paint all boards sequentially. The total time taken will be the sum of all board lengths, i.e., 100 + 200 + 300 + 400 = 1000.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104
1 ≤ k ≤ 105

*/

#include<bits/stdc++.h>
using namespace std;

int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end()), high = accumulate(nums.begin(), nums.end(), 0), ans = -1, n = nums.size();
    while(low<=high){
        int mid = low + (high - low)/2; // possible large sum

        int rs = 0, ns = 1;
        for(int i=0; i<n; i++){
            if(rs+nums[i] <= mid) rs+=nums[i];
            else{
                rs = nums[i];
                ns+=1;
            }
        }

        if(ns <= k){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}

int main(){
    vector<int> nums = {5, 10, 30, 20, 15};
    int k=3;
    int ans = splitArray(nums, k);
    cout<<"Printing my answer here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(N*log(SUM-MAX_ELEMENT)), where N is the number of elements present in the array, SUM is the sum of all the elements and MAX_ELEMENT is the 
max of all the elements present in the array.
Space complexity: O(1), we are not using any extra space, hence the space complexity is constant here. 


*/