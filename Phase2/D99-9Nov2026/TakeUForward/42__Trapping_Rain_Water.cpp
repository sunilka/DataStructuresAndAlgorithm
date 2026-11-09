/*
42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        vector<int> left(n), right(n);
        left[0] = height[0];
        for(int i = 1; i < n; i++) {
            left[i] = max(left[i-1], height[i]);
        }
        right[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--) {
            right[i] = max(right[i+1], height[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }
};

/*
Time complexity: O(N), where N is the number of elements present in the given array.
Space complexity: O(N), where N is the number of elements present in the given array.
*/

/*
Using monotonic stack.
*/

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int n = height.size(), ans = 0;
        for(int i=0; i<n; i++){
            while(!s.empty() && height[i] > height[s.top()]){
                int bottom = s.top();
                s.pop();
                if(s.empty()) break;
                int distance = i - s.top() - 1;
                int bounded_height = min(height[i], height[s.top()]) - height[bottom];
                ans += distance * bounded_height;
            }
            s.push(i);
        }
        return ans;
    }
};

/*
Time complexity: O(N), where N is the number of elements present in the given array.
Space complexity: O(N), where N is the number of elements present in the given array.
*/

/*
Not using any extra space. Using 2 pointer approach
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        int left = 0, right = n - 1, left_max = 0, right_max = 0, ans = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max) left_max = height[left];
                else ans += left_max - height[left];
                left++;
            } else {
                if (height[right] >= right_max) right_max = height[right];
                else ans += right_max - height[right];
                right--;
            }
        }
        return ans;
    }
};

/*
Time complexity: O(N), where N is the number of elements present in the given array.
Space complexity: O(1), we are not using any extra space here. Hence, the space complexity is constant. 
*/