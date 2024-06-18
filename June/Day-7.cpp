// Author - Chekuri Viroopaksh
// Day 7 - 18th of June, 2024
// Striver's A2Z DSA sheet

#include<bits/stdc++.h>
using namespace std;

int getlongestsubarray(vector<int> &a, int k){
    int n=a.size();
    map<int,int> prefixsum;
    int sum=0;
    int maxLen=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum==k){
            maxLen = max(maxLen, i+1);
        }
        int rem=sum-k;
        if(prefixsum.find(rem)!=prefixsum.end()){
            int len = i-prefixsum[rem];
            maxLen = max(maxLen, len);
        }
        if(prefixsum.find(sum) == prefixsum.end()){
            prefixsum[sum]=i;
        }
    }
    return maxLen;
}

int main(){

}