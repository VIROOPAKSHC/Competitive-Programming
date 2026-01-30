/*
Tag: Stack, Queue, Easy
Problem Statement: https://leetcode.com/problems/implement-stack-using-queues/
*/
#include<bits/stdc++.h>
using namespace std;
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
 
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int val = q1.front();
        // q2.push(val);
        q1.pop();
        while(q2.size() > 0){
            q1.push(q2.front());
            q2.pop();
        }
        return val;
    }
    
    int top() {
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int val = q1.front();
        q2.push(val);
        q1.pop();
        while(q2.size() > 0){
            q1.push(q2.front());
            q2.pop();
        }
        return val;
    }
    
    bool empty() {
        return q1.size()==0;
    }
};