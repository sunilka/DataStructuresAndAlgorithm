/*
Postorder traversal of the tree is a DFS technique again to traverse the tree. The order in which the post order traversal works 
is that left - right - root.
*/


// Recursive code.

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

void postorder(TreeNode* root, vector<int>& ans){
    if(root){
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
}

/*
Time complexity: O(N), where N is the number of nodes present in the binary tree.
Space complexity: O(H) auxiliary stack space used becuase of recursion, where H is the height of the tree.
*/

void postorder(TreeNode* root, vector<int>& ans){
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while(curr!=nullptr && !st.empty()){
        while(curr && curr->right){
            st.push(curr);
            curr = curr->right;
        }
        curr = st.top();
        st.pop();
        ans.push_back(curr->val);
        curr = curr->left;
    }
    reverse(ans.begin(), ans.end());
}

/*

*/