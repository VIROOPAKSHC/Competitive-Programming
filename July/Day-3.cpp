// Author - Chekuri Viroopaksh
// Day 20 - 3rd, July, 2024
// Sorting Leetcode problems

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int c=0;
        sort(nums.begin(),nums.end());
        while(true){     
            if(nums[nums.size()-1]==0){
                break;
            }
            int iter_Val = nums[0];       
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                    continue;
                }
                else if(nums[i]!=0 && iter_Val == nums[0]){
                    iter_Val = nums[i];
                    nums[i]=0;
                }
                else{
                    nums[i]-=iter_Val;
                }
            }
            c++;
            

        }
        return c;
    }
    int minimumOperations_Stylish(vector<int>& nums) {
        unordered_set<int> pos;
        for(int a:nums){
            if(a){
                pos.insert(a);
            }
        }
        return pos.size();
    }
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        return target==arr;
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int,int> mp;
        for(int i=0;i<score.size();i++){
            mp[score[i]] = i;
        }
        sort(score.begin(),score.end());
        vector<string> ans(score.size());
        int n=score.size();
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                ans[mp[score[i]]] = "Gold Medal";
            }
            else if(i==n-2){
                ans[mp[score[i]]] = "Silver Medal";
            }
            else if(i==n-3){
                ans[mp[score[i]]] = "Bronze Medal";
            }
            else{
                string val = "";
                int rem = n-i;
                while(rem){
                    val += ('0'+(rem%10));
                    rem = rem/10;
                }
                string act = "";
                for(int j=val.size()-1;j>=0;j--){
                    act+=val[j];
                }
                ans[mp[score[i]]] = act;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}