/*
Tag: Easy, Arrays

Problem Statement: https://leetcode.com/problems/minimum-time-visiting-all-points/
*/
#include<bits/stdc++.h>
using namespace std;
int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int time=0;
    for(int i=1;i<points.size();i++){
        int x_dist = points[i][0]-points[i-1][0];
        int y_dist = points[i][1]-points[i-1][1];
        if(x_dist == 0){
            time+=abs(y_dist);
            continue;
        }
        if(y_dist == 0){
            time+=abs(x_dist);
            continue;
        }
        time+=max(abs(x_dist),abs(y_dist));
        
    }
    return time;
}