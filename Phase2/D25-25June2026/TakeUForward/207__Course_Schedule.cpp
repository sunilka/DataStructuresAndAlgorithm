/*

207. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 
Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.

*/

#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>& connections, vector<bool>& visited, vector<bool>& pathvisited){
    visited[node] = true;
    pathvisited[node] = true;

    for(int n: connections[node]){
        if(!visited[n]){
            if(dfs(n, connections, visited, pathvisited)) return true;
        }
        else if(pathvisited[n]) return true;
    }
    pathvisited[node] = false;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> connections(numCourses);
    for(auto p: prerequisites){
        int u = p[0], v = p[1];
        connections[v].push_back(u);
    }

    vector<bool> visited(numCourses, false);
    vector<bool> pathvisited(numCourses, false);

    for(int i=0; i<numCourses; i++){
        if(!visited[i]){
            if(dfs(i, connections, visited, pathvisited)) return false;
        }
    }
    return true;
}

int main(){
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0},{0,1}};
    bool ans = canFinish(numCourses, prerequisites);
    cout<<"Printing the answer here "<<ans<<endl;
}   

/* 

Complexity analysis:
Time complexity: O(V+E), where V represents the number of courses and E represents the pre-requisites.
Space complexity: O(V+E),  where V represents the number of courses and E represents the pre-requisites.

*/