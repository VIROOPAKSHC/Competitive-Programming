/*
Tag: Array, 2 Pointers

Problem Statement:https://leetcode.com/problems/3sum/
*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    set<vector<int>> ans_set;
    for(int i=0;i<nums.size();i++){
        int j=i+1;
        int k=nums.size()-1;
        while(j<k){
            int total = nums[i]+nums[j]+nums[k];
            if(total < 0){
                j++;
            }
            else if(total > 0){
                k--;
            }
            else{
                vector<int> temp = {nums[i],nums[j],nums[k]};
                sort(temp.begin(),temp.end());
                ans_set.insert(temp);
                j++;
                k--;
            }

        }

    }
    vector<vector<int>> ans;
    for(auto &a:ans_set){
        ans.push_back(a);
    }
    return ans;
}