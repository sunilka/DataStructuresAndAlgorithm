/*
Delete All Occurrences in DLL

Given the head of a doubly Linked List and a key x . Delete all occurrences of the given key x if it is present and return the new DLL.

Examples:

Input: 2<->2<->10<->8<->4<->2<->5<->2, x = 2

Output:  10<->8<->4<->5

Explanation: 
All Occurrences of 2 have been deleted.
Input: head = 9<->1<->3<->4<->5<->1<->8<->4, x = 9

Output: 1<->3<->4<->5<->1<->8<->4

Explanation: 
All Occurrences of 9 have been deleted.
Constraints:

1 ≤ size of linked list ≤ 105
0 ≤ node.data ≤ 109

*/

#include<bits/stdc++.h>
using namespace std;

/*Structure of the doubly linked list  Node 
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/

class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution {
  public:
    Node* deleteAllOccurOfX(Node* head, int x) {
        Node* prev = nullptr, *tmp = head, *lastnode = nullptr;
        Node* dummynode = new Node(0);
        prev = dummynode;
        while(tmp){
            if(tmp->data != x){
                prev->next = tmp;
                tmp->prev = prev;
                prev = prev->next;
            }
            tmp = tmp->next;
        }
        if(dummynode->next) dummynode->next->prev = nullptr;
        prev->next = nullptr;
        return dummynode->next;
    }
};

/*
Time complexity: O(N), where N is the number of nodes present in the given linked list.
Space complexity: O(1), we are not using an extra space here, hence the space complexity is constant here.
*/