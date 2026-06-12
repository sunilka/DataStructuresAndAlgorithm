/*

15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105

*/


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    unordered_map<int, int> m;
    vector<vector<int>> ans;
    int n = nums.size();
    
    for (int i = 0; i < n; i++) m[nums[i]] = i;

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            int rsum = -1 * (nums[i] + nums[j]);
            if (m.count(rsum)) {
                int idx = m[rsum];
                if (idx > j) {
                    ans.push_back({nums[i], nums[j], rsum});
                }
            }
        }
    }
    return ans; 
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threeSum(nums);
    cout<<"Printing the answer "<<endl;
    for(auto ele: ans){
        for(auto e: ele) cout<<e<<" ";
        cout<<endl;
    }
}

/*

Complexity analysis:

Time complexity: O(NlogN + N^2) = O(N^2), where N is the number of elements present in the array.
Space complexity: O(N), where N is the number of elements present in the array. we are using this space for the unordered map. 

*/