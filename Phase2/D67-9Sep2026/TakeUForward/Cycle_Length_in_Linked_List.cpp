/*
Cycle Length in Linked List
Given the head of a linked list. A linked list contains a cycle if its last node is connected to a previous node. If the given list contains a cycle, return the length of the cycle. Otherwise, return 0.

Note: Internally, the driver code uses an integer x to represent the position (1-based indexing) of the node to which the last node is connected. If x = 0, it means last node points to null which indicating there is no loop.

Examples:

Input: 

Output: 4
Explanation: There exists a loop in the linked list 2 -> 3 -> 4 -> 5, the length of the loop is 4.
Input:

Output: 3
Explanation: There exists a loop in the linked list 19 -> 33 -> 10, the length of loop is 3.
Input:

Output: 0
Explanation: There is no loop.
Constraints:

1 ≤ size of linked list ≤ 105
1 ≤ node.data ≤ 104
0 ≤ x < head.size()

*/

#include<bits/stdc++.h>
using namespace std;


/* Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

// Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        if(head==nullptr) return 0;
        if(head->next==nullptr) return 0;
        Node* slow = head, *fast = head;
        do{
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }while(fast!=nullptr && fast->next!=nullptr);
        if(fast == nullptr || fast->next==nullptr) return 0;
        Node *ans = head;
        while(ans!=slow){
            slow = slow->next;
            ans = ans->next;
        }
        int l = 0;
        do{
            l+=1;
            ans = ans->next;
        }while(ans!=slow);
        return l;
    }
};

/*
Time complexity: O(N), where N is the number of nodes present in the given linked list.
Space complexity: O(1), we are not using extra space, hence the space complexity is constant.
*/