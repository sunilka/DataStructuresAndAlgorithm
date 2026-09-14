/*
Flattening a Linked List
In a linked list, every node has two pointers: next and bottom. The heads of n linked lists are connected using the next pointer, while the bottom pointer points to the next node in the current linked list.
Each linked list is sorted in non-decreasing order of data, and the head nodes are also sorted in non-decreasing order.

Given the head of the first linked list, flatten the linked lists into a single sorted linked list such that every node is connected using only the bottom pointers.

Examples:

Input:

Output: 5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 40 -> 45.
Explanation: 
Bottom pointer of 5 is pointing to 7.
Bottom pointer of 7 is pointing to 8.
Bottom pointer of 10 is pointing to 20 and so on.
So, after flattening the linked list the sorted list will be 
5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 40 -> 45.
Input:

Output: 5 -> 7 -> 8 -> 10 -> 19 -> 22 -> 28 -> 30 -> 50
Explanation:
Bottom pointer of 5 is pointing to 7.
Bottom pointer of 7 is pointing to 8.
Bottom pointer of 8 is pointing to 30 and so on.
So, after flattening the linked list the sorted list will be 
5 -> 7 -> 8 -> 10 -> 19 -> 22 -> 28 -> 30 -> 50.
Constraints:
0 ≤ n ≤ 104
1 ≤ number of nodes in each list ≤ 50
1 ≤ node->data ≤ 5*105
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};

class Solution {
  public:
    Node* merge(Node *tmp1, Node *tmp2) {
        Node* dummy = new Node(-1);
        Node* atmp = dummy;

        while (tmp1 && tmp2) {
            if (tmp1->data <= tmp2->data) {
                atmp->bottom = tmp1;
                tmp1 = tmp1->bottom;
            } else {
                atmp->bottom = tmp2;
                tmp2 = tmp2->bottom;
            }
            atmp = atmp->bottom;
        }

        if (tmp1) atmp->bottom = tmp1;
        else atmp->bottom = tmp2;

        Node* result = dummy->bottom;
        delete dummy;
        return result;
    }

    Node* flatten(Node* head) {
        if (!head || !head->next) return head;
        Node* right = flatten(head->next);
        head->next = nullptr;
        return merge(head, right);
    }
};

/*
Time complexity: O(N*M), where N is the number of nodes present in the hortizontal direction of the linked list and M is the 
number max number of nodes present in the vertical direction of the linked list.
Space complexity: O(N) auxiliary stack space is used.
*/