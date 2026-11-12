/*
3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 105
s consists of English letters, digits, symbols and spaces.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int low = 0, high = 0, n = str.size(), ans = 0;
        unordered_set<char> s;
        while(high < n){
            while(s.count(str[high])){
                s.erase(str[low]);
                low++;
            }
            s.insert(str[high]);
            ans = max(ans, high - low+1);
            high+=1;
        }
        return ans;
    }
};

/*
Time complexity: O(N), where N is the number of characters present in the given string.
Space complexity: O(N)
*/