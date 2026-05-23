// https://leetcode.com/problems/binary-tree-paths/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void calc(TreeNode* root, vector<string>& ans, vector<int>& carrying_ans){
        if(!root){
            return;
        }

        if(root->left == NULL && root->right == NULL){
            carrying_ans.push_back(root->val);

            // Making the answer string here
            string temp_ans = to_string(carrying_ans[0]);
            for(int i=1; i<carrying_ans.size(); i++){
                temp_ans = temp_ans + "->" + to_string(carrying_ans[i]);
            }
            ans.push_back(temp_ans);
            carrying_ans.pop_back();
            return;
        }

        if(root->left){
            carrying_ans.push_back(root->val);
            calc(root->left, ans, carrying_ans);
            carrying_ans.pop_back();
        }

        if(root->right){
            carrying_ans.push_back(root->val);
            calc(root->right, ans, carrying_ans);
            carrying_ans.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> carrying_ans;
        calc(root, ans, carrying_ans);
        return ans;
    }
};