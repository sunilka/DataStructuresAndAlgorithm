/*
131. Palindrome Partitioning
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_palindrome(string ts){
        int i = 0, j = ts.size() - 1;
        while(i < j){
            if(ts[i] != ts[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string& s, int& n, int idx, vector<string>& cans, vector<vector<string>>& ans){
        if(idx == n){
            ans.push_back(cans);
            return;
        }
        for (int i = idx; i < n; i++) {
            int length = i - idx + 1;
            string ts = s.substr(idx, length);            
            if (is_palindrome(ts)) {
                cans.push_back(ts);
                solve(s, n, i + 1, cans, ans);
                cans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> cans;
        vector<vector<string>> ans;
        int n = s.size();
        solve(s, n, 0, cans, ans);
        return ans;
    }
};

/*
Time complexity: O(2^N * N*N), where 2^N is for the number of nodes in the recursion tree and N is for the palindrome check we do.
Space complexity: O(N) auxiliary stack space and O(2^N*N) for stroing the answer.
*/