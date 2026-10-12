/*
Largest BST Subtree

Given the root of a binary tree, find the size of the largest subtree that is also a Binary Search Tree (BST). A subtree is considered a BST if, for every node in the subtree:

All nodes in its left subtree have values less than the node's value.
All nodes in its right subtree have values greater than the node's value.
The subtree contains no duplicate values.
Return the number of nodes in the largest BST subtree.

Note: The size of a subtree is the total number of nodes it contains.

Examples :

Input: root = [5, 2, 4, 1, 3]

Output: 3
Explanation:The following sub-tree is a BST of size 3

Input: root = [6, 7, 3, N, 2, 2, 4]

Output: 3
Explanation: The following sub-tree is a BST of size 3:

Constraints:

1 ≤ size of binary tree, node.data ≤ 105
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class Solution {
private:
    struct NodeInfo {
        bool isBST;
        int size;
        int minVal;
        int maxVal;
    };

    int maxBSTSize = 0;

    NodeInfo solve(Node* root) {
        if (root == nullptr) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        NodeInfo left = solve(root->left);
        NodeInfo right = solve(root->right);

        NodeInfo curr;
        if (left.isBST && right.isBST && root->data > left.maxVal && root->data < right.minVal) {
            curr.isBST = true;
            curr.size = left.size + right.size + 1;
            curr.minVal = min(root->data, left.minVal);
            curr.maxVal = max(root->data, right.maxVal);
            maxBSTSize = max(maxBSTSize, curr.size);
        } else {
            curr.isBST = false;
            curr.size = max(left.size, right.size);
            curr.minVal = 0;
            curr.maxVal = 0;
        }

        return curr;
    }

public:
    int largestBst(Node *root) {
        if (root == nullptr) return 0;
        maxBSTSize = 0;
        solve(root);
        return maxBSTSize;
    }
};

/*
Time complexity: O(N), where N is the number of nodes present in the binary tree.
Space complexity: O(H), where H is the height of the binary tree.
*/