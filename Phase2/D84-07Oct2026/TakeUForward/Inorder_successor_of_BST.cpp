/*
Inorder Successor in BST

Given a BST, and a reference to a Node k in the BST. Find the Inorder Successor of the given node in the BST. If there is no successor, return -1. 

Examples :

Input: root = [2, 1, 3], k = 2
Output: 3 
Explanation: Inorder traversal : 1 2 3 Hence, inorder successor of 2 is 3.

Input: root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], k = 8     
Output: 10
Explanation: Inorder traversal: 4 8 10 12 14 20 22. Hence, successor of 8 is 10.

Constraints:
1 ≤ n ≤ 105, where n is the number of nodes
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
    int inOrderSuccessor(Node *root, Node *k) {
        Node* curr = root, *successor = nullptr;
        while(curr!=nullptr){
            if(curr->data <= k->data) curr = curr->right;
            else successor = curr, curr = curr->left;
        }
        if(successor) return successor->data;
        return -1;
    }
};

/*
Time complexity: O(H), where H is the height of the BST.
Space complexity: O(1), we are not using any extra space here, hence the space complexity is constant here. 
*/