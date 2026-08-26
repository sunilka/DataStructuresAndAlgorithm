/*
5. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/

#include<bits/stdc++.h>
using namespace std;

int longestPalindrome(string s) {
    int n = s.size();
    if (n == 0) return 0;
    int max_ans = 1;
    vector<bool> cur(n, false), next(n, false);
    for (int i = n - 1; i >= 0; i--) {
        cur[i] = true;
        for (int j = i + 1; j < n; j++) {
            bool is_inner_palindrome = (j - i <= 2) ? true : next[j - 1];
            if (s[i] == s[j] && is_inner_palindrome) {    
                max_ans = max(max_ans, j - i + 1);
                cur[j] = true;
            } else {
                cur[j] = false;
            }
        }
        next = cur;
    }
    return max_ans;
}

int main(){
    string s = "babad";
    int ans = longestPalindrome(s);
    cout<<"Printing the maximum answer here "<<ans<<endl;
}