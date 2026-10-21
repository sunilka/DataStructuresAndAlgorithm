/*
653. Two Sum IV - Input is a BST

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void push_left(TreeNode* root, stack<TreeNode*>& st) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
    void push_right(TreeNode* root, stack<TreeNode*>& st) {
        while (root) {
            st.push(root);
            root = root->right;
        }
    }

    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        stack<TreeNode*> leftStack;
        stack<TreeNode*> rightStack;
        push_left(root, leftStack);
        push_right(root, rightStack);
        while (!leftStack.empty() && !rightStack.empty()) {
            TreeNode* leftNode = leftStack.top();
            TreeNode* rightNode = rightStack.top();
            if (leftNode->val >= rightNode->val) break;
            int sum = leftNode->val + rightNode->val;
            if (sum == k) return true;
            else if (sum < k) {
                leftStack.pop();
                if (leftNode->right) {
                    push_left(leftNode->right, leftStack);
                }
            } 
            else {
                rightStack.pop();
                if (rightNode->left) {
                    push_right(rightNode->left, rightStack);
                }
            }
        }
        return false;
    }
};

/*
Time complexity: O(N), where N is the number of nodes present in the binary search tree.
Space complexity: O(H), where H is the height of the given binary search tree.
*/