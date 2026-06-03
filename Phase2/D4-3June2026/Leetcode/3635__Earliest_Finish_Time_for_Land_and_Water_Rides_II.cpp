/*

3635. Earliest Finish Time for Land and Water Rides II

You are given two categories of theme park attractions: land rides and water rides.

Land rides
landStartTime[i] – the earliest time the ith land ride can be boarded.
landDuration[i] – how long the ith land ride lasts.
Water rides
waterStartTime[j] – the earliest time the jth water ride can be boarded.
waterDuration[j] – how long the jth water ride lasts.
A tourist must experience exactly one ride from each category, in either order.

A ride may be started at its opening time or any later moment.
If a ride is started at time t, it finishes at time t + duration.
Immediately after finishing one ride the tourist may board the other (if it is already open) or wait until it opens.
Return the earliest possible time at which the tourist can finish both rides.

 

Example 1:

Input: landStartTime = [2,8], landDuration = [4,1], waterStartTime = [6], waterDuration = [3]

Output: 9

Explanation:​​​​​​​

Plan A (land ride 0 → water ride 0):
Start land ride 0 at time landStartTime[0] = 2. Finish at 2 + landDuration[0] = 6.
Water ride 0 opens at time waterStartTime[0] = 6. Start immediately at 6, finish at 6 + waterDuration[0] = 9.
Plan B (water ride 0 → land ride 1):
Start water ride 0 at time waterStartTime[0] = 6. Finish at 6 + waterDuration[0] = 9.
Land ride 1 opens at landStartTime[1] = 8. Start at time 9, finish at 9 + landDuration[1] = 10.
Plan C (land ride 1 → water ride 0):
Start land ride 1 at time landStartTime[1] = 8. Finish at 8 + landDuration[1] = 9.
Water ride 0 opened at waterStartTime[0] = 6. Start at time 9, finish at 9 + waterDuration[0] = 12.
Plan D (water ride 0 → land ride 0):
Start water ride 0 at time waterStartTime[0] = 6. Finish at 6 + waterDuration[0] = 9.
Land ride 0 opened at landStartTime[0] = 2. Start at time 9, finish at 9 + landDuration[0] = 13.
Plan A gives the earliest finish time of 9.

Example 2:

Input: landStartTime = [5], landDuration = [3], waterStartTime = [1], waterDuration = [10]

Output: 14

Explanation:​​​​​​​

Plan A (water ride 0 → land ride 0):
Start water ride 0 at time waterStartTime[0] = 1. Finish at 1 + waterDuration[0] = 11.
Land ride 0 opened at landStartTime[0] = 5. Start immediately at 11 and finish at 11 + landDuration[0] = 14.
Plan B (land ride 0 → water ride 0):
Start land ride 0 at time landStartTime[0] = 5. Finish at 5 + landDuration[0] = 8.
Water ride 0 opened at waterStartTime[0] = 1. Start immediately at 8 and finish at 8 + waterDuration[0] = 18.
Plan A provides the earliest finish time of 14.​​​​​​​

 

Constraints:

1 <= n, m <= 5 * 104
landStartTime.length == landDuration.length == n
waterStartTime.length == waterDuration.length == m
1 <= landStartTime[i], landDuration[i], waterStartTime[j], waterDuration[j] <= 105

*/

#include<bits/stdc++.h>
using namespace std;

int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

    // Land -> Water
    int ln = landStartTime.size(), wn = waterStartTime.size();
    int min_land_finish = INT_MAX;
    for(int i=0; i<ln; i++) min_land_finish = min(min_land_finish, landStartTime[i]+landDuration[i]);

    int ans1 = INT_MAX;
    for(int i=0; i<wn; i++){
        int st = waterStartTime[i], d = waterDuration[i];
        int total_finish = max(min_land_finish, st) + d;
        ans1 = min(ans1, total_finish);
    }

    // Water -> Land
    int min_water_finish = INT_MAX;
    for(int i=0; i<wn; i++) min_water_finish = min(min_water_finish, waterStartTime[i]+waterDuration[i]);

    int ans2 = INT_MAX;
    for(int i=0; i<ln; i++){
        int st = landStartTime[i], d = landDuration[i];
        int total_finish = max(min_water_finish, st) + d;
        ans2 = min(ans2, total_finish);
    }

    return min(ans1, ans2);
} 

int main(){
    vector<int> landStartTime = {2,8};
    vector<int> landDuration = {4,1};
    vector<int> waterStartTime = {6};
    vector<int> waterDuration = {3};
    int ans = earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);
    cout<<"Printing the answer here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity = O(L + W) + O(W+L), where L is the number of land rides and W is the number of water rides.
Space complexity = O(1), we are not using any extra space here

*/