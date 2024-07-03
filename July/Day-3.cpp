// Author - Chekuri Viroopaksh
// Day 20 - 3rd, July, 2024
// Sorting Leetcode problems

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int c=0;
        sort(nums.begin(),nums.end());
        while(true){     
            if(nums[nums.size()-1]==0){
                break;
            }
            int iter_Val = nums[0];       
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                    continue;
                }
                else if(nums[i]!=0 && iter_Val == nums[0]){
                    iter_Val = nums[i];
                    nums[i]=0;
                }
                else{
                    nums[i]-=iter_Val;
                }
            }
            c++;
            

        }
        return c;
    }
    int minimumOperations_Stylish(vector<int>& nums) {
        unordered_set<int> pos;
        for(int a:nums){
            if(a){
                pos.insert(a);
            }
        }
        return pos.size();
    }
};

int main(){
    return 0;
}