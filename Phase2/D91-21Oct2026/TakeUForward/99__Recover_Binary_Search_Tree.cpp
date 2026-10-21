/*
99. Recover Binary Search Tree

You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

Example 1:


Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 

Constraints:

The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1
 

Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?
*/

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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
    TreeNode* first = nullptr, *middle = nullptr, *last = nullptr, *prev = nullptr;
    void inorder(TreeNode* root){
        if(root){
            inorder(root->left);
            if(prev && root->val < prev->val){
                if(first) last = root;
                else first = prev, middle = root;
            }
            prev = root;
            inorder(root->right);
        }
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(last) swap(first->val, last->val);
        else swap(first->val, middle->val);
    }
};

/*
Time complexity: O(N), where N is the number of nodes in the given binary search tree.
Space complexity: O(1), constant extra space, but we are using O(H) auxiliary stack space because of the recursion.


For constant space we can use the Morris inorder traversal and eliminate the recursion stack used.
*/
