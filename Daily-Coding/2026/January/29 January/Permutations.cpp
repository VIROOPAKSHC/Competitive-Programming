/*
Tag: Medium, Backtracking
Problem Statement: https://leetcode.com/problems/permutations/
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> permute(vector<int>& nums) {
    if(nums.size()==1){
        return {{nums[0]}};
    }
    vector<vector<int>> result;
    for(int i=0;i<nums.size();i++){
        int n = nums[i];
        vector<int> remNums;
        for(int j=0;j<nums.size();j++){
            if(j==i) continue;
            remNums.push_back(nums[j]);
        }
        vector<vector<int>> perms = permute(remNums);
        for(vector<int> &p: perms){
            p.insert(p.begin(),n);
            result.push_back(p);
        }
    }    
    return result;
}
