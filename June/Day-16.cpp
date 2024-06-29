// Author - Chekuri Viroopaksh
// Day 16 - June 29, 2024
// LeetCode random problems
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        map<char,int> mp;
        int n = s.size();
        for(int i=0;i<n/2;i++){
            mp[s[i]]++;
        }
        for(int i=n/2;i<n;i++){
            mp[s[i]]--;
        }
        string vowels = "aeiouAEIOU";
        int summ=0;
        for(int i=0;i<vowels.size();i++){
            summ+=mp[vowels[i]];
        }
        return summ==0;
    }
};

int main(){
    return 0;
}