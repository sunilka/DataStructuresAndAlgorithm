/*
142. Linked List Cycle II

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return nullptr;
        ListNode* slow = head, *fast = head;
        do{
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }while(fast!=nullptr && fast->next!=nullptr);
        if(fast == nullptr || fast->next==nullptr) return nullptr;
        ListNode *ans = head;
        while(ans!=slow){
            slow = slow->next;
            ans = ans->next;
        }
        return ans;
    }
};

/*
Time complexity: O(N), where N is the number of nodes present in the linked list.
Space complexity: O(1), we are not using extra space here, hence the space complexity is constant.
*/


/*
Phase 1: Meeting Point
When slow and fast meet inside the cycle:
Distance traveled by slow: Dslow=L+k
Distance traveled by fast: Dfast=L+nC+k
Since fast travels at twice the speed of slow:
Dfast=2⋅Dslow
​	
 
Substitute the distances:
L+nC+k=2(L+k)
L+nC+k=2L+2k
Subtract (L+k) from both sides:
L=nC−k
Rearrange to isolate the cycle remainder (C−k):
L=(n−1)C+(C−k)
*/