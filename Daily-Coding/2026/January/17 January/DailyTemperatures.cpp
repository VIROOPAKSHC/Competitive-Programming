/*
Tag: Stack, Monotonic Stack

Problem Statement:

*/
#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> results(temperatures.size());
    stack<int> st;
    for(int i=0;i<temperatures.size();i++){
        while(!st.empty() && temperatures[st.top()] < temperatures[i]){
            results[st.top()] = i-st.top();
            st.pop();
        }
        st.push(i);
    }
    return results;
}

/*
My Approach:

- For every temperature, you check the top of the stack if this is higher than the top of the stack, if so, we change the distance to the higher temperature from the top of the stack index
- And we add every temperature again.

*/