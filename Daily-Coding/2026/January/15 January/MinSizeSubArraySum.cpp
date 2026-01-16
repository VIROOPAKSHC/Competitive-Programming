/*
Tag: Sliding Window, Array

Problem Statement:

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
*/

#include <bits/stdc++.h>
using namespace std;
int minSubArrayLen(int target, vector<int>& nums) {
    if(nums.size()==1){
        return nums[0]>=target;
    }
    int i=0,j=0;
    int curr=0;
    int best_sol=0;
    while(j<nums.size()){
        if(curr+nums[j] < target){
            curr+=nums[j++];
        }
        else if(curr+nums[j]>target){
            if(best_sol == 0){best_sol=j-i+1;}
            else{best_sol=min(best_sol,j-i+1);}
            curr=curr-nums[i++];
        }
        else{
            if(best_sol==0){best_sol=j-i+1;}
            else{best_sol=min(best_sol,j-i+1);}

            i=j;
            curr=nums[i];
            j++;

        }
    }
    return best_sol;
}

/*
My Approach:

- First, we need to understand that we are looking for contiguous subarrays with sum greater than or equal to the target.
- To do that, we need to have a window of indices using 2 pointers and have the sum of all the values in the indices.
- Whenever we add a new index, we check if it is greater, to update the minimum subarray size and remove the first element from the window, or if it is lesser, we update the right pointer to the next element, and if it is equal, we reset the sum and add the first element next to the current element
- We repeat this process until we reach the end of the array, and return the minimum subarray size.

This is the best solution - O(n) time complexity, O(1) space complexity.
*/