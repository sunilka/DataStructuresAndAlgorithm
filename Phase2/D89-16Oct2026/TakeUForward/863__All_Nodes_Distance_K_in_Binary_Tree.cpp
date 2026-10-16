/*
863. All Nodes Distance K in Binary Tree
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.


Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000
*/

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    void fill_parent_pointers(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, TreeNode*>& parent_pointers){
        if(!root) return;
        if(prev) parent_pointers[root] = prev;
        fill_parent_pointers(root->left, root, parent_pointers);
        fill_parent_pointers(root->right, root, parent_pointers);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_pointers;
        unordered_set<TreeNode*> visited;
        fill_parent_pointers(root, nullptr, parent_pointers);
        int distance = 0;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        while(!q.empty()){
            if(distance == k) break;
            distance++;
            int s = q.size();
            while(s--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited.count(node->left)) q.push(node->left), visited.insert(node->left);
                if(node->right && !visited.count(node->right)) q.push(node->right), visited.insert(node->right);
                if(parent_pointers.count(node) && !visited.count(parent_pointers[node])) q.push(parent_pointers[node]), visited.insert(parent_pointers[node]);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};

/*
Time complexity: O(N), where N is the number of elements present in the given binary tree.
Space complexity: O(N), where N is the number of elements presnt in the given binary tree.
*/