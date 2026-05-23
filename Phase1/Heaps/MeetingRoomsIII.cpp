// https://leetcode.com/problems/meeting-rooms-iii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        // Min heap for available meeting rooms (smallest room ID first)
        priority_queue<int, vector<int>, greater<int>> meeting_rooms;

        // Min heap for scheduled meetings: (end_time, room_id)
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> scheduled_meetings;

        // Count how many meetings each room handled
        vector<long long> meeting_room_to_counter_map(n, 0);

        // Step 1: populate available rooms
        for (int i = 0; i < n; i++) {
            meeting_rooms.push(i);
        }

        // Step 2: sort meetings by start time
        sort(meetings.begin(), meetings.end());

        // Step 3: process each meeting
        for (int i = 0; i < meetings.size(); i++) {

            long long start = meetings[i][0];
            long long end   = meetings[i][1];
            long long duration = end - start;

            // Free all rooms whose meetings ended before or at current start
            while (!scheduled_meetings.empty() &&
                   scheduled_meetings.top().first <= start) {

                int room_id = scheduled_meetings.top().second;
                scheduled_meetings.pop();
                meeting_rooms.push(room_id);
            }

            // Case 1: we have an available room
            if (!meeting_rooms.empty()) {

                int room_id = meeting_rooms.top();
                meeting_rooms.pop();

                meeting_room_to_counter_map[room_id]++;

                scheduled_meetings.push({end, room_id});
            }
            // Case 2: no available room → delay meeting
            else {

                auto earliest = scheduled_meetings.top();
                scheduled_meetings.pop();

                long long earliest_end = earliest.first;
                int room_id = earliest.second;

                long long new_end = earliest_end + duration;

                meeting_room_to_counter_map[room_id]++;

                scheduled_meetings.push({new_end, room_id});
            }
        }

        // Step 4: find room with maximum meetings
        long long maxCount = -1;
        int answer = 0;

        for (int i = 0; i < n; i++) {
            if (meeting_room_to_counter_map[i] > maxCount) {
                maxCount = meeting_room_to_counter_map[i];
                answer = i;
            }
        }

        return answer;
    }
};