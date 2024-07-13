// Author - Chekuri Viroopaksh
// Day 27 - July 13, 2024
// Leetcode Hashing

#include<bits/stdc++.h>
using namespace std;

int findPermutationDifference(string s, string t) {
        map<char,int>mp;
        int sss=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]] = i;
        }
        for(int i=0;i<t.size();i++){
            sss += abs(mp[t[i]]-i);
        }
        return sss;
    }

int main(){
    return 0;
}