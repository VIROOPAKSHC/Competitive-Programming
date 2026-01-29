/*
Tag: Bit Manipulation
Problem Statement: https://leetcode.com/problems/single-number/description/?q=Single+Number
*/

#include<bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums) {
    int missing = 0;
    for(int &i:nums){
        missing ^= i;
    }
    return missing;
}