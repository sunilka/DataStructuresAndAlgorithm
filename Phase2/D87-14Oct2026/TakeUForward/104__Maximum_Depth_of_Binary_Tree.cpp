/*
104. Maximum Depth of Binary Tree

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
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
    void inorder(TreeNode* root, int level, int& ans){
        if(root){
            inorder(root->left, level+1, ans);
            ans = max(ans, level);
            inorder(root->right, level+1, ans);
        }
    }
    int maxDepth(TreeNode* root) {
        int ans = 0;
        inorder(root, 1, ans);
        return ans;
    }
};

/*
Time complexity: O(N), where N is the number of nodes present in the binary tree.
Space complexity: O(H) auxiliary stack space, where H is the height of the tree.
*/


// Recussive solution way 2.

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left)+1, maxDepth(root->right)+1);
    }
};

/*
Time complexity: O(N), where N is the number of nodes present in the binary tree.
Space complexity: O(H) auxiliary stack space, where H is the height of the tree.
*/