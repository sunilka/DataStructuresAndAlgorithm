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
    static bool custom(string &a, string &b){
        return a.size() < b.size();
    }
    bool can_be_successor(string ps, string cs){
        int n1 = ps.size(), n2 = cs.size(), idx1 = 0, idx2 = 0;
        if(n1+1 != n2) return false;
        while(idx1 < n1 && idx2 < n2){
            if(ps[idx1]!=cs[idx2]) idx2++;
            else idx1++, idx2++;
        }
        return idx1 == n1;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), custom);
        vector<int> dp(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                bool cbs = can_be_successor(words[j], words[i]);
                if(cbs && dp[i] < dp[j]+1) dp[i] = dp[j]+1;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

/*
Time complexity: O(N^2*m), where N is the number of the words present in given array and m is the max length if the 
words given in the array.
Space complexity: O(N)
*/