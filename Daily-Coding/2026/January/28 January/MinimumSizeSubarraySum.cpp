/*
Tag: Array, Sliding Window

Problem Statement: https://leetcode.com/problems/minimum-size-subarray-sum/
*/

#include <bits/stdc++.h>
using namespace std;
int minSubArrayLen(int target, vector<int>& nums) {
    if(nums.size()==1){
        return nums[0]>=target;
    }
    int i=0;
    int j=0;
    int runningsum = 0;
    int minLen = nums.size()+1;
    while(i<nums.size()){
        while(j<nums.size() && runningsum + nums[j] < target){
            runningsum += nums[j];
            j++;
        }
        if(j==nums.size()){
            break;
        }
        while(runningsum + nums[j] >= target){
            minLen = min(minLen,j-i+1);
            runningsum-=nums[i];
            i++;
        }
    }
    if(minLen > nums.size()){
        return 0;
    }
    return minLen;
}