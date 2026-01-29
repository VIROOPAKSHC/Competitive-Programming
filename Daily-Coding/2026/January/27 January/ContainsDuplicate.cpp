/*
Tag: Array, Easy

Problem Statement: https://leetcode.com/problems/contains-duplicate/?q=Duplicate+Values
*/

#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    map<int,int> mp;
    for(int &i:nums){
        mp[i]++;
        if(mp[i]>=2){
            return true;
        }
    }
    return false;
}


