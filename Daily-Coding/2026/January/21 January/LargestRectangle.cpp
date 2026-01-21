/*
Tag: Stack, Monotonic Stack

Problem Statement:


*/
#include<bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
    stack<int> stk;
    int n=heights.size();
    vector<int> right(n),left(n);
    for(int i=0;i<n;i++){
        while(!stk.empty() && heights[stk.top()] >= heights[i])
            stk.pop();
        left[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }
    
    while(!stk.empty()) stk.pop();
    for(int i=n-1;i>=0;i--){
        while(!stk.empty() && heights[stk.top()] >= heights[i])
            stk.pop();
        right[i] = stk.empty() ? n : stk.top();
        stk.push(i);
    }
    
    int maxArea = 0;
    for(int i=0;i<n;i++){
        int width = right[i]-left[i]-1;
        maxArea = max(maxArea,width*heights[i]);
    }
    return maxArea;
}

/*
My Approach(inspired from solutions):

- First to find maximum area, we need to know the width and height of the bars that are included in the calculation.
- To do so, for each of the bar, we find the left smaller and right smaller.
- So, we build 2 arrays where at each index, we check for the left and right smaller, if the current index is the smallest, we take -1 as the smallest for the left because we want the entire left part to be used with this height in the area calculation, similarly for the right smallest, we take n because we want till the right end of the array.
- We do this because, at the area calculation we calculate the area maximum possible by this index, by taking the left most and right most indices where this is the greatest and multiply the width with the height of the bar.
- Finally, we iterate over all the elements and calculate area for each of the index and check max.


*/