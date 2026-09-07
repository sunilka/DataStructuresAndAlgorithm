/*
Delete Head of Doubly Linked List
Given the head of a doubly linked list, delete the head node and return the new head of the list.

Examples :

Input:

Output: 2 <-> 3

Explanation: The first node [1] is removed, and the next node [2] becomes the new head.
Input: head = [2, 5, 7, 8, 99, 100]
 
Output: 5 <-> 7 <-> 8 <-> 99 <-> 100

Explanation: The head node [2] is deleted, and the remaining list starts from node 5.
Constraints:
2 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 109
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int x){
            data = x;
            next = prev = nullptr;
        }
};

class Solution {
  public:
    Node* deleteHead(Node* head) {
        Node* temp = head;
        if(temp->next) head = temp->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return head;
    }
};