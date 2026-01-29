/*
Tag: Medium, Arrays

Problem Statement: https://leetcode.com/problems/spiral-matrix/
*/

#include<bits/stdc++.h>
using namespace std;
bool visitedall(vector<vector<int>> visited){
    for(int i=0;i<visited.size();i++){
        for(int j=0;j<visited[i].size();j++){
            if(visited[i][j]==-1){
                return false;
            }
        }
    }
    return true;
}

vector<int> movearound(vector<vector<int>>&matrix, int start_x, int start_y, int end_x, int end_y,vector<vector<int>>& visited){
    
    vector<int> ans;
    for(int i=start_y;i<=end_y;i++){
        if(visited[start_x][i]==1) continue;
        visited[start_x][i]=1;
        ans.push_back(matrix[start_x][i]);
    }
    for(int i=start_x+1;i<=end_x;i++){
        if(visited[i][end_y]==1) continue;
        visited[i][end_y]=1;
        ans.push_back(matrix[i][end_y]);
    }
    for(int i=end_y-1;i>=start_y;i--){
        if(visited[end_x][i]==1) continue;
        visited[end_x][i]=1;
        ans.push_back(matrix[end_x][i]);
    }
    for(int i=end_x-1;i>=start_x+1;i--){
        if(visited[i][start_y]==1) continue;
        visited[i][start_y]=1;
        ans.push_back(matrix[i][start_y]);
    }
    return ans;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    
    int n=matrix.size()-1;
    int m= matrix[0].size()-1;
    vector<vector<int>> visited;
    for(int i=0;i<n+1;i++){
        vector<int> temp;
        for(int j=0;j<m+1;j++){
            temp.push_back(-1);
        }
        visited.push_back(temp);
    }
    vector<int> start_point = {0,0};
    vector<int> end_point = {n,m};
    vector<int> order;
    while(true){
        vector<int> temp = movearound(matrix,start_point[0],start_point[1],end_point[0],end_point[1],visited);
        for(auto &i:temp){
            order.push_back(i);
        }
        start_point[0]+=1;
        start_point[1]+=1;
        end_point[0]-=1;
        end_point[1]-=1;

        if(visitedall(visited)) break;

    }
    return order;
}