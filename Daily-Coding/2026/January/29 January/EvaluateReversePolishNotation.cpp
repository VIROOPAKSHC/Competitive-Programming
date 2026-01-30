/*
Tag: Stack, Medium
Problem Statement: https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/
#include<bits/stdc++.h>
using namespace std;
int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for(string &s:tokens){
        if(s=="+"){
            int b=st.top();
            st.pop();
            int a = st.top();
            st.pop();
            st.push(a+b);
        }
        else if(s=="-"){
            int b=st.top();
            st.pop();
            int a = st.top();
            st.pop();
            st.push(a-b);
        }
        else if(s=="/"){
            int b=st.top();
            st.pop();
            int a = st.top();
            st.pop();
            st.push(a/b);
        }
        else if(s=="*"){
            int b=st.top();
            st.pop();
            int a = st.top();
            st.pop();
            st.push(a*b);
        }
        else{
            st.push(stoi(s));
        }
    }
    return st.top();
}