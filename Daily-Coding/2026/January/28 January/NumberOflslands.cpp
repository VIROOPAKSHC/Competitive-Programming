/*
Tag: Medium, BFS, Arrays

Problem Statement: https://leetcode.com/problems/number-of-islands/
*/

#include<bits/stdc++.h>
using namespace std;
void bfs(vector<vector<char>> grid, int i, int j,vector<vector<int>> &visited, int n, int m){
    queue<vector<int>> q;
    q.push({i,j});
    vector<vector<int>> directions={{-1,0},{0,-1},{1,0},{0,1}};
    while(q.size()!=0){
        auto location = q.front();
        q.pop();
        for(auto &dir:directions){
            int xx = dir[0]+location[0];
            int yy = dir[1]+location[1];
            if (!(xx>=0 && xx<=n-1)){
                continue;
            }
            if (!(yy>=0 && yy<=m-1)){
                continue;
            }
            if(visited[xx][yy]==1){
                continue;
            }
            if(grid[xx][yy]=='1'){
                q.push({xx,yy});
                visited[xx][yy]=1;
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    vector<vector<int>> visited;
    int n=grid.size();
    int m=grid[0].size();
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<m;j++){
            temp.push_back(0);
        }
        visited.push_back(temp);
    }
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='0'){continue;}
            if(visited[i][j]==1){
                continue;
            }
            visited[i][j]=1;
            bfs(grid,i,j,visited,n,m);
            count++;
        }
    }
    return count;

}