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
};
int main(){
    return 0;
}