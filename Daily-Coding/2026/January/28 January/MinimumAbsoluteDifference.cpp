/*
Tag: Sorting, Array
Problem Statement:https://leetcode.com/problems/minimum-absolute-difference/description/
*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    int minabsdiff = arr[1]-arr[0];
    for(int i=1;i<arr.size();i++){
        minabsdiff = min(minabsdiff,abs(arr[i]-arr[i-1]));
    }
    vector<vector<int>> ans;
    for(int i=1;i<arr.size();i++){
        if(arr[i]-arr[i-1] == minabsdiff){
            ans.push_back({arr[i-1],arr[i]});
        }
    }
    return ans;

}