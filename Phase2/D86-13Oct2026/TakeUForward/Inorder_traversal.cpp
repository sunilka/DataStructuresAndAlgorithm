/*

Inorder traversal of a binary tree is a DFS technique of traversing the tree.
In the inorder traversal, we traverse the tree in the order of Left - Root - Right.

Now lets look at how to code the tree in different techniques.

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

void inorder(TreeNode* root, vector<int>& ans){
    if(root){
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    inorder(root, ans);
    return ans;
}

/*
Time complexity: O(N), where N is the number of nodes present in the binary tree.
Space complexity: O(H) auxiliary stack space used becuase of recursion, where H is the height of the tree.
*/


/*
Iterative code of inorder traversal with stack.
*/

void inorder(TreeNode* root, vector<int>& ans){
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* temp = root;

    while(temp!=nullptr && !st.empty()){
        while(temp!=nullptr && temp->left){
            st.push(temp->left);
            temp = temp->left;
        }

        TreeNode* node = st.top();
        st.pop();
        ans.push_back(node->val);
        if(node->right){
            st.push(node->right);
            temp = node->right;
        }
    }
}


void inorder(TreeNode* root, vector<int>& ans) {
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr != nullptr || !st.empty()) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        ans.push_back(curr->val);
        curr = curr->right;
    }
}

/*
Time complexity: O(N) where N is the number of nodes in the binary tree.
Space complexity: O(H) stack space used, where H is the height of the tree.
*/

/*
Morris traversal. Constant space traversal.

In morris traversal, we follow a technique of threading the inorder predecessor to the inorder sucessor so that we can 
use the thread to come back to the root and proceed the traversal to the right subtree.
*/

void inorder(TreeNode* root, vector<int>& ans){
    TreeNode *curr = root;
    while(curr!=nullptr){
        if(curr->left){
            TreeNode* temp = curr->left;
            while(temp->right && temp->right!=curr) temp = temp->right;
            if(temp->right==nullptr){
                // Thread is to be created over here.
                temp->right = curr;
                curr = curr->left;
            }
            else{
                // Remove the thread. When we are removing a thread, we are sure that we have explored the left 
                // subtree of the node and hence we push the node into the answer and then we look of the 
                // right subtree exploration.
                ans.push_back(curr->val);
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
Time complexity: Amorotized O(N), where N is the number of nodes in the binary tree.
Space complexity: Constant space complexity. 
*/



