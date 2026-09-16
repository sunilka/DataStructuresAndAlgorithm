/*
17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

1 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char, vector<char>> m = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
    void solve(string& digits, int& n, int idx, string cans, vector<string>& ans){
        if(idx == n){
            ans.push_back(cans);
            return;
        }
        char digit = digits[idx];
        vector<char> mapped_chars = m[digit]; 
        for(int i=0; i<mapped_chars.size(); i++){
            cans.push_back(mapped_chars[i]);
            solve(digits, n, idx+1, cans, ans);
            cans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = digits.size();
        solve(digits, n, 0, "", ans);
        return ans;
    }
};

/*
Time Complexity: O(4^N * N)
- N is the length of the input string digits.
- Each digit maps to up to 4 characters, resulting in up to 4^N combinations.
- At the base case, copying `cans` of length N into `ans` takes O(N) time.

Space Complexity:
- Auxiliary Space: O(N) for recursion call stack and `cans` string.
- Output Space: O(4^N * N) to store all generated letter combinations.
Total Space=O(N+4^N * N)=O(4^N * N)
*/