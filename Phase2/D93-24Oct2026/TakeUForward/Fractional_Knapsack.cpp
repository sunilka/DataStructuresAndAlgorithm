/*
Fractional Knapsack

Given two arrays, val[] and wt[] , representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
Return the maximum value as a double, rounded to 6 decimal places.

Examples :

Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output: 240.000000
Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240
Input: val[] = [500], wt[] = [30], capacity = 10
Output: 166.670000
Explanation: Since the item’s weight exceeds capacity, we take a fraction 10/30 of it, yielding value 166.670000.
Constraints:

val.size() ≤ 105
1 ≤ val[i], wt[i] ≤ 104
1 ≤ capacity ≤ 109
wt.size() = val.size()
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        priority_queue<pair<double, pair<int, int>>> pq;
        int n = val.size();
        for (int i = 0; i < n; i++) {
            double ratio = (double)val[i] / (double)wt[i];
            pq.push({ratio, {val[i], wt[i]}});
        }
        double totalProfit = 0.0;
        while (capacity > 0 && !pq.empty()) {
            auto top = pq.top();
            pq.pop(); 
            double ratio = top.first;
            int itemVal = top.second.first;
            int itemWeight = top.second.second;
            if (itemWeight <= capacity) {
                totalProfit += itemVal;
                capacity -= itemWeight;
            } else {
                totalProfit += capacity * ratio;
                capacity = 0;
            }
        }
        return totalProfit;
    }
};

/*
Time complexity: O(NlogN), for going over the elements and inserting into the priority queue and O(N) for going over the elements 
in priority queue to find the answer.
Space complexity: O(N) where N is the number of elements present.
*/