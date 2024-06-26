// Author - Chekuri Viroopaksh
// Day 17 - 30, June, 2024
// Leetcode String Problems

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int StringToNum(string s){
        int n=0;
        int i=0;
        while(i<s.size()){
            n = n*10 + int(s[i]-'0');
            i++;
        }
        return n;
    }
    bool areNumbersAscending(string s) {
        vector<string> numbers;
        string num="";
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9'){
                num+=s[i];
            }
            else{
                if(num.size()){numbers.push_back(num);}
                
                num = "";
            }
        }
        if(num.size()){numbers.push_back(num);}
        for(int i=0;i<numbers.size()-1;i++){
            int num1,num2;
            num1 = StringToNum(numbers[i]);
            num2 = StringToNum(numbers[i+1]);
            if(num1>=num2){
                return false;
            }
        }
        return true;
    }
    int minLength(string s) {
        int i=0;
        string old = s;
        string neww = "";
        int k = s.size();
        while(k--){
            int ops = 0;
            int i=0;
            
            while(i<old.size()-1){
                if(old[i]=='A' && old[i+1]=='B'){
                    i+=2;
                    ops++;

                }

                else if(old[i]=='C' && old[i+1]=='D'){
                    i+=2;
                    ops++;
                }
                else{
                    neww += old[i];
                    i+=1;
                }
                
            }
            if(i==old.size()-1){
                neww += old[i];
            }
            if(ops==0 || neww.size()==0){
                return neww.size();
            }
            old = neww;
            neww = "";
        }
        return neww.size();
    }
    int minLength_Stylish(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(st.top()=='A' && s[i]=='B'){
                    st.pop();
                }
                else if(st.top()=='C' && s[i]=='D'){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        
        }
        return st.size();
    }
    string largestGoodInteger(string num) {
        string max_curr = "";
        int max_int = -1;
        for(int i=0;i<num.size()-2;i++){
            int k = i;
            if(i+2 > num.size()-1){
                break;
            }
            if(num[k]==num[k+1] && num[k]==num[k+2]){
                
                string val="";
                val+=num[k];
                val+=num[k+1];
                val+=+num[k+2];
                
                if(max_int < StringToNum(val)){
                    max_curr = val;
                    max_int = StringToNum(val);
                }
            }
        }
        return max_curr;
    }
};
int main(){
    return 0;
}