/*
Pre Post Inorder in single traversal.
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

vector<vector<int>> solve(TreeNode* root){
    stack<pair<TreeNode*, int>> st;
    vector<int> pre, in, post;
    st.push({root, 1});

    while(!st.empty()){
        auto [node, val] = st.top();
        st.pop();

        if(val == 1){
            pre.push_back(node->val);
            st.push({node, 2});

            if(node->left){
                st.push({node->left, 1});
            }
        }

        else if(val == 2){
            in.push_back(node->val);
            st.push({node, 3});
            if(node->right){
                st.push({node->right, 1});
            }
        }
        else{
            post.push_back(node->val);
        }
    }
    return {in, pre, post};
}

/*
Time complexity: O(3N).
Space complexity: O(3N). 
*/