/*
94. Binary Tree Inorder Traversal
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]

Explanation:
Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]

Explanation:

Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?
*/

// Morris inorder traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> ans;
        while(curr!=nullptr){
            if(curr->left == nullptr){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* temp = curr->left;
                while(temp->right!=nullptr && temp->right!=curr) temp = temp->right;
                if(temp->right == nullptr){
                    temp->right = curr;
                    curr = curr -> left;
                }
                else{
                    ans.push_back(curr->val);
                    temp->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};

/*
Time complexity: Amortized O(N) + O(N) where N is the number of nodes present in the given binary tree.
Space complexity: O(1), we are not using any extra space here, hence the space complexity is constant.
*/