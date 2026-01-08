/*
Tag: Array, Hash Table, Prefix Sum

Problem Statement:

There is a rectangular brick wall in front of you with n rows of bricks. The ith row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths. The total width of each row is the same.

Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.

Given the 2D array wall that contains the information about the wall, return the minimum number of crossed bricks after drawing such a vertical line.

Example 1:
Input: wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
Output: 2
Example 2:

Input: wall = [[1],[1],[1]]
Output: 3
 
*/

#include<bits/stdc++.h>
using namespace std;

int leastBricks(vector<vector<int>>& wall) {
    map<long long int,int> mp;
    for(auto &row:wall){
        long long int total=0;
        for(int i=0;i<row.size()-1;i++){
            total+=row[i];
            mp[total]++;
        }
    }

    int high=0;
    for(auto &it:mp){
        high=max(high,it.second);
    }

    return wall.size()-high;
}

/*
My Solution:

- Find out the gaps between the bricks for each row using the prefix sum, because we can draw the line only at the gaps to minimize the number of bricks we hit.
- Store the frequency of each gap in a map.
- The gap with the highest frequency will allow us to cross the least number of bricks.
- Finally, subtract the highest frequency from the total number of rows to get the minimum number of crossed bricks.

This is the best solution with some optimizations in calculations.

*/