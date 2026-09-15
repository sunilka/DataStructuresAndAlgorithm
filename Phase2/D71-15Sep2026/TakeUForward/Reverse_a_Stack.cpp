/*
Reverse a Stack
You are given a stack st[]. You have to reverse the stack.

Note: The input array represents the stack from bottom to top (last element is the top). The output is displayed by printing elements from top to bottom after reversal.

Examples:

Input: st[] = [1, 2, 3, 4]
Output: [1, 2, 3, 4]
Explanation: After reversing, the elements of stack are in opposite order.

Input: st[] = [3, 2, 1]
Output: [3, 2, 1]
Explanation: After reversing, the elements of stack are in opposite order.

Constraints:
1 ≤ st.size() ≤ 100
0 ≤ stack element ≤ 100
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void insert(stack<int> &st, int ele){
        if(st.empty()){
            st.push(ele);
            return;
        }
        int top_ele = st.top();
        st.pop();
        insert(st, ele);
        st.push(top_ele);
    }
    void solve(stack<int> &st){
        if(!st.empty()){
            int ele = st.top();
            st.pop();
            solve(st);
            insert(st, ele);
        }
    }
    void reverseStack(stack<int> &st) {
        solve(st);
    }
};

/*
Time complexity: O(N*N), where N is the number of elements present in the given stack.
Space complexity: O(N+N) = O(2N) = O(N) auxiliaxy stack space.
*/