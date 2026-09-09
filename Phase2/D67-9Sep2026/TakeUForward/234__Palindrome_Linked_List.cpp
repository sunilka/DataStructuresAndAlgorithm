/*
234. Palindrome Linked List

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast!=nullptr && fast->next!=nullptr) slow = slow->next, fast = fast->next->next;
        ListNode *prev = nullptr, *cur = slow;
        while(cur!=nullptr){
            ListNode *nextnode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextnode;
        }
        ListNode *first = head, *second = prev; 
        while(second!=nullptr){
            if(first->val != second->val) return false;
            first = first->next, second = second->next;
        }
        return true;
    }
};

/*
Time complexity: O(N), where N is the number of nodes present in the given linked list.
Space complexity: O(1), we are not using any extra space, hence the space complexity is constant.
*/