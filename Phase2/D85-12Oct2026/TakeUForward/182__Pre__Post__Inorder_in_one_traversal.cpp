/*
Inorder , preorder and postorder traversal in one iteration
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left, *right;
};

vector<vector<int>> solve(TreeNode* root){
    vector<int> inorder, preorder, postorder;
    if(!root) return {inorder, preorder, postorder};
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while(!st.empty()){
        pair<TreeNode*, int> node_data = st.top();
        st.pop();
        if(node_data.second == 1){
            preorder.push_back(node_data.first->data);
            st.push({node_data.first, node_data.second+1});
            if(node_data.first->left) st.push({node_data.first->left, 1});
        }   
        else if(node_data.second == 2){
            inorder.push_back(node_data.first->data);
            st.push({node_data.first, node_data.second+1});
            if(node_data.first->right) st.push({node_data.first->right, 1});
        }
        else{
            postorder.push_back(node_data.first->data);
        }
    }   
    return {inorder, preorder, postorder};
}

/*
Time complexity: O(3*N) where N is the number of nodes present in the given binary tree.
Space complexity: O(3N), where N is the number of nodes present in the given binary tree.
*/