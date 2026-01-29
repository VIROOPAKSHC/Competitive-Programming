/*
Tag: Dynamic Programming, Greedy

Problem Statement:https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/
#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int sell=prices[0];
        int maxProfit = 0;
        for(int &i:prices){
            
            maxProfit=max(maxProfit,i-min(buy,i));
            buy = min(buy,i);
        }
        return maxProfit;
    }