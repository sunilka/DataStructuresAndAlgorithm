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
Time complexity: O(N) where N is the number of nodes present in the binary tree.
Space complexity: O(W), where W is the width of the binary tree.
*/