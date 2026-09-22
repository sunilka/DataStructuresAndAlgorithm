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

// Structure of a Tree Node
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
    bool solve(Node *root){
        if(!root) return true;
        if(root->left == nullptr && root->right == nullptr) return true;
        bool la = solve(root->left);
        bool ra = solve(root->right);
        if(la == false || ra == false) return false;
        int lv = 0, rv = 0;
        if(root->left) lv = root->left->data;
        if(root->right) rv = root->right->data;
        if(root->data == (lv + rv)) return true;
        return false;
    } 
    bool isSumProperty(Node *root) {
        return solve(root);
    }
};

/*
Time complexity: O(N), where N is the number of nodes present in the given tree.
Space complexity: O(H) auilixary stack space, where H is the maximum dept of the given tree.
*/