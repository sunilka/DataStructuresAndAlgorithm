/*
Top View of Binary Tree
You a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Return the nodes from the leftmost node to the rightmost node.
If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 
Examples:

Input: root = [1, 2, 3]
Output: [2, 1, 3]
Explanation: The Green colored nodes represents the top view in the below Binary tree.
 
Input: root = [10, 20, 30, 40, 60, 90, 100]
Output: [40, 20, 10, 30, 100]
Explanation: The Green colored nodes represents the top view in the below Binary tree.


Constraints:

1 ≤ size of binary tree, node.data ≤ 105
*/

#include<bits/stdc++.h>
using namespace std;

/* 
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
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
                if(topNodeMap.find(c) == topNodeMap.end()) topNodeMap[c] = node->data;
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

    vector<int> topView(Node *root) {
        if(!root) return {};
        if(root->left == nullptr && root->right == nullptr) return {root->data};
        return solve(root);
    }
};

/*
Time complexity: O(NlogN)
Space complexity: O(N)
*/