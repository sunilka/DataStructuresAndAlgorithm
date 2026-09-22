/*
110. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
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
    pair<bool, int> solve(TreeNode *root){
        if(!root) return {true, 0};
        pair<bool, int> linfo = solve(root->left);
        pair<bool, int> rinfo = solve(root->right);
        int lh = linfo.second, rh = rinfo.second;
        if(!linfo.first || !rinfo.first) return {false, 0};
        if(abs(lh - rh) > 1) return {false, max(lh, rh)+1};
        return {true, max(lh, rh)+1};
    }
    bool isBalanced(TreeNode* root) {
        pair<bool, int> ans = solve(root);
        return ans.first;
    }
};

/*
Time complexity: O(N), where N is the number of nodes present in the tree.
Space complexity: O(H) where H is the maximum helght of the given tree.
*/