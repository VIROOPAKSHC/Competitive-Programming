// Author - Chekuri Viroopaksh
// Day 9 - 20th June, 2024
// Striver's A2Z DSA sheet
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        vector<string> s;
        int temp = 0;
        string p = "";
        if (S[0] == '(') {
            p += S[0];
            temp = 1;
        }
        for (int i = 1; i < S.length(); i++) {
            if (S[i] == ')') {
                temp--;
            }
            if (S[i] == '(') {
                temp++;
            }
            if (temp == 0) {
                string k = "";
                for (int i = 1; i < p.length(); i++) {
                    k += p[i];
                }
                s.push_back(k);
                p = "";
                // cout<<k<<endl;
            } else {
                p += S[i];
            }
        }
        p = "";
        for (int i = 0; i < s.size(); i++) {
            p += s[i];
        }
        return p;
    }
};


string reverseWords(string s) {
        vector<string> words;
        string ans="";
        for(auto c:s){
            if(c==' '){
                if(ans.size()){
                    words.push_back(ans);
                    ans="";
                }
            }
            else{
                ans+=c;
            }
        }
        if(ans.size()){
            words.push_back(ans);
        }
        ans="";
        for(int i=words.size()-1;i>=0;i--){
            ans+=words[i];
            if(i!=0){
                ans+=' ';
            }
        }
        return ans;
    }

int main(){
    return 0;
}