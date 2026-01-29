/*
Tag: Easy, Array
Problem Statement: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> vect(nums.size()+1,-1);
    for(int &i:nums){
        vect[i]=1;
    }
    vector<int> ans;
    for(int i=1;i<vect.size();i++){
        if(vect[i]==-1){
            ans.push_back(i);
        }
    }
    return ans;

}