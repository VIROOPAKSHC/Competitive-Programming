// Author - Chekuri Viroopaksh
// Day 19 - 2nd, July 2024
// LeetCode Sorting problems

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int> sorrt = nums;
        sort(sorrt.begin(),sorrt.end());
        int n=nums.size();
        if(sorrt[n-1]>=2*sorrt[n-2]){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==sorrt[n-1]){
                    return i;
                }
            }
        }
        return -1;
    }
    bool isGood(vector<int>& nums) {
        if(nums.size()==1){return false;}
        
        sort(nums.begin(),nums.end());
        int n = nums[nums.size()-1];
        if(n+1 != nums.size()){
            return false;
        }
        if(nums[0]!=1){
            return false;
        }
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]==nums[i-1]){
                return false;
            }
        }
        if(nums[nums.size()-1]!=nums[nums.size()-2]){
            return false;
        }
        return true;
    }
};

int main(){
    return 0;
}