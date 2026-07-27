/*
Frog Jump

Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the last stair. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the last stair.

Example:

Input: heights[] = [20, 30, 40, 20]
Output: 20
Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
jump from stair 0 to 1: cost = |30 - 20| = 10
jump from stair 1 to 3: cost = |20 - 30| = 10
Total Cost = 10 + 10 = 20
Input: heights[] = [30, 20, 50, 10, 40]
Output: 30
Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
jump from stair 0 to 2: cost = |50 - 30| = 20
jump from stair 2 to 4: cost = |40 - 50| = 10
Total Cost = 20 + 10 = 30
Constraints:
1 ≤ height.size() ≤ 105
0 ≤ height[i] ≤ 104
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        if(n == 1) return 0;
        vector<vector<pair<int, int>>> adjList(n);
        for (int i = 0; i < n - 1; i++) { 
            if (i + 1 < n) {
                adjList[i].push_back({i + 1, abs(height[i] - height[i + 1])});
            }
            if (i + 2 < n) {
                adjList[i].push_back({i + 2, abs(height[i] - height[i + 2])});
            }
        }
        
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            if(node == n-1) return d;
            
            if (d > dist[node]) continue;
            for(int i=0; i<adjList[node].size(); i++){
                int connected_node = adjList[node][i].first, price = adjList[node][i].second;
                if(dist[connected_node] > price+d){
                    dist[connected_node] = price + d;
                    pq.push({price+d, connected_node});
                }
            }
        }
        return -1;
    }
};

/*
Time complexity: O(ElogV), where E is the edges and V is the number of nodes.
Space complexity: O(V+E), where E is the edges and V is the number of nodes.
*/

class Solution {
  public:
    vector<int> dp;
    int calc(vector<int>& height, int n, int i){
        if(i == n-1) return 0;
        if(i >= n ) return INT_MAX;
        if(dp[i]!=-1) return dp[i];
        
        int one_step = calc(height, n, i+1);
        if(one_step != INT_MAX) one_step += abs(height[i] - height[i+1]);
        int two_step = calc(height, n, i+2);
        if(two_step != INT_MAX) two_step += abs(height[i] - height[i+2]);
        int ans = min(one_step, two_step);
        dp[i] = ans;
        return ans;
    }
    int minCost(vector<int>& height) { 
        int n = height.size();
        dp.resize(n, -1);
        return calc(height, n, 0);
    }
};

/*
Time complexity: O(N)
Space complexity: O(N)
*/


/*
Bottoms up DP
*/
class Solution {
  public:
    int minCost(vector<int>& height) { 
        int n = height.size();
        vector<int> dp(n+1, 0);
        dp[n-1] = 0;
        
        for(int i=n-2; i>=0; i--){
            int one_step = dp[i+1];
            if(one_step != INT_MAX) one_step += abs(height[i] - height[i+1]);
            int two_step = INT_MAX;
            if (i + 2 < n) {
                two_step = dp[i + 2] + abs(height[i] - height[i + 2]);
            }
            int ans = min(one_step, two_step);
            dp[i] = ans;
        }
        return dp[0];
    }
};

/*
Time complexity: O(N)
Space complexity: O(N)
*/