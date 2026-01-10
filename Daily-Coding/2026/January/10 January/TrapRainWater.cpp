/*
Tag: 2 Pointers, Array

Problem Statement:
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5

*/

#include<bits /stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    if(height.size()<=1){
        return 0;
    }
    int i=0;
    int j=height.size()-1;
    int capacity=0;
    int leftMax=height[i];
    int rightMax=height[j];
    while(i<=j){
        if(height[i]<=height[j]){
            if(height[i]>=leftMax){
                leftMax=height[i];
            }
            else{
                capacity+=leftMax-height[i];
            }
            i++;
        }
        else{
            if(height[j]>=rightMax){
                rightMax=height[j];
            }
            else{
                capacity+=rightMax-height[j];
            }
            j--;
        }
    
    }
        return capacity;
}

/*
My Solution: (Inspired from solutions)

- We need to find the water trapped at every bar. And the water trapped is dependent on the minimum height of both left and right maximum heights of bars at this index.
- To find that, we initialize 2 pointers for both left and right movement, and also maintain a maximum height seen till now, for left and right.
- Now at every step, we compare the heights of bars at both pointers, if the left one is a smaller or same height bar, we go and look the water it trapped based on its height difference with the leftMaximum till now.
- We update the left maximum if we have a higher bar at the left pointer.
- Then we update the left pointer.
- So at every point, we make sure that either if we encounter a larger bar, we update the maximum or if we update a smaller bar, we update the capacity of water trapped.
- If the right pointer is smaller than the left one, we do the same for the right pointer and right maximum.
- Finally we return the total capacity calculated.

- We are using 2 pointers from left and right to avoid iterating the same loop twice to find left maximum and right maximum, capacity calculation is done in the same loop.

This is the best solution.
*/
