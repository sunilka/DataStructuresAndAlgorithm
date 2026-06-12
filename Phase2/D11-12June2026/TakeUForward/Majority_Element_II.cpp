/*

229. Majority Element II

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 

Follow up: Could you solve the problem in linear time and in O(1) space?

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int e1 = 0, c1 = 0;
    int e2 = 0, c2 = 0;
    int n = nums.size();
    
    for(int i = 0; i < n; i++) {
        int ele = nums[i];
        if (c1 > 0 && e1 == ele) c1++;
        else if (c2 > 0 && e2 == ele) c2++;
        else if (c1 == 0) e1 = ele, c1 = 1;
        else if (c2 == 0) e2 = ele, c2 = 1;
        else c1--, c2--;
    }

    c1 = 0; c2 = 0;
    for(auto ele: nums) {
        if(ele == e1) c1++;
        else if(ele == e2) c2++;
    }

    vector<int> ans;
    int rn = (n / 3) + 1;
    
    if(c1 >= rn) ans.push_back(e1);
    if(c2 >= rn) ans.push_back(e2);
    
    return ans;
}

int main(){
    vector<int> nums = {1,1,2,2,7,7,8,8,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3};
    vector<int> ans = majorityElement(nums);
    cout<<"Printing the answer array here "<<endl;
    for(auto ele: ans) cout<<ele<<" ";
    cout<<endl;
}

/*

Complexity analysis:

Time complexity: O(N), where N is the number of elements in the array.
Space complexity: O(1), we do not use any extra space, so the space complexity is constant.

*/