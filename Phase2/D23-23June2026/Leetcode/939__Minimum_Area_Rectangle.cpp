/*

939. Minimum Area Rectangle

You are given an array of points in the X-Y plane points where points[i] = [xi, yi].

Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.

Example 1:

Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4
Example 2:


Input: points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2
 
Constraints:

1 <= points.length <= 500
points[i].length == 2
0 <= xi, yi <= 4 * 104
All the given points are unique.

*/

#include<bits/stdc++.h>
using namespace std;

int minAreaRect(vector<vector<int>>& points) {
    set<pair<int, int>> ps;
    int ans = INT_MAX, n = points.size();
    sort(points.begin(), points.end());
    for(auto point: points) ps.insert({point[0], point[1]});

    for(int i=0; i<n; i++){
        int p1x = points[i][0], p1y = points[i][1];
        for(int j=i+1; j<n; j++){
            if(points[j][0]==p1x || points[j][1]==p1y) continue;
            int p3x = points[j][0], p3y = points[j][1];
            if(ps.count({p3x, p1y}) && ps.count({p1x, p3y})){
                int p2x = p3x, p2y = p1y, p4x = p1x, p4y = p3y;
                int area = abs(p3x - p4x) * abs(p3y - p1y);
                ans = min(ans, area);
            }
        }
    }
    return ans == INT_MAX? 0: ans;
}

int main(){
    vector<vector<int>> points = {{1,1},{1,3},{3,1},{3,3},{2,2}};
    int ans = minAreaRect(points);
    cout<<"Printing the minimum answer here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(nlogn+ n^2logn) = O(n^2logn), where n is the number of elements present in the array. We need nlogn to sort the elements out, and n^2 to pick two points of the diagonal to find the area 
and also the set lookup inside the loop takes logn time. 
Space complexity: O(n), where n is the number of elements present in the set and this is the space used by the set we have. 

*/