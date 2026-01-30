/*
Tag: Medium, Backtracking
Problem Statement: https://leetcode.com/problems/combinations/
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> combine(int n, int k) {
    set<vector<int>> result;
    result.insert({1});
    for(int i=2;i<=n;i++){
        set<vector<int>> temp;
        for(auto vect:result){
            temp.insert(vect);
            if(vect.size()<k){
                vect.push_back(i);
                temp.insert(vect);
            }
            temp.insert({i});
        }
        result = temp;
    }
    vector<vector<int>> total;
    for(auto &v:result){
        if(v.size()==k){
            total.push_back(v);
        }
    }
    return total;
}

/*Faster solution using recursion:*/
void backtrack(vector<int> &comb, int start, int n, int k,vector<vector<int>> &result){
    if(comb.size()==k){
        result.push_back(comb);
        return;
    }
    for(int i=start;i<=n;i++){
        comb.push_back({i});
        backtrack(comb,i+1,n,k,result);
        comb.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> comb={};
    backtrack(comb,1,n,k,result);
    return result;
}