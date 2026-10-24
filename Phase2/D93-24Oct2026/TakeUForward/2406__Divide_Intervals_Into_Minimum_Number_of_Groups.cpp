/*
2406. Divide Intervals Into Minimum Number of Groups
You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti].

You have to divide the intervals into one or more groups such that each interval is in exactly one group, and no two intervals that are in the same group intersect each other.

Return the minimum number of groups you need to make.

Two intervals intersect if there is at least one common number between them. For example, the intervals [1, 5] and [5, 8] intersect.


Example 1:

Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
Output: 3
Explanation: We can divide the intervals into the following groups:
- Group 1: [1, 5], [6, 8].
- Group 2: [2, 3], [5, 10].
- Group 3: [1, 10].
It can be proven that it is not possible to divide the intervals into fewer than 3 groups.
Example 2:

Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
Output: 1
Explanation: None of the intervals overlap, so we can put all of them in one group.
 

Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
1 <= lefti <= righti <= 106
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<>> pq;
        for(int i = 0; i < n; i++){
            int cur_start = intervals[i][0];
            int cur_end = intervals[i][1];
            if(!pq.empty() && cur_start > pq.top()) {
                pq.pop(); 
            }
            pq.push(cur_end);
        }
        return pq.size();
    }
};

/*
Time complexity: O(NlogN).
Space complexity: O(N)
*/

// Approach 2
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> event_count;
        
        for (const auto& interval : intervals) {
            event_count[interval[0]]++;
            event_count[interval[1] + 1]--; 
        }
        
        int max_groups = 0;
        int current_active_groups = 0;
        
        for (auto const& [time, change] : event_count) {
            current_active_groups += change;
            max_groups = max(max_groups, current_active_groups);
        }
        
        return max_groups;
    }
};

/*
Time complexity: O(NlogN).
Space complexity: O(N)
*/
