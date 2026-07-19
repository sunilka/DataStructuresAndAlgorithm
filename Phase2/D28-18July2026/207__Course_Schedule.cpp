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

bool dfs(int numCourses, int node, vector<vector<int>>& adjList, vector<bool>& visited, vector<bool>& pathVisited){
    visited[node] = true;
    pathVisited[node] = true;

    for(int i=0; i<adjList[node].size(); i++){
        int connected_node = adjList[node][i];
        if(pathVisited[connected_node] == true) return true;
        if(visited[connected_node] == false){
            if(dfs(numCourses, connected_node, adjList, visited, pathVisited)) return true;
        }
    }
    pathVisited[node] = false;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adjList(numCourses);
    vector<bool> visited(numCourses, false);
    vector<bool> pathVisited(numCourses, false);

    for(int i=0; i<prerequisites.size(); i++){
        int u = prerequisites[i][0], v = prerequisites[i][1];
        adjList[v].push_back(u);
    }

    for(int i=0; i<numCourses; i++){
        if(visited[i] == false){
            bool cycleExists = dfs(numCourses, i, adjList, visited, pathVisited);
            if(cycleExists) return false;
        }
    }
    return true;
}

/*
Time complexity: O(V+E), where V is the number of vertices present in the graph and E is the number of edges present in the graph.
Space complexity: O(V+E), where V is the number of vertices present in the graph and E is the number of edges present in the graph.
*/

// Khan's algorithm.
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adjList(numCourses);
    vector<int> indegree(numCourses, 0);
    for(int i=0; i<prerequisites.size(); i++){
        int u = prerequisites[i][0], v = prerequisites[i][1];
        adjList[v].push_back(u);
        indegree[u]++;
    }

    queue<int> q;
    for(int i=0; i<numCourses; i++){
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for(int i=0; i<adjList[node].size(); i++){
            int connected_node = adjList[node][i];
            indegree[connected_node]-=1;
            if(indegree[connected_node] == 0) q.push(connected_node);
        }
    }

    if(ans.size() == numCourses){
        return true;
        
    return false;
}

int main(){
    int numCourses;
    vector<vector<int>> prerequisites;
    bool ans = canFinish(numCourses, prerequisites);
    cout<<"Printing my answer here "<<ans<<endl;
}

/*
Time complexity: O(V+E), where V is the number of vertices present in the graph and E is the number of edges present in the graph.
Space complexity: O(V+E), where V is the number of vertices present in the graph and E is the number of edges present in the graph.
*/
