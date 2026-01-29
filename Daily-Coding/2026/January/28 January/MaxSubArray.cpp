/*
Tag: Dynamic Programming, Array

Problem Statement:https://leetcode.com/problems/maximum-subarray/description/
*/

#include<bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int>& nums) {
    vector<int> DP(nums.size(),0);
    DP[0]=nums[0];
    int maxSub = DP[0];
    for(int i=1;i<nums.size();i++){
        DP[i]=max(nums[i],DP[i-1]+nums[i]);
        maxSub = max(maxSub,DP[i]);
    }
    return maxSub;
}