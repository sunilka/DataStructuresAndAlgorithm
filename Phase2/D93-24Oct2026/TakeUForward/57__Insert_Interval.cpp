/*
57. Insert Interval
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Two intervals are considered overlapping if they share at least one point.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()){
            return {newInterval};
        }
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int total_intervals = intervals.size();
        for(int i = 1; i < total_intervals; i++){
            int cur_start = intervals[i][0];
            int cur_end = intervals[i][1];
            int prev_end = ans.back()[1];
            if(cur_start > prev_end) ans.push_back(intervals[i]);
            else ans.back()[1] = max(prev_end, cur_end);
        }
        return ans;
    }
};

/*
Time complexity: O(NlogN), where N is the number of elements present in the given array.
Space complexity: O(N) for the answer array
*/