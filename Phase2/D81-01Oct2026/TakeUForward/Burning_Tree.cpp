/*
Burning Tree
Given the root of a binary tree and a target node, determine the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent.

Note: The tree contains unique values.

Examples : 

Input: root = [1, 2, 3, 4, 5, 6, 7], target = 2
  
Output: 3
Explanation: Initially 2 is set to fire at 0 sec 
At 1 sec: Nodes 4, 5, 1 catches fire.
At 2 sec: Node 3 catches fire.
At 3 sec: Nodes 6, 7 catches fire.
It takes 3s to burn the complete tree.
Input: root = [1, 2, 3, 4, 5, N, 7, 8, N, N, 10], target = 10

Output: 5
Explanation: Initially 10 is set to fire at 0 sec 
At 1 sec: Node 5 catches fire.
At 2 sec: Node 2 catches fire.
At 3 sec: Nodes 1 and 4 catches fire.
At 4 sec: Node 3 and 8 catches fire.
At 5 sec: Node 7 catches fire.
It takes 5s to burn the complete tree.
Constraints:

1 ≤ size of binary tree, node.data ≤ 105
*/

#include<bits/stdc++.h>
using namespace std;

/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

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
    void fill_parent_pointers(Node* root, unordered_map<Node*, Node*>& parent_pointers){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            if(node->left){
                parent_pointers[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent_pointers[node->right] = node;
                q.push(node->right);
            }
        }
    }
    Node* find_target(Node* root, int target){
        if(!root) return nullptr;
        if(root->data == target) return root;
        Node* left = find_target(root->left, target);
        if(left) return left;
        return find_target(root->right, target);
    }
    
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent_pointers;
        fill_parent_pointers(root, parent_pointers);
        unordered_set<Node*> visited;
        Node* target_node = find_target(root, target);
        queue<Node*> q;
        q.push(target_node);
        visited.insert(target_node);
        int time = 0;
        
        while(!q.empty()){
            int s = q.size();
            bool flag = false;
            while(s--){
                Node* node = q.front();
                q.pop();
                if(node->left && !visited.count(node->left)){
                    flag = true;
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && !visited.count(node->right)){
                    flag = true;
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if(parent_pointers[node] && !visited.count(parent_pointers[node])){
                    flag = true;
                    visited.insert(parent_pointers[node]);
                    q.push(parent_pointers[node]);
                }
            }
            if(flag) time +=1;
        }
        return time;
    }
};

/*
Time complexity: O(N)
Space complexity: O(N)
*/