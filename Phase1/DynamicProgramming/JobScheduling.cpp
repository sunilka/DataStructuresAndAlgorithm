// https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> jobs;
    vector<int> dp;

    int findNextJob(int currentIndex) {
        int low = currentIndex + 1;
        int high = jobs.size() - 1;
        int nextIndex = jobs.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (jobs[mid][0] >= jobs[currentIndex][1]) {
                nextIndex = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return nextIndex;
    }

    int calc(int pos) {
        if (pos >= jobs.size())
            return 0;

        if (dp[pos] != -1)
            return dp[pos];

        int nextJob = findNextJob(pos);

        int take = jobs[pos][2] + calc(nextJob);
        int skip = calc(pos + 1);

        return dp[pos] = max(take, skip);
    }

    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {

        int n = startTime.size();

        jobs.resize(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end());  

        dp.assign(n, -1);

        return calc(0);
    }
};