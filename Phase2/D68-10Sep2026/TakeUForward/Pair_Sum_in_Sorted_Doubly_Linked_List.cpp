/*
Pair Sum in Sorted Doubly Linked List

Given a sorted doubly linked list containing distinct positive integers and an integer target, find all pairs of nodes whose values add up to target.

Examples :

Input:

target = 7
Output: [[1, 6], [2, 5]]
Explanation: There are two pairs (1, 6) and (2,5) with sum 7.
Input: 

target = 6
Output: [[1, 5]]
Explanation: There is one pairs  (1, 5) with sum 6.
Constraints:

1 ≤ size of linked list, target ≤ 105
0 ≤ node.data ≤ 105
*/

#include<bits/stdc++.h>
using namespace std;

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
}; */

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
    vector<vector<int>> givenSumPairs(Node* head, int x) {
        vector<vector<int>> ans;
        Node* first = head, *last = head;
        while(last->next!=nullptr) last = last->next;
        while(first!=last && last->next != first){
            int sum = first->data + last->data;
            if(sum == x){
                ans.push_back({first->data, last->data});
                first = first->next, last=last->prev;
            } 
            else if(sum > x) last = last->prev;
            else first = first->next;
        }
        return ans;
    }
};

/*
Time complexity: O(N), where N is the number of nodes present in the linked list.
Space complexity: O(1), we are not using any extra space here, hence is the space complexity is constant.
*/