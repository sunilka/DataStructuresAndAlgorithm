/*
Add 1 to a Linked List Number
You are given head of a linked list where each node contains a single digit. The digits together represent a number formed by concatenating the node values in order. Add 1 to this number and return the head of the modified linked list.

Examples :

Input: Head: 4->5->6
Output: 457

Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457. 
Input: Head: 1->2->3
Output: 124
 
Explanation:  1->2->3 represents 123 and when 1 is added it becomes 124. 
Input: Head: 0->0->1
Output: 002
Constraints:

1 ≤ size of linked list ≤ 105
0 ≤ node.data ≤ 9
*/

#include<bits/stdc++.h>
using namespace std;

/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    Node* reverse_ll(Node* head){
        Node *prev = nullptr, *cur = head;
        while(cur){
            Node *nextnode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextnode;
        }
        return prev;
    }
    
    Node* addOne(Node* head) {
        Node *rhead = reverse_ll(head);
        Node *tmp = rhead;
        int n = 1;
        while(tmp){
            if(tmp->data + n < 10){
                tmp->data = tmp->data + n;
                n = 0;
                break;
            }
            else{
                tmp->data = 0;
                n = 1;
                tmp = tmp->next;
            }
        }
        
        Node *ahead = reverse_ll(rhead);
        if(n == 1){
            Node *newnode = new Node(1);
            newnode->next = ahead;
            ahead = newnode;
        }
        return ahead;
    }
};

/*
Time complexity: O(N), where N is the number of elements present in the linked list.
Space complexity: O(1), we are not using nay extra space, hence the space complexity is constant.
*/

/*
Recursive code.
*/

/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    int solve(Node* tmp, int n){
        if(tmp==nullptr) return n;
        int carry = solve(tmp->next, n);
        if(tmp->data + carry < 10){
            tmp->data = tmp->data + carry;
            return 0;
        }
        else{
            tmp->data = 0;
            return 1;
        }
    }
    Node* addOne(Node* head) {
        int carry = solve(head, 1);
        if(carry){
            Node *newnode = new Node(carry);
            newnode->next = head;
            head = newnode;
        }
        return head;
    }
};

/*
Time complexity: O(N), where N is the number of nodes present in the linked list.
Space complexity: O(N), auxiliary stack space is used.
*/