/*
139. Word Break
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool can_split(string& s, int idx, int i, unordered_set<string>& wordSet){
        string ts = s.substr(idx, i - idx + 1);
        if(wordSet.count(ts)) return true;
        return false;
    }
    bool solve(string& s, int& n, int idx, unordered_set<string>& wordSet, vector<int>& dp){
        if(idx == n) return true;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=idx; i<n; i++){
            if(can_split(s, idx, i, wordSet)){
                if(solve(s, n, i+1, wordSet,dp)) return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> dp(n+1, -1);
        return solve(s, n, 0, wordSet, dp);
    }
};

/*
Time complexity: O(N^2*L), where N is the length of the given string s and L is the time for the substring operations.
Space complexity: O(N) space is used for the DP array and O(N) auxiliary stack space is used beacuse of the recusion and 
O(W⋅L) memory to store all words from wordDict. 
*/