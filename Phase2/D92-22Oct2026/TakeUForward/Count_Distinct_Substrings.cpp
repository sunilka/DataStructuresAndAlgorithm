/*
Count Distinct Substrings

Given a string s consisting of lowercase English letters, find the total number of distinct non-empty substrings of s.

Note: A substring is a contiguous sequence of characters within a string. Two substrings are considered distinct if they have different character sequences, regardless of their positions in the string.

Examples :

Input: s = "ababa"
Output: 9
Explanation: All distinct substrings of "ababa" are: "a", "b", "ab", "ba", "aba", "bab", "abab", "baba", "ababa".
Input: s = "aaa"
Output: 3
Explanation: The distinct substrings of "aaa" are: "a", "aa", "aaa".
Constraints:
1 ≤ s.size() ≤ 3000
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct TrieNode {
        vector<TrieNode*> children;
        TrieNode() {
            children.resize(26, nullptr);
        }
        // Destructor to clean up memory (optional, but good practice)
        ~TrieNode() {
            for (auto child : children) {
                delete child;
            }
        }
    };

    int countSubs(string& s) {
        int count = 0;
        int n = s.size();
        TrieNode* root = new TrieNode();

        for (int i = 0; i < n; i++) {
            TrieNode* temp = root;
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if (temp->children[idx] == nullptr) {
                    temp->children[idx] = new TrieNode();
                    count++; 
                }
                temp = temp->children[idx];
            }
        }

        delete root; 
        return count;
    }
};

/*
Time complexity: O(N^2), where N is the numbers of characters in the given word.
Space complexity: O(N^2), where N is the number of characters in the given word.
*/