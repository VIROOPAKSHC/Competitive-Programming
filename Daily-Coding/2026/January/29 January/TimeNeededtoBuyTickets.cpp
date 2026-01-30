/*
Tag: Queue, Simulation
Problem Statement: https://leetcode.com/problems/time-needed-to-buy-tickets/
*/
#include<bits/stdc++.h>
using namespace std;
int timeRequiredToBuy(vector<int>& tickets, int k) {
    queue<int> indices;
    vector<int> times(tickets.size(),0);
    for(int i=0;i<tickets.size();i++){
        indices.push(i);
    }
    while(indices.size()){
        int top = indices.front();
        indices.pop();
        for(int i=0;i<times.size();i++){
            if(tickets[i]>0){ 
                times[i]++;
            }
        }
        tickets[top]--;
        if(tickets[top]>0){
            indices.push(top);
        }
    }
    return times[k];
}