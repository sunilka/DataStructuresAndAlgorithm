/*
Geek's Training

Geek is going for a training program for n days. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Given a 2D matrix mat[][], where mat[i][0], mat[i][1], and mat[i][2] represent the merit points for Running, Fighting, and Learning on the i-th day, determine the maximum total merit points Geek can achieve .

Example:

Input: mat[][]= [[1, 2, 5],
               [3, 1, 1], 
               [3, 3, 3]]
Output: 11
Explanation: Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum merit point will be 11.
Input: mat[][]= [[1, 1, 1],
               [2, 2, 2],
               [3, 3, 3]]
Output: 6
Explanation: Geek can perform any activity each day while adhering to the constraints, in order to maximize his total merit points as 6.
Input: mat[][]= [[4, 2, 6]]
Output: 6
Explanation: Geek will learn a new move to make his merit points as 6.
Constraint:
1 ≤ n ≤ 105   
1 ≤  arr[i][j] ≤ 100
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    map<pair<int, int>, int> dp;
    int solve(vector<vector<int>>& mat, int m, int prev_choosen_activity, int ridx){
        if(ridx >= m) return 0;
        if(dp.count({prev_choosen_activity, ridx})) return dp[{prev_choosen_activity, ridx}];
        int ans = 0;
        for(int i=0; i<3; i++){
            if(i == prev_choosen_activity) continue;
            ans = max(ans, solve(mat, m, i, ridx+1)+mat[ridx][i]);
        }
        dp[{prev_choosen_activity, ridx}] = ans;
        return ans;
    }
    int maximumPoints(vector<vector<int>>& mat) {
        dp.clear();
        int m = mat.size();
        return solve(mat, m, -1, 0);
    }
};

/*
Time Complexity:  O(N log N)
   - 4 * N total unique states
   - O(3 * log(4N)) work per state for map lookup and insertion

Space Complexity: O(N)
   - O(4N) auxiliary space to store all key-value pairs in the map
   - O(N) recursion stack space
   - Overall = O(4N + N) = O(N)
*/

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        int m = mat.size();
        vector<vector<int>> dp(m+1, vector<int>(4, 0));
        
        for(int r=m-1; r>=0; r--){
            for(int prev=-1; prev<=2; prev++){
                int ans = 0;
                for(int i=0; i<3; i++){
                    if(i == prev) continue;
                    ans = max(ans,dp[r + 1][i + 1] + mat[r][i]);
                }
                dp[r][prev+1] = ans;
            }
        }
        return dp[0][0];
    }
};

/*
Time complexity: O(N)
Space complexity: O(N)
*/
