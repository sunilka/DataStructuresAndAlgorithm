/*

118. Pascal's Triangle

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30

*/

#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    ans.push_back({1});
    if(numRows==1) return ans;

    ans.push_back({1, 1});
    if(numRows == 2) return ans;

    numRows-=2;
    for(int i=0; i<numRows; i++){
        vector<int> a = ans[ans.size()-1];
        vector<int> ta;
        ta.push_back(1);
        for(int j=0; j<a.size()-1; j++) ta.push_back(a[j]+a[j+1]);
        ta.push_back(1);
        ans.push_back(ta);
    } 
    return ans;
}

int main(){
    int numRows = 5;
    vector<vector<int>> ans = generate(numRows);
    cout<<"Printing the answer array here "<<endl;
    for(auto ele: ans){
        cout<<" [ ";
        for(auto e: ele) cout<<e<<" , ";
        cout<<" ] ";
    }
}

/*

Complexity analysis:

Time complexity: O(numRows*numRows)
Space complexity: O(numRows*numRows)

*/