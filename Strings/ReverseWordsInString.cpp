// https://leetcode.com/problems/reverse-words-in-a-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Remove leading, trailing, and extra spaces
    void cleanSpaces(string &s) {
        int n = s.size();
        int i = 0, j = 0;

        // Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        while (i < n) {
            // Copy non-space characters
            if (s[i] != ' ') {
                s[j++] = s[i++];
            }
            else {
                // Insert only one space between words
                s[j++] = ' ';
                while (i < n && s[i] == ' ') i++;
            }
        }

        // Remove trailing space if present
        if (j > 0 && s[j - 1] == ' ') j--;

        s.resize(j);
    }

    string reverseWords(string s) {
        cleanSpaces(s);

        // Reverse entire string
        reverse(s.begin(), s.end());

        // Reverse each word
        int start = 0;
        for (int end = 0; end <= s.size(); end++) {
            if (end == s.size() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

        return s;
    }
};