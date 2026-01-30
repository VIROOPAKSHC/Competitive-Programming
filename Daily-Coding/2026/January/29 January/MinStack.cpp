/*
Tag: Stack, Medium

Problem Statement: https://leetcode.com/problems/min-stack/
*/
#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    vector<int> mins;
    vector<int> st;
    MinStack() {
    }
    
    void push(int val) {
        if(mins.size()==0){
            mins.push_back(st.size());
        }
        else{
            if(st[mins.back()] > val){
                mins.push_back(st.size());
            }
        }
        st.push_back(val);
    }
    
    void pop() {
        if(mins.back() == st.size()-1){
            mins.pop_back();
        }
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return st[mins.back()];
    }
};