/*
101. Symmetric Tree
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?
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
    bool solve(TreeNode *l, TreeNode *r){
        if(l==nullptr && r ==nullptr) return true;
        if( (l && !r) || (!l && r)) return false;
        if(l->val != r->val) return false;
        return solve(l->left, r->right) && solve(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        if(root->left == nullptr && root->right == nullptr) return true;
        return solve(root->left, root->right);
    }
};

/*
Time complexity: O(N) where N is the number of nodes present in the given tree.
Space complexity: O(H) auxiliary stack space, where H is the maximum depth of the given tree.
*/

/*
Iterative code
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root->left, root->right});
        while (!q.empty()) {
            auto [leftNode, rightNode] = q.front();
            q.pop();
            if (!leftNode && !rightNode) continue;
            if (!leftNode || !rightNode || leftNode->val != rightNode->val) return false;
            q.push({leftNode->left, rightNode->right});
            q.push({leftNode->right, rightNode->left});
        }
        return true;
    }
};

/*
Time complexity: O(N) where N is the number of nodes present in the given tree.
Space complexity: O(W) space, where W is the maximum width of the given tree.
*/

/*
Iterative code - DFS
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({root->left, root->right});
        while (!st.empty()) {
            auto [leftNode, rightNode] = st.top();
            st.pop();
            if (!leftNode && !rightNode) continue;
            if (!leftNode || !rightNode || leftNode->val != rightNode->val) return false;
            st.push({leftNode->left, rightNode->right});
            st.push({leftNode->right, rightNode->left});
        }
        return true;
    }
};

/*
Time complexity: O(N) where N is the number of nodes present in the given tree.
Space complexity: O(H) where H is the height of the binary tree.
*/
