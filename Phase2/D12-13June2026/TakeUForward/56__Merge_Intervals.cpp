/*

56. Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
Example 3:

Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int n = intervals.size();
    // Push the first interval into the answer. 
    ans.push_back(intervals[0]);

    for(int i=1; i<n; i++){
        int cs = intervals[i][0], ce = intervals[i][1];
        if( ans[ans.size()-1][1] >=cs ) ans[ans.size()-1][1] = max(ans[ans.size()-1][1], ce);
        else ans.push_back(intervals[i]);
    }
    return ans;
}

int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = merge(intervals);
    cout<<"Printing the answer array here "<<endl;
    for(auto ele: ans){
        for(auto e: ele) cout<<e<<" ";
        cout<<endl;
    }
    cout<<endl;
}

/*

Complexity analysis:

Time complexity: O(NlogN+N) = O(NLogN), where N is the number of elements present in the array.
Space complexity: O(N), we are using N space for storing the answer.
*/