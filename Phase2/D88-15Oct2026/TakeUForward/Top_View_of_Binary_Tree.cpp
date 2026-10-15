/*
Top View of Binary Tree

You a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Return the nodes from the leftmost node to the rightmost node.
If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 
Examples:

Input: root = [1, 2, 3]
Output: [2, 1, 3]
Explanation: The Green colored nodes represents the top view in the below Binary tree.
 
Input: root = [10, 20, 30, 40, 60, 90, 100]
Output: [40, 20, 10, 30, 100]
Explanation: The Green colored nodes represents the top view in the below Binary tree.


Constraints:

1 ≤ size of binary tree, node.data ≤ 105
*/

#include<bits/stdc++.h>
using namespace std;

/* 
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    vector<int> topView(Node *root) {
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
            if (m.find(c) == m.end()) {
                m[c] = node->data;
            }
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
Time complexity: O(NlogN), where N is the number of nodes present in the binary tree.
Space complexity: O(W), where W is the width of the binary tree.
*/