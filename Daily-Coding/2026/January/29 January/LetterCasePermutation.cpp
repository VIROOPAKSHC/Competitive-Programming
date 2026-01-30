/*
Tag: Backtracking, Strings, Medium

Problem Statement:https://leetcode.com/problems/letter-case-permutation/description/
*/
#include<bits/stdc++.h>
using namespace std;
vector<string> letterCasePermutation(string s) {
    vector<string> output;
    output.push_back("");
    for(char &a:s){
        vector<string> temp;
        if(a>='a' && a<='z'){
            for(string &o:output){
                temp.push_back(o+char(a-32));
                temp.push_back(o+a);
            }
        }
        else if(a>='A'&&a<='Z'){
            for(string &o:output){
                temp.push_back(o+a);
                temp.push_back(o+char(a+32));
            }
        }
        else{
            for(string &o:output){
                temp.push_back(o+a);
            }
        }
        output = temp;
    }
    return output;
}