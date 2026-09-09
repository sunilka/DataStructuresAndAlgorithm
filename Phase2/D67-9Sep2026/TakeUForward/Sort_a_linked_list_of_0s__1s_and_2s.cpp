/*
Sort a linked list of 0s, 1s and 2s

Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only. Your task is to rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end.

Examples:

Input: head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2
   
Output: 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between. The final list will be:
   
Input: head = 2 → 2 → 0 → 1
   
Output: 0 → 1 → 2 → 2
Explanation: After arranging all the 0s, 1s and 2s in the given format, the output will be:
   
Constraints:
1 ≤ no. of nodes ≤ 106
0 ≤ node->data ≤ 2

*/

#include<bits/stdc++.h>
using namespace std;

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
    Node* segregate(Node* head) {
        if (!head || !head->next) return head;
        Node zeroDummy(0), oneDummy(0), twoDummy(0);
        Node *zp = &zeroDummy, *op = &oneDummy, *tp = &twoDummy;
        Node *tmp = head;
        while (tmp != nullptr) {
            if (tmp->data == 0) zp->next = tmp, zp = zp->next;
            else if (tmp->data == 1) op->next = tmp, op = op->next;
            else tp->next = tmp, tp = tp->next;
            tmp = tmp->next;
        }
        zp->next = (oneDummy.next) ? oneDummy.next : twoDummy.next;
        op->next = twoDummy.next;
        tp->next = nullptr;
        return zeroDummy.next;
    }
};

/*
Time complexity: O(N), where N is the number of nodes present in the given linked list.
Space complexity: O(1), we are not using any extra space here, henve the space complexity is constant here. 
*/