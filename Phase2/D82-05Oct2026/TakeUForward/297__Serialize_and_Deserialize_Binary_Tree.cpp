/*
297. Serialize and Deserialize Binary Tree

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.


Example 1:


Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
private:
    vector<string> split(const string& s) {
        vector<string> tokens;
        string token = "";
        for (char ch : s) {
            if (ch == ',') {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token = "";
                }
            } else {
                token += ch;
            }
        }
        if (!token.empty()) tokens.push_back(token);
        return tokens;
    }

public:
    string serialize(TreeNode* root) {
        if (!root) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        s += to_string(root->val) + ",";
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node->left) {
                s += "#,";
            } else {
                s += to_string(node->left->val) + ",";
                q.push(node->left);
            }
            if (!node->right) {
                s += "#,";
            } else {
                s += to_string(node->right->val) + ",";
                q.push(node->right);
            }
        }
        return s;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<string> nodes = split(data);
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1; 
        while (!q.empty() && i < nodes.size()) {
            TreeNode* node = q.front();
            q.pop();
            if (nodes[i] != "#") {
                TreeNode* leftChild = new TreeNode(stoi(nodes[i]));
                node->left = leftChild;
                q.push(leftChild);
            }
            i++;
            if (i < nodes.size() && nodes[i] != "#") {
                TreeNode* rightChild = new TreeNode(stoi(nodes[i]));
                node->right = rightChild;
                q.push(rightChild);
            }
            i++;
        }
        
        return root;
    }
};

/*
Complexity analysis:

Serialization function:
Time complexity: O(N)
Space complexity: O(N)

Deserilization function:
Time complexity: O(N)
Space complexity: O(N)
*/