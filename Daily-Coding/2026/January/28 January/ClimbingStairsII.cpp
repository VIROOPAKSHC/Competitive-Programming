/*
Tag: Dynamic Programming, Medium
Problem Statement:https://leetcode.com/problems/climbing-stairs-ii/
*/
#include<bits/stdc++.h>
using namespace std;
int climbStairs(int n, vector<int>& costs) {
    vector<int> DP(n+1,0);
    DP[0]=0;
    for(int i=1;i<=n;i++){
        int idx=i-1;
        vector<int> all;
        if(i>=3){
            all.push_back(costs[idx]+9+DP[i-3]);
        }
        if(i>=2){
            all.push_back(costs[idx]+4+DP[i-2]);
        }
        if(i>=1){
            all.push_back(costs[idx]+1+DP[i-1]);
        }
        sort(all.begin(),all.end());
        DP[i]=all[0];
    }
    return DP[n];
}