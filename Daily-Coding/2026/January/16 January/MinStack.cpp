/*
Tag: Stack

Problem Statement:

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    vector<int> stack;
    vector<int> min_idxs;
    MinStack() {
        
    }
    
    void push(int val) {
        if(this->min_idxs.size()==0){
            this->min_idxs.push_back(0);
        }
        else{
            int prev=this->min_idxs.back();
            if(this->stack[prev]>=val){
                this->min_idxs.push_back(this->stack.size());
            }
            else{
                this->min_idxs.push_back(this->min_idxs.back());
            }
        }
        this->stack.push_back(val);
    }
    
    void pop() {
        this->min_idxs.erase(this->min_idxs.end());
        this->stack.erase(this->stack.end());
    }
    
    int top() {
        return this->stack.back();
    }
    
    int getMin() {
        return this->stack[this->min_idxs.back()];
    }
};