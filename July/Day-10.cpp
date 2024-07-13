// Author - Chekuri Viroopaksh
// Day 27 - July 13, 2024
// Leetcode Hashing

#include<bits/stdc++.h>
using namespace std;

class OrderedStream {
public:
    string mp[1000];
    int curr = 0;
    OrderedStream(int n) {
        
    }
    
    vector<string> insert(int idKey, string value) {
        mp[idKey-1] = value;
        vector<string> ans;
        while(mp[curr]!=""){
            ans.push_back(mp[curr]);
            curr++;
        }
        return ans;
    }
};

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

int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int c=0;
        for(int a:nums1){
            for(int b:nums2){
                if(a%(b*k) == 0){
                    c++;
                }
            }
        }
        return c;
    }

int main(){
    return 0;
}