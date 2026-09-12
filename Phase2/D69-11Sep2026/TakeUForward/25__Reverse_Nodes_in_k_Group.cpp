/*
25. Reverse Nodes in k-Group

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

Follow-up: Can you solve the problem in O(1) extra memory space?
*/

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse_ll(ListNode *head){
        ListNode *prev = nullptr, *cur = head;
        while(cur){
            ListNode* next_node = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next_node;
        }
        return prev;
    }
    ListNode* solve(ListNode* head, int k){
        if(head == nullptr) return nullptr;
        ListNode *tmp = head;
        for(int i=0; i<k-1; i++){
            if(tmp->next==nullptr) return head;
            tmp = tmp->next;
        }
        ListNode *next_head = solve(tmp->next, k);
        tmp->next = nullptr;
        ListNode* reversed_head = reverse_ll(head);
        head->next = next_head;
        return reversed_head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return solve(head, k);
    }
};

/*
Time complexity: O(N), where N is the number of elements present in the given linked list.
Space complexity: O(N/k) auxiliary stack space.
*/