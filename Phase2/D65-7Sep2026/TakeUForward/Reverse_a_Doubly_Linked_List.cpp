/*
Reverse a Doubly Linked List
Given the head of a doubly linked list, reverse the list and return the head of the reversed doubly linked list.

Note: Driver code will print the returned list in both forward and backward directions.

Examples:

Input:

Output: 
5 <-> 4 <-> 3
3 <-> 4 <-> 5
Explanation: After reversing the given doubly linked list the new list will be 5 <-> 4 <-> 3.

Input: 

Output: 
196 <-> 59 <-> 122 <-> 75
75 <-> 122 <-> 59 <-> 196
Explanation: After reversing the given doubly linked list the new list will be 196 <-> 59 <-> 122 <-> 75.

Constraints:

1 ≤ size of linked list ≤ 106
0 ≤ node.data ≤ 104
*/

/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/

class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution {
  public:
    Node *reverse(Node *head) {
        if(head == nullptr) return nullptr;
        Node* tmp1 = head;
        Node *tmp2 = head -> next;
        Node *newhead = nullptr;
        while(tmp1!=nullptr){
            tmp1 -> next = tmp1 -> prev;
            tmp1 -> prev = tmp2;
            newhead = tmp1;
            tmp1 = tmp2;
            if(tmp2!=nullptr){
                tmp2 = tmp2 -> next;
            }
        }
        return newhead;
    }
};

/*
Time complexity: O(N), where N is the number of nodes in the linked list.
Space complexity: O(1), constant space complexity.
*/

/*
Recusive code
*/

class Solution {
  public:
    Node* solve(Node* prevn, Node* curn){
        if(curn==nullptr) return prevn;
        Node* nextnode = curn->next;
        curn->next = curn->prev;
        curn->prev = nextnode;
        return solve(curn, nextnode);
    }
    Node *reverse(Node *head) {
        return solve(nullptr, head);
    }
};

/*
Time complexity: O(N), where N is the number of nodes present in the linked list.
Space complexity: O(N) auxiliary stack space. 
*/