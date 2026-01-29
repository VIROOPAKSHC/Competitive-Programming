/*
Tag: Array, Binary Search, Sorting

Problem Statement: https://leetcode.com/problems/minimum-absolute-sum-difference/description/
*/
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    vector<long long int> ans;
    int maxdiff = -1;
    int maxdiffindx = -1;
    long long int total = 0;
    for(int i=0;i<nums1.size();i++){
        long long int diff = abs(nums2[i]-nums1[i]);
        if(maxdiff < diff){
            maxdiff = diff;
            maxdiffindx = i;
        }
        ans.push_back(diff);
        total += diff;
    }

    sort(nums1.begin(),nums1.end());
    long long int totalMin = total;
    cout<<totalMin<<endl;
    for(auto i=0;i<ans.size();i++){ 
        long long int temp = total;
        auto it = lower_bound(nums1.begin(),nums1.end(),nums2[i]);
        temp = (temp-ans[i]);
        long long int val;
        if(it==nums1.begin()){
            val = abs(*it-nums2[i]);
        }
        else if(it==nums1.end()){
            val = abs(nums1.back()-nums2[i]);
        }
        else{
            val =  min(abs(*it-nums2[i]),abs(*(it-1)-nums2[i]));
        }
        val = min(val,(long long int)(ans[i]));
        temp = (temp + val);
        totalMin = min(totalMin,temp);
    }
    return totalMin%mod;
}