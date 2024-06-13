// Author: Chekuri Viroopaksh
// Day-2 : 13th of June
// Striver's A2Z DSA sheet

#include<bits/stdc++.h>
using namespace std;

bool isPrime(int N){
    for(int i=2;i<(N/2)+1;i++){
        if(N%i==0){
            return false;
        }
    }
    return true;
}

bool isPrime_Stylish(int N){
    for(int i=2;i<int(sqrt(N))+1;i++){
        if(N%i==0){
            return false;
        }
    }
    return true;
}

void recursivePrint(int N){
    if(N==0){
        return;
    }
    cout<<"VIROOPAKSH"<<endl;
    recursivePrint(--N);
}

void Print1toN(int N){
    if(N==0){
        cout<<endl;
        return;
    }
    Print1toN(--N);
    cout<<N+1<<" ";
}

int Sum1toN(int N){
    // 4th Problem
    if(N==1){
        return 1;
    }
    return N+Sum1toN(N-1);
}

void RecursiveReverse(vector<int>& vect){
    // Problem-5
    if(vect.size()==1){
        return;
    }
    int temp = *vect.rbegin();
    vect.pop_back();

    RecursiveReverse(vect);
    vect.insert(vect.begin(),temp);
}

class Solution {
public:
    bool isPalindrome_Imperfect(string s) {
        // Fails extremely large test case - memory limit exceeded.
        if(s.size()<=1){
            return true;
        }
        
        int n = s.size();
        int i=0,j=n-1;
        if(((s[i]<='z') && (s[i]>='a'))||((s[i]>='A') && (s[i]<='Z')) || (s[i]>='0' && s[i]<='9') ){
            if(s[i]<='Z'){
                s[i] = s[i]+32;
            }
        }
        else{
            while(i<n-1){
                i++;
                if(((s[i]<='z') && (s[i]>='a'))||((s[i]>='A') && (s[i]<='Z'))|| (s[i]>='0' && s[i]<='9') ){
                    if(s[i]<='Z'){
                        s[i] = s[i]+32;
                        
                    }
                    break;
                 }
            }
        }
        if(((s[j]<='z') && (s[j]>='a'))||((s[j]>='A') && (s[j]<='Z'))|| (s[j]>='0' && s[j]<='9') ){
            if(s[j]<='Z'){
                s[j] = s[j]+32;
            }
        }
        else{
             while(j>0){
                j--;
                if(((s[j]<='z') && (s[j]>='a'))||((s[j]>='A') && (s[j]<='Z'))|| (s[j]>='0' && s[j]<='9') ){
                    if(s[j]<='Z'){
                        s[j] = s[j]+32;
                    }
                    break;
                 }
            }
        }
        
        if((i>j) || ((i==n) || (j==n))){
            return true;
        }
        
        return (s[i]==s[j]) && isPalindrome_Imperfect(s.substr(i+1,j-i-1));
    }
    bool isPalindrome_Perfect(string s) {
        vector<char> vect;
        for(int i=0;i<s.size();i++){
            if((s[i]>=97 && s[i]<=122) || (s[i]>=65 && s[i]<=90) || (s[i]>='0' && s[i]<='9')){
                vect.push_back(s[i]);
            }
        }
        for(int i=0;i<vect.size();i++){
            char a=vect[i];
            char b=vect[vect.size()-1-i];
            if(a<97)
                a+=32;
            if(b<97)
                b+=32;
            if(a!=b){
                return false;
            }
        }
        return true;
    }
};

map<int,int> CountOccurences(vector<int> vect){
    map<int,int> mp;
    for(int i=0;i<vect.size();i++){
        mp[vect[i]]++;
    }
    return mp;
}

int main(){

    
    map<int,int> mp = CountOccurences({1,1,1,3,4,3,2,-3,5,3,4});
    for(auto a:mp){
        cout<<a.first<<" "<<a.second<<endl;
    }
    return 0;
}