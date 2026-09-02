/*
1547. Minimum Cost to Cut a Stick
Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:
Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.

Example 1:


Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:

The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).
Example 2:

Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.
 

Constraints:

2 <= n <= 106
1 <= cuts.length <= min(n - 1, 100)
1 <= cuts[i] <= n - 1
All the integers in cuts array are distinct.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& cuts, int i, int j){
        if(i+1 >= j) return 0; // the rod length is just 1, we cannot make any cuts and hence we return 0;
        int mini = INT_MAX;
        for(int k=0; k<cuts.size(); k++){
            if(cuts[k] > i && cuts[k]<j){
                int cost = solve(cuts, i, cuts[k]) + solve(cuts, cuts[k], j) + (j-i);
                mini = min(cost, mini);
            }
        }
        return (mini == INT_MAX) ? 0: mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        return solve(cuts, 0, n);
    }
};

/*
Time complexity: O(CSLogCS + CS!), where CS is the size of the CS array and N is the length of the rod.
Space complexity: O(C) auxiliary stack space.
*/

/*
Top down memoization.
*/

class Solution {
public:
    int solve(vector<int>& cuts, int i, int j, vector<vector<int>>& dp){
        if(i + 1 >= j) return 0; 
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k = i + 1; k < j; ++k){
            int cost = solve(cuts, i, k, dp) + solve(cuts, k, j, dp) + (cuts[j] - cuts[i]);
            mini = min(cost, mini);
        }
        return dp[i][j] = (mini == INT_MAX) ? 0 : mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return solve(cuts, 0, m - 1, dp);
    }
};

/*
Time complexity: O(C^3), where C is the number of elements present in the cuts array.
Space complexity: O(C^2) for the DP array and O(C) auxiliary stack space.
*/

/*
Bottom up DP - tabulation method.
*/

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, 0));
        for(int i=m-1; i>=0; i--){
            for(int j=i+2; j<m; j++){
                int mini = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    int cost = (cuts[j] - cuts[i]) + dp[i][k] + dp[k][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[0][m-1];
    }
};

/*
Time complexity: O(CS^3), where CS is the number of elements present in the cuts array.
Space complexity: O(CS^2) for the DP array and please note here that we are not using any extra auxiliary stack 
space here.
*/