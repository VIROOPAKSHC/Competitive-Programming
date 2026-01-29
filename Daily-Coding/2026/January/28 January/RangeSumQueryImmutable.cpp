/*
Tag: Simulation, Design, Easy

Problem Statement: https://leetcode.com/problems/range-sum-query-immutable/
*/
#include<bits/stdc++.h>
using namespace std;
class NumArray {
public:
    vector<int> nums;
    vector<int> prefxsum;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                this->prefxsum.push_back(nums[i]);
                continue;
            }
            this->prefxsum.push_back(nums[i]+this->prefxsum.back());
        }
    }
    
    int sumRange(int left, int right) {
        return this->prefxsum[right]-this->prefxsum[left]+this->nums[left];
    }
};