// Author - Chekuri Viroopaksh
// Day 10 - 21st June, 2024
// Striver's A2Z DSA Sheet

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
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
    int maxDepth(string s) {
        int c=0,max_c=0;
        for(auto a:s){
            if(a=='('){
                c++;
            }
            else if(a==')'){
                max_c=max(c,max_c);
                c--;
            }
        }
        return max_c;
    }
};

int main(){

    return 0;
}