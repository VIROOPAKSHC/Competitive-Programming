// Author - Chekuri Viroopaksh
// Day 22 - July 8, 2024
// Sorting Leetcode problems

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int c=0;
        int start = nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]-start > k){
                c++;
                start = nums[i];
            }
        }
        return c+1;
        
    }
    
};

int main(){
    vector<int> s;
    
    return 0;
}