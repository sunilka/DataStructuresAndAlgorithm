/*

963. Minimum Area Rectangle II

You are given an array of points in the X-Y plane points where points[i] = [xi, yi].

Return the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the X and Y axes. If there is not any such rectangle, return 0.

Answers within 10-5 of the actual answer will be accepted. 

Example 1:
Input: points = [[1,2],[2,1],[1,0],[0,1]]
Output: 2.00000
Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.

Example 2:
Input: points = [[0,1],[2,1],[1,1],[1,0],[2,0]]
Output: 1.00000
Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.

Example 3:
Input: points = [[0,3],[1,2],[3,1],[1,3],[2,1]]
Output: 0
Explanation: There is no possible rectangle to form from these points.
 
Constraints:

1 <= points.length <= 50
points[i].length == 2
0 <= xi, yi <= 4 * 104
All the given points are unique.

*/

#include<bits/stdc++.h>
using namespace std;

double minAreaFreeRect(vector<vector<int>>& points) {
    int n = points.size();
    unordered_map<string, vector<pair<int, int>>> digonal_map;
    double min_area = DBL_MAX;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            long long midx = points[i][0] + points[j][0];
            long long midy = points[i][1] + points[j][1];
            long long dx = points[j][0] - points[i][0];
            long long dy = points[j][1] - points[i][1];
            long long dist = (dx*dx) + (dy*dy);
            string key = to_string(midx) + "," + to_string(midy) + "," + to_string(dist); 
            digonal_map[key].push_back({i,j});
        }
    }

    for(auto& [key, pairs]: digonal_map){
        if(pairs.size() < 2) continue;

        for(int i=0; i<pairs.size(); i++){
            for(int j=i+1; j<pairs.size(); j++){
                int p1 = pairs[i].first;
                int p2 = pairs[i].second;
                int p3 = pairs[j].first;
                int p4 = pairs[j].second;

                double dx1 = points[p1][0] - points[p3][0];
                double dy1 = points[p1][1] - points[p3][1];
                double L = sqrt(dx1 * dx1 + dy1 * dy1);

                double dx2 = points[p2][0] - points[p3][0];
                double dy2 = points[p2][1] - points[p3][1];
                double B = sqrt(dx2 * dx2 + dy2 * dy2);

                double area = L * B;
                min_area = min(min_area, area);
            }
        }
    }
    return min_area == DBL_MAX ? 0.0 : min_area;
}

int main(){
    vector<vector<int>> points = {{1,2},{2,1},{1,0},{0,1}};
    double ans = minAreaFreeRect(points);
    cout<<"Printing the answer here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(N^2), where N is the number of points given to us.
Space complexity: O(N^2) for the map we have.

*/