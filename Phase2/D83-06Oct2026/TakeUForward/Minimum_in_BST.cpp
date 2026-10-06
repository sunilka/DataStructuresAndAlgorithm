/*
Minimum in BST
Given a Binary Search Tree, find the minimum in the given BST.

Examples

Input: root = [5, 4, 6, 3, N, N, 7, 1]
ex-1
Output: 1
Explanation: The minimum element in the given BST is 1.
Input: root = [10, 5, 20, 2]
ex-2
Output: 2
Explanation: The minimum element in the given BST is 2.
Input: root = []
Output: -1
Explanation: The root of the BST is NULL.
Constraints:

0 ≤ size of binary tree, node.data ≤ 5*105
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
    int minValue(Node* root) {
        if (root == nullptr) return -1;
        Node* curr = root;
        while(curr->left) curr = curr->left;
        return curr->data;
    }
};

/*
Time complexity: O(H) where H is the height of the tree.
Space complexity: O(1), we are not using any extra space here, hence the space complexity is constant.
*/