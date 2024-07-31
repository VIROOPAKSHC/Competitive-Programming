// Author - Chekuri Viroopaksh
// Day 30 - July 31, 2024
// Leetcode Medium Problems

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        map<int,int> mp;
        set<int> s;
        for(int num:nums){
            mp[num]++;
            s.insert(num);
        }
        while(true){
            vector<int> vect;
            bool f=false;
            for(auto a:s){
                if(mp[a]){vect.push_back(a);mp[a]--;}
                
                if(mp[a]!=0){
                    f=true;
                }
            }
            ans.push_back(vect);
            if(f==false){
                break;
            }
        }
        return ans;
    }
    int minOperations(vector<int>& nums, int k) {
        int x = nums[0];
        for(int i=1;i<nums.size();i++){
            x = x ^ nums[i];
        }
        x = x^k;
        int diff = 0;
        while(x){
            diff++;
            x = (x&(x-1));
        }
        return diff;
    }
};

int main(){
    
    return 0;
}