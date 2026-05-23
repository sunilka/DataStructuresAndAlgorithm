#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> ans;
        ans.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            } else {
                auto it = lower_bound(ans.begin(), ans.end(), nums[i]);
                *it = nums[i];
            }
        }
        return ans.size();
    }
};
