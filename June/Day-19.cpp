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
};

int main(){
    return 0;
}