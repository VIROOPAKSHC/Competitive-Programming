// Author - Chekuri Viroopaksh
// Day 23 - July 9, 2024
// Sorting Leetcode problems

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res(people.size(), vector<int>());
        for(int i = 0; i < people.size(); i++){
            int cnt, j;
            for(cnt = 0, j = 0; j < res.size(); j++){ //empty count start from 0
                if(res[j].empty()){
                    if(cnt==people[i][1]) break;
                    cnt++;
                }
            }
            res[j]=people[i];
        }
        return res;
    }
    static bool cmp(vector<int>& p1, vector<int>& p2){
        if(p1[0]!=p2[0]) return p1[0]<p2[0];
        else return p1[1]>p2[1];
    }
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp;
        set<int> s;
        for(auto a:matches){
            mp[a[0]] = mp[a[0]];
            mp[a[1]] = mp[a[1]]+1;
            s.insert(a[0]);
            s.insert(a[1]);
        }
        vector<int> first;
        vector<int> second;
        for(int a:s){
            if(mp[a] == 0){
                first.push_back(a);
            }
            else if(mp[a]==1){
                second.push_back(a);
            }
        }
        return {first,second};
    }
};

int main(){
    return 0;
}