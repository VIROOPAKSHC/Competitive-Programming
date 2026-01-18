/*
Tag: Stack, Array

Problem Statement:

*/

#include<bits/stdc++.h>
using namespace std;
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    int i=1;
    int j=0;
    st.push(pushed[0]);
    while(i<pushed.size() && j<popped.size()){
        if(st.size() && st.top()==popped[j]){
            if(st.size()){st.pop();}
            else{return false;}
            j++;
        }
        else{
            st.push(pushed[i]);
            i++;
        }
    }
    while(j<popped.size() && st.top()==popped[j]){
            st.pop();
            j++;
    }

    return i==pushed.size() && st.size()==0;
}

/*
My Approach:

*/