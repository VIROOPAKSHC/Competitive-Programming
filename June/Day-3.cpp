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
    int removeDuplicates(vector<int>& nums) {
        int i=1,j=1;
        while(i<nums.size()){
            if(nums[i]!=nums[j-1]){
                nums[j]=nums[i];
                j++;
            }
            i++;
        }
        return j;
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        int gcd=__gcd(n,k);
        k=k%n;
        for(int i=0;i<gcd;i++){
            int temp=nums[i];
            int j=i;
            int l;
            while(true){
                l=j-k;
                if(l<0){
                    l=l+n;
                }
                if(l==i){
                    break;
                }
                nums[j]=nums[l];
                j=l;
            }
            nums[j]=temp;
        
};

int main(){

}