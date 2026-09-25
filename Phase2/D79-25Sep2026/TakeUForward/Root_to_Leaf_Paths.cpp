/*
Root to Leaf Paths
Given a Binary Tree, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.
Note: The paths should be returned such that paths from the left subtree of any node are listed first, followed by paths from the right subtree.
Examples:

Input: root = [1, 2, 3, 4, 5, N, N]
ex-3
Output: [[1, 2, 4], [1, 2, 5], [1, 3]]
Explanation: All the possible paths from root node to leaf nodes are: 1 -> 2 -> 4, 1 -> 2 -> 5 and 1 -> 3
Input: root = [1, 2, 3]

Output: [[1, 2], [1, 3]] 
Explanation: All the possible paths from root node to leaf nodes are: 1 -> 2 and 1 -> 3
Input: root = [10, 20, 30, 40, 60, N, N]

Output: [[10, 20, 40], [10, 20, 60], [10, 30]]
Explanation: All the possible paths from root node to leaf nodes are: 10 -> 20 -> 40, 10 -> 20 -> 60 and 10 -> 30
Constraints:

1 ≤ size of binary tree, node.data ≤ 104
*/


#include<bits/stdc++.h>
using namespace std;

/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

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
    void solve(Node* root, vector<int>& cans, vector<vector<int>> &ans){
        if(!root) return;
        if(root->left == nullptr && root->right == nullptr){
            cans.push_back(root->data);
            ans.push_back(cans);
            cans.pop_back();
            return;
        }
        cans.push_back(root->data);
        solve(root->left, cans, ans);
        solve(root->right, cans, ans);
        cans.pop_back();
    }
    vector<vector<int>> paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> cans;
        solve(root, cans, ans);
        return ans;
    }
};

/*
Time complexity: O(N), where N is the number of nodes in the given tree.
Space complexity; O(H), where H is the maximum height of the given tree.
*/