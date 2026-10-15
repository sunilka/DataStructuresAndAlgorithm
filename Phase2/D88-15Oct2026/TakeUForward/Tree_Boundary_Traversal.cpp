/*
Tree Boundary Traversal

Given a root of a Binary Tree, return its boundary traversal in the following order:

Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring the left child over the right and excluding leaves.
Leaf Nodes: All leaf nodes from left to right, covering every leaf in the tree.
Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node, preferring the right child over the left, excluding leaves, and added in reverse order.
Note: The root is included once, leaves are added separately to avoid repetition, and the right boundary follows traversal preference not the path from the rightmost leaf.

Examples:

Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
Output: [1, 2, 4, 8, 9, 6, 7, 3]
Explanation:

Input: root = [1, N, 2, N, 3, N, 4, N, N] 
Output: [1, 4, 3, 2]
Explanation:

Left boundary: [1] (as there is no left subtree)
Leaf nodes: [4]
Right boundary: [3, 2] (in reverse order)
Final traversal: [1, 4, 3, 2]
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105
*/

#include<bits/stdc++.h>
using namespace std;

/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    bool isLeaf(Node* node) {
        return node && !node->left && !node->right;
    }

    void traverse_left(Node* curr, vector<int>& ans) {
        if (!curr || isLeaf(curr)) return;
        ans.push_back(curr->data);
        if (curr->left) traverse_left(curr->left, ans);
        else if (curr->right) traverse_left(curr->right, ans);
    }

    void traverse_right(Node* curr, vector<int>& ans) {
        if (!curr || isLeaf(curr)) return;
        if (curr->right) traverse_right(curr->right, ans);
        else if (curr->left) traverse_right(curr->left, ans);
        ans.push_back(curr->data); // Pushed after recursion to get bottom-up (reversed) order
    }

    void get_leaf_nodes(Node* curr, vector<int>& ans) {
        if (!curr) return;
        if (isLeaf(curr)) {
            ans.push_back(curr->data);
            return;
        }
        get_leaf_nodes(curr->left, ans);
        get_leaf_nodes(curr->right, ans);
    }

    vector<int> boundaryTraversal(Node *root) {
        if (!root) return {};
        vector<int> ans;

        if (!isLeaf(root)) {
            ans.push_back(root->data);
        }

        // 1. Traverse Left Boundary
        traverse_left(root->left, ans);

        // 2. Get All Leaf Nodes
        get_leaf_nodes(root, ans);

        // 3. Traverse Right Boundary
        traverse_right(root->right, ans);

        return ans;
    }
};

/*
Time complexity: O(N), where N is the number nodes present in the given binary tree.
Space complexity: O(H) axuiliary stack space because of recursion, where H is the height of the given binary tree.
*/