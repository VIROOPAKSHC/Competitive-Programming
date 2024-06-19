// Author - Chekuri Viroopaksh
// Day 8 - 19th June, 2024
// Striver's A2Z DSA Sheet
#include<bits/stdc++.h>
using namespace std;

vector<int> findLeaders(vector<int> vect){
    int n=vect.size();
    vector<int> ans;
    int curr_max=vect[n-1];
    ans.push_back(curr_max);
    for(int i=n-2;i>=0;i--){
        if(curr_max<vect[i]){
            curr_max = vect[i];
            ans.push_back(curr_max);
        }
    }
    return ans;
}

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        
        set<int> s;
        for(int i:nums){
            s.insert({i});
        }
        int prev=-1;
        int c=0,max_count=0;
        int prev_op=-1;
        int first_iter=1;
        for(int i:s){
            if(prev==-1 && first_iter==1){
                prev=i;
                c=1;
                prev_op=-1;
                first_iter=0;
                continue;
            }
            if(((i==prev+1) && (prev_op==1 || prev_op==-1))){
                prev=i;
                prev_op=1;
                c++;
            }
            else if((i==prev-1) && (prev_op==0 || prev_op==-1)){
                prev=i;
                prev_op=0;
                c++;
            }
            else{
                prev=i;
                max_count=max(max_count,c);
                prev_op=-1;
                c=1;
            }
            
        }
        max_count=max(max_count,c);
        return max_count;
    }
};

void setZeroes(vector<vector<int>>& matrix) {
        map<int,int> mp;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    if(mp[i]==1){
                        mp[i]=10;
                    }
                    if(mp[j]==-1){
                        mp[j]=10;
                    }
                    if(!mp[i])
                        mp[i]=-1;
                    if(!mp[j])
                        mp[j]=1;
                    
                    if(i==j){
                        mp[i]=10;
                    }
                }
                   
            }
        }
       
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(mp[i]==-1 || mp[i]==10){
                    matrix[i][j]=0;
                    continue;
                }
                if(mp[j]==1 || mp[j]==10){
                    matrix[i][j]=0;
                    continue;
                }
            }
        }
    }

void rotate(vector<vector<int>>& matrix) {
        int edgeLength = matrix.size();

        int top = 0;
        int bottom = edgeLength - 1;

        while (top < bottom) {
            for (int col = 0; col < edgeLength; col++) {
                int temp = matrix[top][col];
                matrix[top][col] = matrix[bottom][col];
                matrix[bottom][col] = temp;
            }
            top++;
            bottom--;
        }

        for (int row = 0; row < edgeLength; row++) {
            for (int col = row + 1; col < edgeLength; col++) {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        }        
    }

int main(){
    vector<int> a1 = findLeaders({4,7,1,0});
    vector<int> a2=findLeaders({10,22,12,3,0,6});
    for(int i:a1) cout<<i<<" ";
    cout<<endl;
    for(int i:a2) cout<<i<<" ";
    cout<<endl;
}
