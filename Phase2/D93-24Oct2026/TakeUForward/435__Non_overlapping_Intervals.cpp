/*
435. Non-overlapping Intervals
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool solver(const vector<int>& info1, const vector<int>& info2){
        return info1[1] < info2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), solver);
        int count_kept = 0, n = intervals.size();
        long long prev_end_time = LLONG_MIN;
        for(int i = 0; i < n; i++){
            int cur_start_time = intervals[i][0];
            int cur_end_time = intervals[i][1];
            if(prev_end_time == LLONG_MIN || cur_start_time >= prev_end_time){
                count_kept++;
                prev_end_time = cur_end_time;
            }
        }
        return n - count_kept;
    }
};

/*
Time complexity: O(NlogN), where N is the number of elements present in the given array.
Space complexity: O(1).
*/