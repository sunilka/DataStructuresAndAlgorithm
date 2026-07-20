/*

Alien Dictionary

A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.
Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

Examples:

Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
Output: true
Explanation: A possible correct order of letters in the alien dictionary is "bdac".
The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
So, 'b' → 'd' → 'a' → 'c' is a valid ordering.
Input: words[] = ["caa", "aaa", "aab"]
Output: true
Explanation: A possible correct order of letters in the alien dictionary is "cab".
The pair "caa" and "aaa" suggests 'c' appears before 'a'.
The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary. 
So, 'c' → 'a' → 'b' is a valid ordering.
Input: words[] = ["ab", "cd", "ef", "ad"]
Output: ""
Explanation: No valid ordering of letters is possible.
The pair "ab" and "ef" suggests "a" appears before "e".
The pair "ef" and "ad" suggests "e" appears before "a", which contradicts the ordering rules.
Constraints:
1 ≤ words.length ≤ 500
1 ≤ words[i].length ≤ 100
words[i] consists only of lowercase English letters.


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findOrder(vector<string> &words) {
        vector<bool> present(26, false);
        int uniqueCharCount = 0;
        int n = words.size();
        
        for(int i=0; i<n; i++){
            for(char ch : words[i]) {
                if(!present[ch - 'a']) {
                    present[ch - 'a'] = true;
                    uniqueCharCount++;
                }
            }
        }
        
        vector<vector<int>> adjList(26);
        vector<int> indegree(26, 0);
        
        for(int i=0; i<=n-2; i++){
            string s1 = words[i], s2 = words[i+1];
            
            if (s1.length() > s2.length() && s1.compare(0, s2.length(), s2) == 0) {
                return "";
            }
            
            int len = min(s1.length(), s2.length());
            for(int j=0; j<len; j++){
                if(s1[j] != s2[j]){
                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';
                    adjList[u].push_back(v);
                    indegree[v]+=1;
                    break;
                }
            }
        }
        
        vector<int> ans;
        queue<int> q;
        
        for(int i=0; i<26; i++){
            if(present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            
            for(int i=0; i<adjList[node].size(); i++){
                int connected_node = adjList[node][i];
                indegree[connected_node]-=1;
                if(indegree[connected_node] == 0) q.push(connected_node);
            }
        }
        if(ans.size() != uniqueCharCount) return "";
        string sans = "";
        for(int i=0; i<ans.size(); i++) {
            sans += (char)('a' + ans[i]);
        }
        return sans;
    }
};

/*
Time complexity: O(N*K+(V+E)), where N is the number of words given and K is the number of characters in each word, V is the number of unique characters (which becomes thew vertices) and
E is the number of edges.
Space complexity: O(V+E), where V is the number of vertices and the E is the number of edges.
*/