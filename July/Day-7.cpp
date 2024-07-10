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
    
};

int main(){
    return 0;
}