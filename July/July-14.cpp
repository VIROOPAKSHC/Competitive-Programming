// Author - Chekuri Viroopaksh
// Day 28 - July 14,2024
// Leetcode Hashing

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp1;
        map<int,int> mp2;
        for(int i:nums1){
            mp1[i]++;
        }
        for(int i:nums2){
            mp2[i]++;
        }
        int c1=0,c2=0;
        for(int i:nums1){
            if(mp2[i]){
                c1++;
            }
        }
        for(int i:nums2){
            if(mp1[i]){
                c2++;
            }
        }
        return {c1,c2};
    }
};

int main(){
    return 0;
}
