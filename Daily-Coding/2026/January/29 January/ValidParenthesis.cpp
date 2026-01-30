/*
Tag: Stack, Easy
Problem Statement: https://leetcode.com/problems/valid-parentheses/

*/
#include<bits/stdc++.h>
using namespace std;
 bool isValid(string s) {
    if(s.size()%2!=0){return false;}
    stack<char> st;
    for(char &c:s){
        if(c==')'){
            if(st.size() && st.top() == '('){st.pop();}
            else{return false;}
        } 
        else if(c=='}'){
            if(st.size() && st.top() == '{'){st.pop();}
            else{return false;}
        } 
        else if(c==']'){
            if(st.size() && st.top() == '['){st.pop();}
            else{return false;}
        } 
        else{
            st.push(c);
        }
    }
    return st.size()==0;
}