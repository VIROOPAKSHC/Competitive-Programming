// Author - Chekuri Viroopaksh
// Day 19 - 2nd, July 2024
// LeetCode Sorting problems

#include<bits/stdc++.h>
using namespace std;
bool compare(int a, int b){
        return a>=b;
}

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int> sorrt = nums;
        sort(sorrt.begin(),sorrt.end());
        int n=nums.size();
        if(sorrt[n-1]>=2*sorrt[n-2]){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==sorrt[n-1]){
                    return i;
                }
            }
        }
        return -1;
    }
    bool isGood(vector<int>& nums) {
        if(nums.size()==1){return false;}
        
        sort(nums.begin(),nums.end());
        int n = nums[nums.size()-1];
        if(n+1 != nums.size()){
            return false;
        }
        if(nums[0]!=1){
            return false;
        }
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]==nums[i-1]){
                return false;
            }
        }
        if(nums[nums.size()-1]!=nums[nums.size()-2]){
            return false;
        }
        return true;
    }
    int maximumProduct(vector<int>& nums) {
        if(nums.size()==3){
            return nums[0]*nums[1]*nums[2];
        }
        int prod = 1;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int m1 = nums[n-1]*nums[n-2]*nums[n-3];
        int m2 = nums[0]*nums[1];
        return max(m1,m2*nums[n-1]);
    }
    bool istriangle(int a,int b,int c){
        return (a+b>c) && (b+c>a) && (c+a>b);
    }
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a,b,c;
        a = nums[0];
        b = nums[1];
        c = nums[2];
        if(!istriangle(a,b,c)){
            return "none";
        }
        if(c==a){
            return "equilateral";
        }
        else if((c==b)||(b==a)){
            return "isosceles";
        }
        else{return "scalene";}
    }
    int missingInteger(vector<int>& nums) {
        int s=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                s+=nums[i];
            }
            else{
                break;
            }
       }
       int ind=-1;
       sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size();i++){
        if(nums[i]<s){
            continue;
        }
        
        else if(nums[i]>s){
            return s;
        }
        else{
            ind = i;
            break;
        }
       }
       while(ind<nums.size() && nums[ind]==s){
        ind++;
        while(ind<nums.size() && nums[ind]==nums[ind-1]){ind++;}
        s++;
       }
       return s;
    }
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        auto copyy = score;
        map<int,int> mp;
        vector<int> vals;
        for(int i=0;i<score.size();i++){
            mp[score[i][k]] = i;
            vals.push_back(score[i][k]);
        }
        sort(vals.begin(),vals.end(),compare);
        vector<vector<int>> ans;
        for(int i:vals){
            ans.push_back(score[mp[i]]);
        }
        return ans;
    }
};

int main(){
    return 0;
}