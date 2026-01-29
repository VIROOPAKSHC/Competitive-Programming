/*
Tag: Easy, Array

Problem Statement: https://leetcode.com/problems/two-sum/description/
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        int other= target-nums[i];
        // Check if you have the other value directly before adding
        if(mp.find(other)!=mp.end()){
            return {i,mp[other]};
        }
        // If we cant find any such, then add it . If 2 numbers are same, we will already have one in our map and if the 2*number==target, when we reach the second one, we check for the first one indirectly and the answer will be returned.
        mp[nums[i]]=i;
    }
    return {};
}