/*
Bottom View of Binary Tree
Given a binary tree, and your task is to return its bottom view. The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level order traversal is considered.

Examples :

Input: root = [1, 2, 3, 4, 5, N, 6]
    
Output: [4, 2, 5, 3, 6]
Explanation: The Green nodes represent the bottom view of below binary tree.
    
Input: root = [20, 8, 22, 5, 3, 4, 25, N, N, 10, 14, N, N, 28, N]
    
Output: [5, 10, 4, 28, 25]
Explanation: The Green nodes represent the bottom view of below binary tree.
    
Constraints:

1 ≤ size of binary tree, node.data ≤ 105
*/

#include<bits/stdc++.h>
using namespace std;

/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if (!root) return ans;
        map<int, int> m;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int c = it.second;
            m[c] = node->data;
            if (node->left) {
                q.push({node->left, c - 1});
            }
            if (node->right) {
                q.push({node->right, c + 1});
            }
        }
        for (auto it : m) {
            ans.push_back(it.second);
        }
        return ans;
        
    }
};

/*
Time complexity: O(N log N),, where N is the number of nodes present in the given binary tree.
Space complexity: O(W), where W is the width of the binary tree.
*/