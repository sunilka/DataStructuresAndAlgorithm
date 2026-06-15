/*

Understanding the concept of upper bound.

Upper bound gives you the smallest index where the element strictly greater than the given target element.
*/

#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int ans = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    return ans;
}

int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 5;
    int ans = search(nums, target);
    cout<<"Printing the answer here "<<ans<<endl;
}

/*

Complexity analysis:

in a vector, 

Time complexity: O(logN), where N is the number of elements in the array.
Space complexity: O(1), it will not using any extra space, hence the space complexity is constant.

*/