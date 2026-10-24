/*
Maximum Meetings in One Room

Given two arrays s[] and f[], where s[i] and f[i] denote the start time and finish time of the ith meeting, respectively. There is only one meeting room. A meeting can be scheduled only if its start time is strictly greater than the finish time of the previously selected meeting.

Find the maximum number of meetings that can be scheduled in the room such that no two selected meetings overlap. Return the indices (1-based) of the selected meetings in sorted (increasing) order.

Note: If multiple schedules are possible, prefer meetings with earlier finish times. If two meetings have the same finish time, prefer the meeting with the smaller index.

Examples:

Input: s[] = [1, 3, 0, 5, 8, 5], f[] = [2, 4, 6, 7, 9, 9] 
Output: [1, 2, 4, 5]
Explanation: We can attend the 1st meeting from (1 to 2), then the 2nd meeting from (3 to 4), then the 4th meeting from (5 to 7), and the last meeting we can attend is the 5th from (8 to 9). It can be shown that this is the maximum number of meetings we can attend.
Input: s[] = [3], f[] = [7]
Output: [1]
Explanation: Since there is only one meeting, we can attend the meeting.
Constraints:
1 ≤ s.size() = f.size() ≤ 105
0 ≤ s[i] ≤ f[i] ≤ 109
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    static bool comparator(pair<int, pair<int, int>> info1, pair<int, pair<int, int>> info2){
        if (info1.second.second != info2.second.second) {
            return info1.second.second < info2.second.second;
        }
        return info1.first < info2.first;
    }
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        vector<pair<int, pair<int, int>>> meeting_info;
        int n = s.size();
        for(int i=0; i<n; i++) meeting_info.push_back({i+1, {s[i], f[i]}});
        sort(meeting_info.begin(), meeting_info.end(), comparator);
        int prev_finish_time = -1;
        vector<int> ans;
        for(auto info: meeting_info){
            int cur_index = info.first;
            int cur_start_time = info.second.first;
            int cur_end_time = info.second.second;
            if(prev_finish_time == -1 || cur_start_time > prev_finish_time){
                ans.push_back(cur_index);
                prev_finish_time = cur_end_time;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*
Time complexity: O(NlogN), where N is the number of elements present in the given array.
Space complexity: O(N)
*/