/*
Insertion in a Doubly Linked List
Given the head of a doubly-linked list, a position p, and an integer x. Insert a new node with value x at the position just after pth node (0-based indexing) in the doubly linked list and return the head of the modified list.

Examples:

Input: p = 2, x = 6

Output: 2 <-> 4 <-> 5 <-> 6
Explanation: Insert a node of value 6 after the 2nd node.

Input: p = 0, x = 44 

Output: 1 <-> 44 <-> 2 <-> 3 <-> 4
Explanation: Insert a node of value 44 after the 0th node.

Constraints:
0 ≤ p < list size ≤ 104
0 ≤ x, node->data ≤ 104
*/

#include<bits/stdc++.h>
using namespace std;

/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/
class Node{
    public: 
        int data;
        Node *next, *prev;

        Node(int x){
            data = x;
            next = prev = nullptr;
        }
};

class Solution {
  public:
    Node* insertAtPos(Node* head, int p, int x) {  
        Node* newnode = new Node(x);
        Node* temp = head;
        for(int i=0; i<p; i++) temp = temp->next;
        if(temp->next){
            temp->next->prev = newnode;
            newnode->next = temp->next;
            newnode->prev = temp;
            temp->next = newnode;
        }
        else{
            newnode -> prev = temp;
            temp->next = newnode;
        }
        return head;
    }
};

/*
TIme complexity: O(L), where L is the length of the doubly linked list or the number of nodes in the 
doubly linked list.
Space complexity: O(1), constant extra space used.
*/