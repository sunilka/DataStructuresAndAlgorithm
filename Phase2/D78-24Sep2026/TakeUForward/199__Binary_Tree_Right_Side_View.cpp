/*
199. Binary Tree Right Side View
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:
Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:
Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []

Constraints:

The number of nodes in the tree is in the range [0, 100].
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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        if(root->left == nullptr && root->right == nullptr) return {root->val};
        vector<int> ans;
        queue<pair<int, TreeNode*>> q;
        set<int> s;
        q.push({0, root});
        while(!q.empty()){
            int ss = q.size();
            while(ss--){
                auto [l, node] = q.front();
                q.pop();
                if(!s.count(l)){
                    ans.push_back(node->val);
                    s.insert(l);
                }

                if(node->right) q.push({l+1, node->right});
                if(node->left) q.push({l+1, node->left});
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(N)
Space complexity: O(N)
*/