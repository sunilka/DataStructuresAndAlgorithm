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
    int minValue(Node* root) {
        if (root == nullptr) return -1;
        Node* curr = root;
        while(curr->right) curr = curr->right;
        return curr->data;
    }
};

/*
Time complexity: O(H) where H is the height of the tree.
Space complexity: O(1), we are not using any extra space here, hence the space complexity is constant.
*/