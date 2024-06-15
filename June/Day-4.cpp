// Author - Chekuri Viroopaksh
// Day 4 - 15th of June, 2024.
// Striver's A2Z DSA sheet

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s=nums.size();
        for(int i=0;i<s;i++){
            if(nums[i]!=0){
                continue;
            }
            int j=i+1;
            while(j<s && nums[j]==0 ){
                j++;
            }
            if(j>=s){
                return;
            }
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
    }
};

int main(){
    return 0;
}