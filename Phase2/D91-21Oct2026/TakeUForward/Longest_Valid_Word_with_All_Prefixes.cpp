/*
Longest Valid Word with All Prefixes

Given an array of strings words[], find the longest string such that every prefix of it is also present in words[]. If multiple strings have the same maximum length, return the lexicographically smallest one.

If no such string is found, return an empty string.

Examples:

Input: words[] = ["p", "pr", "pro", "probl", "problem", "pros", "process", "processor"]
Output: "pros" 
Explanation: "pros" is the longest word with all prefixes ("p", "pr", "pro", "pros") present.
Input: words[] = ["geeks", "gfg", "geeksforgeeks"]
Output: ""
Explanation: No valid strings for all their prefixes present in the words array.
Constraints:
1 <= words.size <= 1000
1 <= words[i].size <= 100
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:  
    struct TrieNode{
        vector<TrieNode*> children;
        bool is_end;
        TrieNode(){
            children.resize(26, nullptr);
            is_end = false;
        }
    };
    TrieNode *root = nullptr;
    void insert_word(string word){
        if(root == nullptr) root = new TrieNode();
        TrieNode *temp = root;
        for(auto ch: word){
            int idx = ch - 'a';
            if(temp->children[idx] == nullptr) temp->children[idx] = new TrieNode();
            temp = temp->children[idx];
        }
        temp->is_end = true;
    }
    bool check_string(string word){
        TrieNode *temp = root;
        for(auto ch: word){
            int idx = ch - 'a';
            if (temp->children[idx] == nullptr) return false;
            temp = temp->children[idx];
            if (temp->is_end == false) return false;
        }
        return true;
    }
    static bool comparator(string s1, string s2){
        if (s1.size() != s2.size()) return s1.size() > s2.size();
        return s1 < s2;
    }
    string longestValidWord(vector<string>& words) {
        for(auto word: words) insert_word(word);
        sort(words.begin(), words.end(), comparator);
        for(auto word: words){
            bool check = check_string(word);
            if(check) return word;
        }
        return "";
    }
};

/*
Time Complexity: O(N⋅L)
Space complexity: O(N⋅L)
*/
