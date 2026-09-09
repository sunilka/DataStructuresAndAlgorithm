/*
148. Sort List
Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
 

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
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
    ListNode* get_middle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge_sorted_ll(ListNode* left, ListNode* right) {
        ListNode* dummynode = new ListNode(-1);
        ListNode* temp = dummynode;

        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) { 
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        if (left != nullptr) {
            temp->next = left;
        } else {
            temp->next = right;
        }

        ListNode* result = dummynode->next;
        delete dummynode;
        return result;
    }

    ListNode* merge_sort(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* middle = get_middle(head);
        ListNode* right = middle->next;
        ListNode* left = head;
        middle->next = nullptr;
        
        left = merge_sort(left);
        right = merge_sort(right);
        
        return merge_sorted_ll(left, right);
    }

    ListNode* sortList(ListNode* head) {
        return merge_sort(head);
    }
};

/*
Time complexity: O(NlogN), where N is the number of nodes present in the linked list.
Space complexity: O(logN), auxiliary stack space is used here. 
*/