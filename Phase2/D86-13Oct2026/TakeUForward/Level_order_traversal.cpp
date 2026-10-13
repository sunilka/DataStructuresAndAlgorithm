/*
Level order traversal of a binary tree is a BFS way for traversing a binary tree.
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

vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int s = q.size();
        vector<int> tempans;
        while(s--){
            TreeNode* node = q.front();
            q.pop();
            tempans.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        if(tempans.size()>0){
            ans.push_back(tempans);
        }
    }
    return ans;
}

/*
Time complexity: O(N) where N is the number of nodes present in the given binary tree.
Space complexity: O(W) where W is the width of the given binary tree. In case of complete binary tree the width can be N/2.
Hence, it be witten as O(N/2)= O(N) 
*/