/*
Left View of Binary Tree
Given the root of a binary tree. Return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

Note: If the tree is empty, return an empty list.

Examples :

Input: root = [1, 2, 3, 4, 5, N, N] 
 
Output:[1, 2, 4]
Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.

Input: root = [1, 2, 3, N, N, 4, N, N, 5, N, N]

Output: [1, 2, 4, 5]
Explanation: From the left side of the tree, only the nodes 1, 2, 4, and 5 are visible.

Constraints:

0 ≤ size of binary tree, node.data ≤ 105

*/

/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

#include<bits/stdc++.h>
using namespace std;

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
    vector<int> leftView(Node *root) {
        if(!root) return {};
        if(root->left == nullptr && root->right == nullptr) return {root->data};
        vector<int> ans;
        queue<pair<int, Node*>> q;
        set<int> s;
        q.push({0, root});
        while(!q.empty()){
            int ss = q.size();
            while(ss--){
                auto [l, node] = q.front();
                q.pop();
                if(!s.count(l)){
                    ans.push_back(node->data);
                    s.insert(l);
                }
                if(node->left) q.push({l+1, node->left});
                if(node->right) q.push({l+1, node->right});
            }
        }
        return ans;
    }
};

/*
Time complexity: O(NlogN)
Space complexity: O(N)
*/