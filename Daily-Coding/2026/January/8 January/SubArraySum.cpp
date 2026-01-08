/*
Tag: Prefix Sum, Hash Table

Problem Statement:

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 10^4
-1000 <= nums[i] <= 1000
-10^7 <= k <= 10^7
*/

#include<bits/stdc++.h>
using namespace std;


int subarraySum(vector<int>& nums, int k) {
    int sum=0;
    int total=0;
    unordered_map<int,int> mp;
    mp[sum]=1;
    for(auto &i:nums){
        sum+=i;
        int other_val = sum-k;
        if(mp.find(other_val)!=mp.end()){
            total+=mp[other_val];
        }
        mp[sum]++;
    }
    return total;
}

/*
My Solution:

- First we define an unordered map to store the frequency of prefix sums.
- We initialize the sum variable to keep track of the current prefix sum and total to count the number of subarrays.
- We iterate through each element in the array, updating the prefix sum.
- For each prefix sum, we check if there exists a previous prefix sum such that the difference between the current prefix sum and that previous prefix sum equals k.
- If such a previous prefix sum exists, we add its frequency to the total count of subarrays.
- Finally, we return the total count of subarrays whose sum equals k.

This is the best solution.

- map[sum]=1 is used to handle the case when the subarray starts from index 0.

*/