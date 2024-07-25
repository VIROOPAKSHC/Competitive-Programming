// Author - Chekuri Viroopaksh
// Day 25 - 11 July, 2024
// Leetcode Sorting Problems and daily challenge

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(c==')'){
                string rev = "";
                while(!st.empty() && st.top() != '('){
                    rev += st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
                for(int j=0;j<rev.size();j++){
                    st.push(rev[j]);
                }
            }
            else{
                st.push(c);
            }
        }
        string result = "";
        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans;
        for(int i=n;i>=1;i--){
            for(int j=0;j<n-1;j++){
                if(arr[j] == i){
                    ans.push_back(j+1);
                    reverse(arr.begin(),arr.begin()+j+1);
                    ans.push_back(i);
                    reverse(arr.begin(),arr.begin()+i);
                }
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}