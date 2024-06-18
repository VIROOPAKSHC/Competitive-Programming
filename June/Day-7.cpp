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

class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[0]){
                nums[i]=0;
                mp[0]--;
            }
            else if(mp[1]){
                nums[i]=1;
                mp[1]--;
            }
            else{
                nums[i]=2;
                mp[2]--;
            }
        }
    }
};
int majorityElement(vector<int>& nums) {
        map<long long int, long long int> mp;
        long long int max_len=0,max_ele=0;
        for(auto i:nums){
            mp[i]++;
            if(max_len < mp[i]){
                max_len = mp[i];
                max_ele = i;
            }
        }
        return max_ele;
    }

int majorityElement_Stylish(vector<int>& nums) {
        int c=0,result=0;
        for(int i:nums){
            if(c==0)
                result = i;
            if(result != i)
                c--;
            else
                c++;
        }
        return result;
    }

int main(){

}