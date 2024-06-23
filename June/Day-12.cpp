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
    string addBinary(string a, string b) {
        string res;
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        while(i>=0 || j>=0){
            int sum=carry;
            if(i>=0) sum+=a[i--]-'0';
            if(j>=0) sum+=b[j--]-'0';
            carry = sum>1 ? 1 : 0;
            res += to_string(sum%2);
        }
        if(carry) res+=to_string(carry);
        reverse(res.begin(),res.end());
        return res;
    }
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[sum]=1;
        for(auto it:nums){
            sum+=it;
            int find = sum - k;
            if(mp.find(find)!=mp.end()){
                ans += mp[find];
            }
            mp[sum]++;
        }
        return ans;
    }
};

int main(){

    return 0;
}