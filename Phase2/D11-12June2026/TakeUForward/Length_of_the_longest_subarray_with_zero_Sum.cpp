/*

Largest subarray with 0 sum

Given an array arr[] containing both positive and negative integers, the task is to find the length of the longest subarray with a sum equals to 0.

Note: A subarray is a contiguous part of an array, formed by selecting one or more consecutive elements while maintaining their original order.

Examples:

Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The longest subarray with sum equals to 0 is [-2, 2, -8, 1, 7].
Input: arr[] = [2, 10, 4]
Output: 0
Explanation: There is no subarray with a sum of 0.
Input: arr[] = [1, 0, -4, 3, 1, 0]
Output: 5
Explanation: The longest subarray with sum equals to 0 is [0, -4, 3, 1, 0]
Constraints:
1 ≤ arr.size() ≤ 106
−103 ≤ arr[i] ≤ 103


*/

#include<bits/stdc++.h>
using namespace std;

int maxLength(vector<int>& arr) {
    int ps = 0, ans = 0;
    unordered_map<int, int> m;
    for(int i=0; i<arr.size(); i++){
        ps += arr[i];
        if(ps == 0) ans = max(ans, i+1);
        if(m.count(ps)) ans = max(ans, i-m[ps]);
        if(!m.count(ps)) m[ps] = i;
    }

    return ans;
}

int main(){
    vector<int> arr = {2, 10, 4};
    int ans = maxLength(arr);
    cout<<"Printing the answer here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(N), where N is the number of elements present in the array.
Space complexity: O(N), we are using the unordered map to store the elements, hence the space complexity is O(N).

*/