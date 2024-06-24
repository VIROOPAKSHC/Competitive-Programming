// Author - Chekuri Viroopaksh
// Day 13 - 24 June, 2024
// Striver's A2Z DSA sheet
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int el1 = INT_MIN,el2 = INT_MIN,cnt1=0,cnt2=0;
        for(int i:nums){
            if(cnt1==0 && el2!=i){
                cnt1=1;
                el1=i;
            }
            else if(cnt2==0 && el1!=i){
                cnt2=1;
                el2=i;
            }
            else if(el1==i){
                cnt1++;
            }
            else if(el2==i){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1=0;
        cnt2=0;
        for(int i:nums){
            if(i==el1)
                cnt1++;
            else if(i==el2){
                cnt2++;
            }
        }
        if(cnt1 >= int(n/3)+1)
            ans.push_back(el1);
        if(cnt2 >= int(n/3)+1)
            ans.push_back(el2);
        return ans;
    }
};

int main(){
    return 0;
}