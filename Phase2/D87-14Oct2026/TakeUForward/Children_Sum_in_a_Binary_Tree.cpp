/*
Children Sum in a Binary Tree

Given a binary tree, find if it satisfies the Children Sum Property which has the following rules

Each non-leaf node must have a value equal to the sum of its left and right children's values.
A NULL child is considered to have a value of 0, and all leaf nodes are considered valid by default.
Examples:

Input: root = [35, 20, 15, 15, 5, 10, 5]

Output: True
Explanation: Here, every node is sum of its left and right child.
Input: root = [1, 4, 3, 5]
  
Output: False
Explanation: Here, 1 is the root node and 4, 3 are its child nodes. 4 + 3 = 7 which is not equal to the value of root node. Hence, this tree does not satisfy the given condition.
Constraints:

1 ≤ size of binary tree ≤ 105
0 ≤ node.data ≤ 109
*/

#include<bits/stdc++.h>
using namespace std;

/* Structure of a Tree Node
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
    bool isSumProperty(Node *root) {
        if(!root) return true;
        if (!root->left && !root->right) return true;
        int l = 0, r = 0;
        if(root->left) l = root->left->data;
        if(root->right) r = root->right->data;
        if(root->data != l+r) return false;
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};

/*
Time complexity: O(N) where N is the number of nodes present in the given binary tree.
Space complexity: O(H) auxiliary stack space because of recursion, where H is the height of the tree.
*/