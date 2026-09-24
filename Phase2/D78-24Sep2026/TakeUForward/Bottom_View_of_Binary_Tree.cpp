/*
Bottom View of Binary Tree

You are given the root of a binary tree, and your task is to return its bottom view. The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level order traversal is considered.

Examples :

Input: root = [1, 2, 3, 4, 5, N, 6]
    
Output: [4, 2, 5, 3, 6]
Explanation: The Green nodes represent the bottom view of below binary tree.
    
Input: root = [20, 8, 22, 5, 3, 4, 25, N, N, 10, 14, N, N, 28, N]
    
Output: [5, 10, 4, 28, 25]
Explanation: The Green nodes represent the bottom view of below binary tree.
    
Constraints:

1 ≤ size of binary tree, node.data ≤ 105

*/

#include<bits/stdc++.h>
using namespace std;

/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    vector<int> solve(Node* root){
        map<int, int> topNodeMap;
        queue<pair<int, Node*>> q;
        q.push({0, root});
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [c, node] = q.front();
                q.pop();
                topNodeMap[c] = node->data;
                if(node->left) q.push({c-1, node->left});
                if(node->right) q.push({c+1, node->right});
            }
        }
        vector<int> ans;
        for(auto it : topNodeMap){
          ans.push_back(it.second);
        }
        return ans;
    }
    vector<int> bottomView(Node *root) {
        if(!root) return {};
        if(root->left == nullptr && root->right == nullptr) return {root->data};
        return solve(root);
    }
};

/*
Time complexity: O(NlogN)
Space complexity: O(N)
*/