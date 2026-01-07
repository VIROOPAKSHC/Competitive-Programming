// Author - Chekuri Viroopaksh
// Day 29 - July 17, 2024
// Leetcode Backtracking

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets;
class Solution {
public:
    void Generate(vector<int> nums, int k,vector<int> subset){
        if(k==nums.size()){
            subsets.push_back(subset);
            subset={};
            
        }
        else{
            Generate(nums,k+1,subset);
            subset.push_back(nums[k]);
            Generate(nums,k+1,subset);
            subset.pop_back();
        }
    }
    int subsetXORSum(vector<int>& nums) {
        subsets = {};
        Generate(nums,0,{});
        int total = 0;
        for(vector<int> subset:subsets){
            if(subset.size()==0){
                continue;
            }
            int s=subset[0];
            for(int i=1;i<subset.size();i++){
                if(i==1){
                    s=s^subset[i];
                }
                else{
                    s=s^subset[i];
                }
            }
            total+=s;
        }
        return total;
    }
};
int main(){
    return 0;
}
