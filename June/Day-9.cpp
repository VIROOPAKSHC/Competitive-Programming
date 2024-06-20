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

string largestOddNumber(string num) {
        int last_odd_ind=-1;
        for(int i=0;i<num.size();i++){
            int n = num[i]-'0';
            if(n%2){
                last_odd_ind = i;
            }
        }
        if(last_odd_ind==-1){
            return "";
        }
        else{
            string ans="";
            for(int i=0;i<last_odd_ind+1;i++){
                ans+=num[i];
            }
            return ans;
        }
    }

string longestCommonPrefix(vector<string>& strs) {
        string common=strs[0];
        for(int i=1;i<strs.size();i++){
            string p="";
            if(common.size()==0){
                break;
            }
            for(int j=0;j<common.size() && j<strs[i].size();j++){
                if(common[j]==strs[i][j]){
                    p+=common[j];
                }
                else{
                    break;
                }
            }
            common=p;
        }
        return common;
}

int main(){
    return 0;
}