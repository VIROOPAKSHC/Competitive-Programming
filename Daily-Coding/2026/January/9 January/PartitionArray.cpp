/*
Tag: Two Pointers, Arrays

Problem Statement:

You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:

Every element less than pivot appears before every element greater than pivot.
Every element equal to pivot appears in between the elements less than and greater than pivot.
The relative order of the elements less than pivot and the elements greater than pivot is maintained.
More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. If i < j and both elements are smaller (or larger) than pivot, then pi < pj.
Return nums after the rearrangement.

 

Example 1:

Input: nums = [9,12,5,10,14,3,10], pivot = 10
Output: [9,5,3,10,10,12,14]
Explanation: 
The elements 9, 5, and 3 are less than the pivot so they are on the left side of the array.
The elements 12 and 14 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [9, 5, 3] and [12, 14] are the respective orderings.
Example 2:

Input: nums = [-3,4,3,2], pivot = 2
Output: [-3,2,4,3]
Explanation: 
The element -3 is less than the pivot so it is on the left side of the array.
The elements 4 and 3 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [-3] and [4, 3] are the respective orderings.
 

Constraints:

1 <= nums.length <= 10^5
-10^6 <= nums[i] <= 10^6
pivot equals to an element of nums.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot) {
    int lessI=0;
    int greaterI=nums.size()-1;
    vector<int> ans(nums.size());
    for(int i=0, j=nums.size()-1; i<nums.size();i++, j--){
        if(nums[i]<pivot){
            ans[lessI]=nums[i];
            lessI++;
        }
        if(nums[j]>pivot){
            ans[greaterI]=nums[j];
            greaterI--;
        }
    }
    while(lessI<=greaterI){
        ans[lessI]=pivot;
        lessI++;
    }
    return ans;
}

/*
My Solution:

- Start by initializing two pointers, `lessI` and `greaterI`, to track the positions for elements less than and greater than the pivot, respectively.
- Create a new vector `ans` of the same size as `nums` to store the rearranged elements.
- Iterate through the `nums` array from both ends simultaneously:
    - If the current element from the left (`nums[i]`) is less than the pivot, place it at the `lessI` position in `ans` and increment `lessI`.
    - If the current element from the right (`nums[j]`) is greater than the pivot, place it at the `greaterI` position in `ans` and decrement `greaterI`.
- After processing all elements, fill the remaining positions between `lessI` and `greaterI` in `ans` with the pivot value.
- Finally, return the rearranged array `ans`.


*/