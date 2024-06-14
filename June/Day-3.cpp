// Author - Chekuri Viroopaksh
// Day 3 - 14th of June, 2024
// Striver's A2Z DSA sheet

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int pos=0;
        while(pos<nums.size()-1){
            if(nums[pos]>nums[(pos+1)]){
                break;
            }
            pos++;
        }
        
        int n=nums.size();
        int i=(pos+1)%n;
        int curr=i;
        
        for(i;i<curr+n;i++){
            if((i)%n == pos){
                break;
            }
            if(nums[i%n]>nums[(i+1)%n]){
                return false;
            }
        }
        return true;
    }
};

int main(){

}