/*
Sort a stack
Given a stack of integers st[]. Sort the stack in ascending order (smallest element at the bottom and largest at the top).

Examples:

Input: st[] = [41, 3, 32, 2, 11]
Output: [41, 32, 11, 3, 2]
Explanation: After sorting, the smallest element (2) is at the bottom and the largest element (41) is at the top.

Input: st[] = [3, 2, 1]
Output: [3, 2, 1]
Explanation: The stack is already sorted in ascending order.

Constraints:

1 ≤ st.size(), st[i] ≤ 103
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void insert(stack<int>& st, int ele){
        if(st.empty()){
            st.push(ele);
            return;
        }
        if(st.top() <= ele){
            st.push(ele);
            return;
        }
        int top_ele = st.top();
        st.pop();
        insert(st, ele);
        st.push(top_ele);
        return;
    }
    void solve(stack<int> &st){
        if(!st.empty()){
            int ele = st.top();
            st.pop();
            solve(st);
            insert(st, ele);
        }
    }
    void sortStack(stack<int> &st) {
        solve(st);
    }
};

/*
Time complexity: O(N*N), where N is the number of elements present in the given stack.
Space complexity: O(N+N) = O(2N) = O(N) auxiliaxy stack space.
*/