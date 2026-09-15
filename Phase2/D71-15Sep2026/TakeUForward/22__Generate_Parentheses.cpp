/*
22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool _is_valid_string(string s){
        stack<char> st;
        int n = s.size();
        for(auto ch: s){
            if(ch == '(') st.push(ch);
            else{
                if(st.empty()) return false;
                else if(st.top() != '(') return false;
                st.pop();
            }
        }
        if(st.empty()) return true;
        return false;
    }
    void solve(int &n, string s, vector<string>& ans){
        if(s.length() == 2*n){
            if(_is_valid_string(s)) ans.push_back(s);
            return;
        }
        if(s.length() > 2*n) return;
        // Insert the '(' braces.
        s = s + '(';
        solve(n, s, ans);
        // Back track and pop the last ( that we inserted.
        s.pop_back();
        // Insert the ')' braces.
        s = s + ')';
        solve(n, s, ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, "", ans);
        return ans;
    }
};

/*
Time complexity: o(2^(2*N)*N), where N is the given n value.
Space complexity: O(N) recursion stack space.
*/