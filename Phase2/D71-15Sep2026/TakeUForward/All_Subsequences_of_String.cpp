/*
All Subsequences of String

Given a string s, generate all possible subsequences of the string (including the empty subsequence) and return them in lexicographical order.

A subsequence is obtained by deleting zero or more characters from the string without changing the relative order of the remaining characters.

Examples:

Input : s = "abc"
Output: ["", "a", "ab", "abc", "ac", "b", "bc", "c"]
Explanation: There are a total of 8 non-empty subsequences for the given string. 
Input: s = "aa"
Output: ["", "a", "a", "aa"]
Constraints:

1 ≤ s.size() ≤ 16
s contains: [a-z].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(string& s, int &n, int idx, string curs, vector<string>& ans){
        if(idx == n){
            ans.push_back(curs);
            return;
        }
        solve(s, n, idx+1, curs, ans);
        solve(s, n, idx+1, curs+s[idx], ans);
    }
    vector<string> powerSet(string &s) {
        vector<string> ans;
        int n = s.size();
        solve(s, n, 0, "", ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*
Time complexity: O(2^N*N) because at each index we can branch by either taking the character at that index or not taking the 
char at that index, hence 2^N, and the N extra that we have is for the time taken for coping the string (since the curs since 
curs is not passed by reference, if we pass by reference then we would need to backtrack and try other possibilities.), 
and for the sorting we need 2^N log 2^N * N time. 
Space complexity: O(N) auxiliary stack space used here because of the recursion.
*/

/*
Pass by reference and backtracking
*/


class Solution {
  public:
    void solve(string& s, int &n, int idx, string& curs, vector<string>& ans){
        if(idx == n){
            ans.push_back(curs);
            return;
        }
        solve(s, n, idx+1, curs, ans);
        curs.push_back(s[idx]);
        solve(s, n, idx+1, curs, ans);
        curs.pop_back();
    }
    vector<string> powerSet(string &s) {
        vector<string> ans;
        int n = s.size();
        string curs = "";
        solve(s, n, 0, curs, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*
Time complexity: O(2^N*N) and O(2^Nlog(2^N)*N)
Space complexity: O(N) auxiliary stack space used here because of the recursion.
*/
