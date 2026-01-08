/*
Tag: Prefix Sum, Arrays

Problem Statement:
You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.

In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.

Each answer[i] is calculated considering the initial state of the boxes.

 

Example 1:

Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.
Example 2:

Input: boxes = "001011"
Output: [11,8,5,4,3,4]
 

Constraints:

n == boxes.length
1 <= n <= 2000
boxes[i] is either '0' or '1'.
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> minOperations(string boxes) {
    vector<int> ans;
    for(int i=0;i<boxes.size();i++){
        int total=0;
        for(int j=0;j<boxes.size();j++){
            if(j==i){continue;}
            if(boxes[j]=='0'){continue;}
            total=total+abs(j-i);
        }
        ans.push_back(total);
    }
    return ans;
}

/*
My Solution:

- I simply used 2 nested loops to calculate the distances of all balls from the current position to their positions by looping over all possible pairs of positions.

The Best Solution:

- Use 2 prefix sum arrays and 2 variables to store the operations for all the balls encountered and cumulative number of balls from the left and right side till now respectively.
- Use a 2 single loops to iterate over all the indices from left to right and right to left.
- In the loop, update the left side of the prefix count of array by adding the current operations to the prefix sum array and then updating the operations by adding the number of balls encountered so far.
- Similarly, update the right side of the prefix count of array by adding the current operations to the prefix sum array and then updating the operations by adding the number of balls encountered so far.
- Finally, add the left and right prefix sum arrays to get the final answer.
*/