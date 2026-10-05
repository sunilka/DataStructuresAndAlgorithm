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
    int find_val(vector<int>& inorder, int l, int r, int val){
        for(int i = l; i <= r; i++){
            if(inorder[i] == val) return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& pp, int left, int right){
        if(left > right) return nullptr;
        TreeNode* root = new TreeNode(preorder[pp]);
        int idx = find_val(inorder, left, right, preorder[pp]);
        pp++;
        root->left = solve(preorder, inorder, pp, left, idx - 1);
        root->right = solve(preorder, inorder, pp, idx + 1, right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pp = 0;
        return solve(preorder, inorder, pp, 0, inorder.size() - 1);
    }
};

/*
Time complexity: O(N*N) = O(N^2), where N is the number of nodes present in the given linked list.
Space complexity: O(N) and auxiliary space of O(N)
*/

/*
Unordered map approach to reduce the time.
*/

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
class Solution {
public:
    unordered_map<int, int> m;
    TreeNode* solve(vector<int>& preorder, int& pp, int left, int right){
        if(left>right) return nullptr;
        TreeNode* root = new TreeNode(preorder[pp]);
        int idx = m[preorder[pp]];
        pp++;
        root->left = solve(preorder, pp, left, idx-1);
        root->right = solve(preorder, pp, idx+1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0; i<n; i++) m[inorder[i]] = i;
        int pp = 0;
        return solve(preorder, pp, 0, n-1);
    }
};

/*
Time complexity: O(N) where N is the number of nodes present in the tree.
Space complexity: O(N) for the unordered map and O(N) auxiliary stack space because of recursion.
*/