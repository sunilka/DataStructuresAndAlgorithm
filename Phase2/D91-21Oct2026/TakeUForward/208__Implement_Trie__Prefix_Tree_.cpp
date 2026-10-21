/*
208. Implement Trie (Prefix Tree)

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.
*/

#include<bits/stdc++.h>
using namespace std;

class Trie {
public:
    struct TrieNode{
        vector<TrieNode*> children;
        bool is_end;
        TrieNode(){
            children.resize(26, nullptr);
            is_end = false;
        }
    };
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(auto ch: word){
            int idx = ch - 'a';
            if(temp->children[idx]==nullptr) temp->children[idx] = new TrieNode();
            temp = temp->children[idx];
        }
        temp->is_end = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(auto ch: word){
            int idx = ch - 'a';
            if(temp->children[idx] == nullptr) return false;
            temp = temp->children[idx];
        }
        if(temp->is_end) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(auto ch: prefix){
            int idx = ch - 'a';
            if(temp->children[idx] == nullptr) return false;
            temp = temp->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/*
Time complexity:

Insert operation: O(WL), where WL is the length of the word.
Search full text: O(WL)
Search starts with: O(WL)

Space complexity:
- Per insert: O(WL) in the worst case (no shared prefix).
- Total Trie storage: O(Total Characters × 26) due to the fixed-size child vectors per node.
*/