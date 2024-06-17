// Author - Chekuri Viroopaksh
// Day 6 - 17th June, 2024
// Striver's A2Z DSA sheet
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int val= target-nums[i];
            if(mp.find(val)!=mp.end()){
               ans.push_back(mp[target-nums[i]]);
               ans.push_back(i);
                // Answer found and as only a single solution is present, returning here is fine.
                return ans;
                
            }else{
                 mp[nums[i]]=i;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}