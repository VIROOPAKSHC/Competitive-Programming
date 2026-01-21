/*
Tag: Array, Greedy

Problem Statement:
You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.

 

Example 1:

Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
Example 2:

Input: arrays = [[1],[1]]
Output: 0
 

Constraints:

m == arrays.length
2 <= m <= 105
1 <= arrays[i].length <= 500
-104 <= arrays[i][j] <= 10^4
arrays[i] is sorted in ascending order.
There will be at most 105 integers in all the arrays.

*/

#include<bits/stdc++.h>
using namespace std;

int maxDistance(vector<vector<int>>& arrays) {
    int MaxDist = 0;
    int minn = arrays[0][0];
    int maxx = arrays[0].back();
    for(int i=1;i<arrays.size();i++){
        auto &arr = arrays[i];
        MaxDist = max(MaxDist, abs(minn-arr.back()));
        MaxDist = max(MaxDist, abs(maxx-arr[0]));
        
        minn = min(minn,arr[0]);
        maxx = max(maxx,arr.back());
    }
    return MaxDist;
}

/*
My Approach (inspired from solutions):

- We initialize two variables, `minn` and `maxx`, to keep track of the minimum and maximum values encountered so far from the arrays.
- We iterate through each array starting from the second one.
- For each array, we calculate the potential maximum distances using the current `minn` and `maxx` values.
- We update `minn` and `maxx` with the first and last elements of the current array, respectively.
- Finally, we return the maximum distance found.

This is the best solution.
*/