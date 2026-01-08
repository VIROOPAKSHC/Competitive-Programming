/*
Tag: Arrays, Hash Table

Problem Statement:
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
 

Constraints:

1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1

*/

#include<bits/stdc++.h>
using namespace std;
int firstMissingPositive(vector<int>& nums) {
    bool exists1=false;
    long int n=nums.size();
    for(int &i:nums){
        if(i==1){
            exists1=true;
        }
        else if(i<=0 || i>n){
            i=1;
        }
    }

    if(!exists1){
        return 1;
    }
    for(int &i:nums){
        int value=abs(i);
        if(value==n){
            nums[0]=-1*abs(nums[0]);
        }
        else{
            nums[value]=-1*abs(nums[value]);
        }
    }

    for(int i=1;i<n;i++){
        if(nums[i]>0){
            return i;
        }
    }
    if(nums[0]>0){
        return n;
    }
    return n+1;
}

/*
My Solution:

- First, we check if the number 1 exists in the array. If not, we return 1 as the smallest missing positive integer.
- Next, we replace all negative numbers, zeros, and numbers greater than n (size of
    the array) with 1, since they are not useful for finding the smallest missing positive integer.
- We then use the array itself to mark the presence of numbers. For each number in the array,
    we take its absolute value and use it as an index to mark the corresponding position in the array as negative.
- Finally, we iterate through the array again to find the first index that contains a positive value.
- The index of this positive value corresponds to the smallest missing positive integer.
This is the best solution.
- We use the input array itself for marking presence, achieving O(1) auxiliary space.
- We handle the special case for the number n by using the first element of the array as a marker.

*/