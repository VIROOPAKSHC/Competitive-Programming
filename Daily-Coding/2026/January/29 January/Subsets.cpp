/*
Tag: Medium, Backtracking

Problem Statement: https://leetcode.com/problems/subsets/
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> total;
    total.push_back({});
    for(int &i:nums){
        vector<vector<int>> temp;
        for(auto v:total){
            temp.push_back(v);
            v.push_back(i);
            temp.push_back(v);
        }
        total = temp;
    }
    return total;
}