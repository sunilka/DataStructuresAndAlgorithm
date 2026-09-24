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


// Node Structure
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
    void left_nodes(Node *root, vector<int>& ans) {
        Node *curr = root->left;
        while (curr != nullptr) {
            if (curr->left == nullptr && curr->right == nullptr) break;
            ans.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void leaf_nodes(Node* root, vector<int>& ans) {
        if (!root) return;
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(root->data);
            return;
        }
        leaf_nodes(root->left, ans);
        leaf_nodes(root->right, ans);
    }

    void right_nodes(Node* root, vector<int>& ans) {
        Node* curr = root->right;
        vector<int> tans;
        while (curr != nullptr) {
            if (curr->left == nullptr && curr->right == nullptr) break;
            tans.push_back(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        ans.insert(ans.end(), tans.rbegin(), tans.rend());
    }

    vector<int> boundaryTraversal(Node *root) {
        if (!root) return {};
        if (root->left == nullptr && root->right == nullptr) return {root->data};
        vector<int> ans;
        ans.push_back(root->data);
        left_nodes(root, ans);
        leaf_nodes(root, ans);
        right_nodes(root, ans);
        return ans;
    }
};

/*
Time Complexity: O(N)
Auxiliary Space Complexity: O(H) worst-case O(N) for a skewed tree due to the call stack.
Total Space Complexity: O(N) including the output array.
*/