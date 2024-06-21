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
    int romanToInt(string s) {
        int c=0,n=s.size();
        map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int i=0;
        while(i<n){
            if(i!=n-1){
                if(s[i]=='I'){
                    if(s[i+1]=='V'){
                        c+=4;
                        i+=2;
                        continue;
                    }
                    else if(s[i+1]=='X'){
                        c+=9;
                        i+=2;
                        continue;
                    }
                    else{
                        c+=1;
                        i++;
                        continue;
                    }
                }
                else if(s[i]=='X'){
                    if(s[i+1]=='L'){
                        c+=40;
                        i+=2;
                        continue;
                    }
                    else if(s[i+1]=='C'){
                        c+=90;
                        i+=2;
                        continue;
                    }
                    else{
                        c+=10;
                        i++;
                        continue;
                    }
                }
                else if(s[i]=='C'){
                    if(s[i+1]=='D'){
                        c+=400;
                        i+=2;
                        continue;
                    }
                    else if(s[i+1]=='M'){
                        c+=900;
                        i+=2;
                        continue;
                    }
                    else{
                        c+=100;
                        i++;
                        continue;
                    }
                }
                else{
                    c+=mp[s[i]];
                    i++;
                    continue;
                }
            }
            else{
                c+=mp[s[i]];
                i++;
                continue;
            }
        }
        return c;
    }
    int myAtoi(string s) 
    {
        int i=0;
        int sign=1;
        long ans=0;
        while(i<s.length() && s[i]==' ')
            i++;
        if(s[i]=='-')
        {
            sign=-1;
            i++;
        }
        else if(s[i]=='+')
            i++;
        while(i<s.length())
        {
            if(s[i]>='0' && s[i]<='9')
            {
                ans=ans*10+(s[i]-'0');
                if(ans>INT_MAX && sign==-1)
                    return INT_MIN;
                else if(ans>INT_MAX && sign==1)
                    return INT_MAX;
                i++;
            }
            else
                return ans*sign;
        }
        return (ans*sign);
    }
};

int main(){

    return 0;
}