// Author - Chekuri Viroopaksh
// Day 23 - July 9, 2024
// Sorting Leetcode problems

#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<char,int>& a,pair<char,int>& b){
    if(a.second != b.second){
        return a.second>b.second;
    }
    return a.first>b.first;
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res(people.size(), vector<int>());
        for(int i = 0; i < people.size(); i++){
            int cnt, j;
            for(cnt = 0, j = 0; j < res.size(); j++){ //empty count start from 0
                if(res[j].empty()){
                    if(cnt==people[i][1]) break;
                    cnt++;
                }
            }
            res[j]=people[i];
        }
        return res;
    }
    static bool cmp(vector<int>& p1, vector<int>& p2){
        if(p1[0]!=p2[0]) return p1[0]<p2[0];
        else return p1[1]>p2[1];
    }
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp;
        set<int> s;
        for(auto a:matches){
            mp[a[0]] = mp[a[0]];
            mp[a[1]] = mp[a[1]]+1;
            s.insert(a[0]);
            s.insert(a[1]);
        }
        vector<int> first;
        vector<int> second;
        for(int a:s){
            if(mp[a] == 0){
                first.push_back(a);
            }
            else if(mp[a]==1){
                second.push_back(a);
            }
        }
        return {first,second};
    }
    int reductionOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto ele:nums)mp[ele]++;
        sort(nums.begin() , nums.end());
        int ind = 0, min = nums[0],n = nums.size();
        while(ind<n and nums[ind] == min) ind++;
        if(ind>=n) return 0;
        int sum = 0;
        int prev = -1e9;
        for(int i=  n-1; i>=ind; i--){
            if(nums[i]==prev) continue;
            sum  +=  mp[nums[i]] + (n-1-i);
            prev = nums[i];
        }
        return sum;
    }
    string frequencySort(string s) {
        auto cmp=[](const pair<char,int>& a,const pair<char,int>& b){
            return a.second<b.second;
        };
        unordered_map<char,int> mp;
        for(auto a:s){
            mp[a]++;
        }
        priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(cmp)> pq(cmp);
        for(const auto& entry:mp){
            pq.push(make_pair(entry.first,entry.second));
        }
        string result = "";
        while(!pq.empty()){
            pair<char,int> p = pq.top();
            pq.pop();
            result.append(p.second,p.first);
        }
        return result;

       
    }
    string frequencySort_Mine(string s) {
        map<char,int> mp;
        for(char a:s){
            mp[a]++;
        }
        vector<pair<char,int>> m;
        for(auto a:mp){
            m.push_back(a);
        }
        sort(m.begin(),m.end(),cmp);
        string ans="";
        for(auto a:m){
            int i = a.second;
            while(i--){
                ans+=a.first;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}