/*
Tag: Easy, Array

Problem Statement: https://leetcode.com/problems/missing-number/
*/

#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>& nums) {
    vector<int> vect(nums.size()+1,-1);
    for(int &i:nums){
        vect[i]=1;
    }
    for(int i=0;i<vect.size();i++){
        if(vect[i]==-1){
            return i;
        }
    }
    return -1;
}