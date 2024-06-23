// Author - Chekuri Viroopaksh
// Day 12 - 23rd June, 2024
// Striver's A2Z DSA sheet

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int M=1e9+7;
    long long power(long long b, long long e, long long ans){
        if(e==0)
            return ans;
        if(e&1)
            return power(b,e-1,(ans*b)%M);
        else
            return power((b*b)%M, e/2, ans);
    }    
    int countGoodNumbers(long long n) {
        long long temp = power(20,n/2,1);
        return (n&1) ? (temp*5)%M :temp;
    }
    double myPow(double x, int n) {
        double num=1;
        long long nn=n;
        if(nn<0)
            nn = -nn;
        while(nn>0){
            if(nn%2){
                num=num*x;
                nn--;
            }
            else{
                x=x*x;
                nn/=2;
            }
        }
        if(n<0){
            num = 1.0/num;
        }
        return num;
    }
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int i=n-1;
        while(i>=0){
            if(digits[i]+1 == 10){
                digits[i]=0;
                i--;
            }
            else{
                digits[i]+=1;
                break;
            }
        }
        if(i==-1){
            vector<int> ans;
            ans.push_back(1);
            for(int i=0;i<n;i++){
                ans.push_back(0);
            }
            return ans;
        }
        return digits;
    }
};

int main(){

    return 0;
}