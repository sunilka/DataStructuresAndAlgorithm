/*
543. Diameter of Binary Tree
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
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
Time complexity: O(N), where N is the number of nodes present in the binary tree.
Space complexity: O(H) auxiliary stack space, where H is the height of the tree.
*/