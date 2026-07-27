/*
70. Climbing Stairs
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> dp;
    int calc(int destination, int cur_step){
        if(cur_step == destination) return 1;
        if(cur_step > destination) return 0;
        if(dp.count(cur_step)) return dp[cur_step];
        else{
            int ans = calc(destination, cur_step+1) + calc(destination, cur_step+2);
            dp[cur_step] = ans;
            return ans;
        }
    }
    int climbStairs(int n) {
        return calc(n, 0);
    }
};

/*
General formula: Time complexity: Number of unique states of the DP * work done per state.

Here, the number of unique states of the DP is N+1 (since we have cur_step in the recursive function call and we are going from 0...N, since we are 
starting from 0, we have to include N+1) and the work done per state is constant. 
Time complexity: O(N+1) = O(N)
Space complexity: O(N+1) = O(N)
*/

class Solution {
public:
    vector<int> dp;
    int calc(int destination, int cur_step){
        if(cur_step == destination) return 1;
        if(cur_step > destination) return 0;
        if(dp[cur_step]!=-1) return dp[cur_step];
        else{
            int ans = calc(destination, cur_step+1) + calc(destination, cur_step+2);
            dp[cur_step] = ans;
            return ans;
        }
    }
    int climbStairs(int n) {
        dp.resize(n+1, -1);
        return calc(n, 0);
    }
};

/*
General formula: Time complexity: Number of unique states of the DP * work done per state.

Here, the number of unique states of the DP is N+1 (since we have cur_step in the recursive function call and we are going from 0...N, since we are 
starting from 0, we have to include N+1) and the work done per state is constant. 
Time complexity: O(N+1) = O(N)
Space complexity: O(N+1) = O(N)
*/

/*
Bottoms up DP.
*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for(int i=n-1; i>=0; i--){
            int take1 = dp[i+1];
            int take2 = (i+2<=n)? dp[i+2]: 0;
            dp[i] = take1 + take2;
        }
        return dp[0];
    }
};

/*
Time complexity: O(N+1) = O(N)
Space complexity: O(N+1) = O(N)
*/

/*
Here are the 4 crisp points:

1. **Table:** Declare a `dp` table sized to fit all possible values of your changing recursive variables.
2. **Base Cases:** Copy your recursive base cases directly into the corresponding `dp` array indices.
3. **Loop & Recurrence:** Loop in the direction of solved dependencies, replacing recursive calls with `dp[...]` lookups.
4. **Answer:** Return the `dp` index that corresponds to your initial recursion call.

*/