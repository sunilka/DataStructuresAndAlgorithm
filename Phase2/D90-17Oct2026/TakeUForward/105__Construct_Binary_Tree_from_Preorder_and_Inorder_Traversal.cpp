/*

105. Construct Binary Tree from Preorder and Inorder Traversal

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.

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
    unordered_map<int, int> m;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& pidx, int low, int high, int s){
        if(pidx>=s || low>high) return nullptr;
        TreeNode* newnode = new TreeNode(preorder[pidx]);
        int idx = m[preorder[pidx]];
        pidx+=1;
        newnode->left = solve(preorder, inorder, pidx, low, idx-1, s);
        newnode->right = solve(preorder, inorder, pidx, idx+1, high, s);
        return newnode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int s = inorder.size();
        for(int i=0; i<s; i++) m[inorder[i]] = i;
        int pidx = 0;
        return solve(preorder, inorder, pidx, 0, s-1, s);
    }
};

/*
Time complexity: O(N) where N is the numbers of elements present in the given vector array.
Space complexity: O(N) for the unordered map, O(H) auxiliary stack space because of the recursion, where H is the height of the resulting bianry tree.
*/