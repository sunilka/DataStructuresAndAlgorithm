/*

Leaders in an Array

16

Problem Statement: .

Examples
Example 1:
Input:
 arr = [4, 7, 1, 0]  
Output:
 7 1 0  
Explanation:
 The rightmost element (0) is always a leader.  
7 and 1 are greater than the elements to their right, making them leaders as well.

Example 2:
Input:
 arr = [10, 22, 12, 3, 0, 6]  
Output:
 22 12 6  
Explanation:
 6 is a leader because there are no elements after it.  
12 is greater than all the elements to its right (3, 0, 6), and 22 is greater than 12, 3, 0, 6, making them leaders as well.

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int>& arr){
    stack<int> s;
    int n = arr.size();
    vector<int> ans;
    for(int i=n-1; i>=0; i--){
        if(s.empty()) s.push(arr[i]);
        else if(arr[i] >= s.top()) s.push(arr[i]);
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main(){
    vector<int> arr = {4, 7, 1, 0};
    vector<int> ans = leaders(arr);
    cout<<"Printing the answer here "<<endl;
    for(auto ele: ans) cout<<ele<<" ";
}

/*

Complexity analysis:

Time complexity: O(N), where N is the number of elements present in the array.
Space complexity: O(N), for the stack that we are using, N is the number of elements present in the array.

*/