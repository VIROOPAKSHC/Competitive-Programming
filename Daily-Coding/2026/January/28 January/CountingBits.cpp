/*
Tag: Dynamic Programming, Easy
Problem Statement: https://leetcode.com/problems/counting-bits/
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> countBits(int n) {
    if(n==0){return {0};}
    if(n==1){return {0,1};}
    vector<int> DP(n+1,0);
    DP[0]=0;
    DP[1]=1;
    DP[2]=1;
    for(int i=3;i<=n;i++){
        DP[i]=DP[i/2]+DP[i%2];
    }
    return DP;
}