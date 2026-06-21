/*
Minimize Max Distance to Gas Station

We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[n-1]. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 6 decimal places.
Note: stations is in a strictly increasing order.

Examples:

Input: stations[] = [1, 2, 3, 4, 5], k = 2
Output: 1.00
Explanation: Since all gaps are already equal (1 unit each), adding extra stations in between does not reduce the maximum distance.
Input: stations[] = [3, 6, 12, 19, 33], k = 3
Output: 6.00 
Explanation: The largest gap is 14 (between 19 and 33). Adding 2 stations there splits it into approx 4.67. The next largest gap is 7 (between 12 and 19). Adding 1 station splits it into 3.5. Now the maximum gap left is 6.
Constraint:
1 ≤ stations.size() ≤ 105
0 ≤ stations[i] ≤ 106
0 ≤ k ≤ 105

*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stations, double mid, int K) {
    int stations_used = 0;
    int n = stations.size();
    
    for (int i = 0; i < n - 1; i++) {
        double gap = stations[i+1] - stations[i];
        stations_used += floor(gap / mid);
    }
    
    return stations_used <= K;
}

double minMaxDist(vector<int> &stations, int K) {
    int n = stations.size();
    double low = 0.0;
    double high = 0.0;
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (double)(stations[i+1] - stations[i]));
    }
    while (high - low > 1e-7) {
        double mid = low + (high - low) / 2.0;
        if (isPossible(stations, mid, K)) {
            high = mid; 
        } else {
            low = mid; 
        }
    }
    return low; 
}

int main() {
    vector<int> stations = {3, 6, 12, 19, 33};
    int k = 3;
    cout << "Printing my answer here: " << minMaxDist(stations, k) << endl; 
    return 0;
}

/* 

Complexity analysis:

Time complexity: O(Nlog(max_gap)), where the max_gap represents the maximum possible gap present between the given stations and N is the number of elements given in the array.
Space complexity: O(1), we are not using any extra space, hence the space complexity is constant.

*/