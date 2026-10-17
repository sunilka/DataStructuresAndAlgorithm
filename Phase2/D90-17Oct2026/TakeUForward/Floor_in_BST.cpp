/*
Floor in BST

Given a binary search tree and a number k, find the greatest number in the binary search tree that is less than or equal to k.

Note: If no such node value exists that is smaller than k, then return -1.

Examples:

Input: root = [10, 7, 15, 2, 8, 11, 16],  k  =  14

Output: 11
Explanation: The greatest element in the tree which is less than or equal to 14, is 11.
Input: root = [5, 2, 12, 1, 3, 9, 21, N, N, N, N, N, N, 19, 25],  k  = 24

Output: 21
Explanation: The greatest element in the tree which is less than or equal to 24, is 21. 
Input: root = [5, 2, 12, 1, 3, 9, 21, N, N, N, N, N, N, 19, 25], k = 4

Output: 3
Explanation: The greatest element in the tree which is less than or equal to 4, is 3.
Constraints:

1 ≤ size of binary tree, node.data, k ≤ 105
All node values in root are unique.

*/

#include<bits/stdc++.h>
using namespace std;

/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    int ans = -1;
    void solve(Node* root, int k){
        if(!root) return;
        if(root->data > k) solve(root->left, k);
        else{
            ans = max(ans, root->data);
            solve(root->right, k);
        }
    }
    int findMaxFork(Node* root, int k) {
        solve(root, k);
        return ans;
    }
};

/*
Time complexity: O(N), where N is the number of nodes present in the binary search tree.
Space complexity: O(H), where H is the height of the binary search tree.
*/