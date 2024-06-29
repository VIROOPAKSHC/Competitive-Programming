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
    string removeTrailingZeros(string num) {
        string ans = "";
        int prev=-1;
        for(int i=0;i<num.size();i++){
            if(num[i]!='0'){
                prev=i;
            }
        }
        
        for(int j=0;j<=prev;j++){
            ans+=num[j];
        }
        return ans;
    }
};

int main(){
    return 0;
}