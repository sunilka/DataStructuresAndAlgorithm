/*
Preorder traversal is a DFS traversal technique, in which we explore the tree in the order of Root - Left - Right.
Lets us look into the pre order traversal one by one here.
*/

// Recursive pre-order traversal.

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

void preorder(TreeNode* root, vector<int>& ans){
    if(root){
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    preorder(root, ans);
    return ans;
}

/*
Time complexity: O(N), where N is the number of nodes present in the binary tree.
Space complexity: O(H) auxiliary stack space because of recursion, where H is the height of the tree.
*/

/*
Iterative with stack
*/

void preorder(TreeNode* root, vector<int>& ans) {
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr != nullptr || !st.empty()) {
        while (curr != nullptr) {
            ans.push_back(curr->val);
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        curr = curr->right;
    }
}

/*
Time complexity: O(N), where N is the number of nodes present in the binary tree.
Space complexity: O(H) stack space, where H is the height of the tree.
*/

/*
Morris traversal.
*/

void preorder(TreeNode* root, vector<int>& ans){
    TreeNode *curr = root;
    while(curr!=nullptr){
        if(curr->left){
            TreeNode* temp = curr->left;
            while(temp->right && temp->right!=curr) temp = temp->right;
            if(temp->right==nullptr){
                // Thread is to be created over here.
                ans.push_back(curr->val);
                temp->right = curr;
                curr = curr->left;
            }
            else{
                // Remove the thread. When we are removing a thread, we are sure that we have explored the left 
                // subtree of the node and hence we push the node into the answer and then we look of the 
                // right subtree exploration.
                temp->right = nullptr;
                curr = curr->right;
            }
        }
        else{
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }
}


/*
Time complexity: O(N), where N is the number of nodes present in the binary tree.
Space complexity: O(1) constant space.
*/