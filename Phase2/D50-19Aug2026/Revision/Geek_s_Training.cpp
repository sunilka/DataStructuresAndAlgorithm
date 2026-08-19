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
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n+1, vector<int>(4, 0));
        for(int day=n-1; day>=0; day--){
            for(int pgi=-1; pgi<3; pgi++){
                int ans = 0;
                for(int i=0; i<3; i++){
                    if(i != pgi){
                        ans = max(ans, dp[day+1][i+1] + mat[day][i]);
                    }
                }
                dp[day][pgi+1] = ans;
            }
        }
        return dp[0][0];
    }
};

/*
Stack Space Eliminated: By replacing recursion with iteration, you reduced the auxiliary call stack space from O(N) to O(1).
Total Space Complexity: Purely O(N) due to the 2D DP matrix of size (N+1)×4.
Total Time Complexity: Remains O(N) since you visit each state (N×4) once and do a constant 3 iterations inside.
*/

/*
Space optimization.
*/

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> next(4, 0), cur(4, 0);
        for(int day=n-1; day>=0; day--){
            for(int pgi=-1; pgi<3; pgi++){
                int ans = 0;
                for(int i=0; i<3; i++){
                    if(i != pgi){
                        ans = max(ans, next[i+1] + mat[day][i]);
                    }
                }
                cur[pgi+1] = ans;
            }
            next = cur;
        }
        return next[0];
    }
};

/*
Total Time Complexity: Remains O(N) since you visit each state (N×4) once and do a constant 3 iterations inside.
Space complexity: O(4) space complexity. O(1) constant space.
*/