// Author - Chekuri Viroopaksh
// Day 24 - July 10, 2024
// LeetCode

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int c=0;
        for(auto a:logs){
            if(a[0]=='.'){
                if(a[1]=='.'){
                    if(c!=0){c--;}
                }
            }
            else{
                c++;
            }
        }
        return c;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int c=0;
        for(int a:queries){
            int s=0;
            c=0;
            for(int i:nums){
                s+=i;
                if(s>a){
                    break;
                }
                c++;
            }
            ans.push_back(c);
        }
        return ans;
    }
    int unequalTriplets(vector<int>& nums) {
        map<int,int> mp;
        vector<int> unique;
        for(int a:nums){
            if(mp[a]==0){
                unique.push_back(a);
            }
            mp[a]++;
        }
        if(mp.size()<3) return 0;
        int ans=0;
        int n=unique.size();
        int val1,val2,val3;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    val1 = unique[i];
                    val2 = unique[j];
                    val3 = unique[k];
                    ans += (mp[val1]*mp[val2]*mp[val3]);
                }
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}