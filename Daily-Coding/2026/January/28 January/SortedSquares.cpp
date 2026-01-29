/*
Tag: Easy, Array, 2 Pointer

Problem Statement:  https://leetcode.com/problems/squares-of-a-sorted-array/
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> sortedSquares(vector<int>& nums) {
    int firstnonneg = -1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>=0 & firstnonneg==-1){
            firstnonneg=i;
            break;
        
        }
    }
    if(firstnonneg == -1){
    firstnonneg = nums.size()-1;
    }
    int i=0;
    int j=nums.size()-1;
    vector<int> ans;
    while(i<firstnonneg && j>=firstnonneg){
        long int leftprod = nums[i]*nums[i];
        long int rightprod = nums[j]*nums[j];
        if(leftprod > rightprod){
            ans.push_back(leftprod);
            i++;
        }
        else if(leftprod < rightprod){
            ans.push_back(rightprod);
            j--;
        }
        else{
            ans.push_back(leftprod);
            ans.push_back(rightprod);
            i++;
            j--;
        }
    }
    while(j>=firstnonneg){
        long int prod=nums[j]*nums[j];
        ans.push_back(prod);
        j--;
    }
    while(i<firstnonneg){
        long int prod=nums[i]*nums[i];
        ans.push_back(prod);
        i++;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}