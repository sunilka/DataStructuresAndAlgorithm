/*
1048. Longest String Chain

You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool custom(const string &s1, const string &s2){
        return s1.size() < s2.size();
    }
    bool is_predecessor(const string &w1, const string &w2) {
        if (w1.size() + 1 != w2.size()) return false;
        int i = 0, j = 0;
        while (i < w1.size() && j < w2.size()) {
            if (w1[i] == w2[j]) i++;
            j++;
        }
        return i == w1.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size(), max_val = 1;
        sort(words.begin(), words.end(), custom);
        vector<int> dp(n, 1);
        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(is_predecessor(words[j], words[i])){
                    dp[i] = max(dp[i], dp[j]+1);
                    max_val = max(max_val, dp[i]);
                }
            }
        }
        return max_val;
    }
};

/*
Time complexity: O(N^2*max_word_length), where N is the number of elements present in the array and
max_word_length is the length of the maximum word present in the array.
Space complexity: O(N) for the DP array.    
*/