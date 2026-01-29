/*
Tag: Easy, Array

Problem Statement: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> copy_sorted;
    for(int &i:nums){copy_sorted.push_back(i);}
    sort(copy_sorted.begin(),copy_sorted.end());
    map<int,int> mp;
    for(int i=0;i<copy_sorted.size();i++){
        if(mp.find(copy_sorted[i])!=mp.end()){continue;}
        mp[copy_sorted[i]] = i;
    }
    vector<int> ans;
    for(int &i:nums){
        ans.push_back(mp[i]);
    }
    return ans;
}