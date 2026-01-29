/*
Tag: Hashmap, Array
Problem Statement: https://leetcode.com/problems/contains-duplicate-ii/
*/
#include <bits/stdc++.h>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]] = i;
                continue;
            }
            if(abs(i - mp[nums[i]]) <= k){
                return true;
            }
            else{
                mp[nums[i]] = i;
            }
        }
        return false;
    }