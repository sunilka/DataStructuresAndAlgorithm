class Solution {
public:
    bool check(vector<int>& nums) {
        int count_drops = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Compare the current element to the next one, wrapping around at the end
            if (nums[i] > nums[(i + 1) % n]) {
                count_drops++;
            }
        }
        
        // A valid array will have either 0 drops (already sorted) or 1 drop (rotated)
        return count_drops <= 1;
    }
};