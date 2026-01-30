/*
Tag: Queue, Stack, Easy
Problem Statement:https://leetcode.com/problems/implement-queue-using-stacks/
*/
#include<bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while(st1.size() > 1){
            st2.push(st1.top());
            st1.pop();
        }
        int val = st1.top();
        st1.pop();
        while(st2.size() > 0){
            st1.push(st2.top());
            st2.pop();
        }
        return val;
    }
    
    int peek() {
         while(st1.size() > 1){
            st2.push(st1.top());
            st1.pop();
        }
        int val = st1.top();
        st1.pop();
        st2.push(val);
        while(st2.size() > 0){
            st1.push(st2.top());
            st2.pop();
        }
        return val;
    }
    
    bool empty() {
        return st1.size()==0;
    }
};
