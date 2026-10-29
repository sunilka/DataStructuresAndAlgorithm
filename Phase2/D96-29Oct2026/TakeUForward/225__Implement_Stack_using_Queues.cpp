/*
225. Implement Stack using Queues
Solved
Easy

Topics
premium lock icon
Companies
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
 

Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, top, and empty.
All the calls to pop and top are valid.
 

Follow-up: Can you implement the stack using only one queue?
*/

#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    std::queue<int> q, tempq;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if (q.empty()) return -1;
        
        // Move all elements except the last one to tempq
        while (q.size() > 1) {
            int ele = q.front();
            q.pop();
            tempq.push(ele);
        }
        
        // The last element is our stack's top/pop element
        int rele = q.front();
        q.pop();
        
        // Move elements back from tempq to q
        while (!tempq.empty()) {
            q.push(tempq.front());
            tempq.pop();
        }
        
        return rele;
    }
    
    int top() {
        if (q.empty()) return -1;
        
        // Move all elements except the last one to tempq
        while (q.size() > 1) {
            int ele = q.front();
            q.pop();
            tempq.push(ele);
        }
        
        // The last element is the top element
        int rele = q.front();
        q.pop();           
        
        // Push rele into tempq too, so it doesn't get lost
        tempq.push(rele); 
        
        // Move all elements back from tempq to q
        while (!tempq.empty()) {
            q.push(tempq.front());
            tempq.pop();
        }
        
        return rele;
    }
    
    bool empty() {
        return q.empty();
    }
};