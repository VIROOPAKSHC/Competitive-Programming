/*
Tag: Dynamic Programming, Array

Problem Statement:https://leetcode.com/problems/climbing-stairs/description/
*/
#include<bits/stdc++.h>
using namespace std;
int climbStairs(int n) {
    if(n<=3){
        return n;
    }
    vector<int> DP(n+1,n+1);
    DP[0]=0;
    DP[1]=1;
    DP[2]=2;
    
    DP[3]=3;
    for(int i=3;i<=n;i++){
        DP[i]=DP[i-1]+DP[i-2];
    }
    return DP[n];
}