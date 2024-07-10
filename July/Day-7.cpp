// Author - Chekuri Viroopaksh
// Day 24 - July 10, 2024
// LeetCode

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int c=0;
        for(auto a:logs){
            if(a[0]=='.'){
                if(a[1]=='.'){
                    if(c!=0){c--;}
                }
            }
            else{
                c++;
            }
        }
        return c;
    }
};

int main(){
    return 0;
}