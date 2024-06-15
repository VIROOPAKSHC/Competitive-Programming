// Author - Chekuri Viroopaksh
// Day 4 - 15th of June, 2024.
// Striver's A2Z DSA sheet

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s=nums.size();
        for(int i=0;i<s;i++){
            if(nums[i]!=0){
                continue;
            }
            int j=i+1;
            while(j<s && nums[j]==0 ){
                j++;
            }
            if(j>=s){
                return;
            }
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
    }
    int missingNumber(vector<int>& nums) {
        if(nums.size()==1){
            if(nums[0]==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        int n = 0;
        int sum=0;
        int found=0;
        for(int i:nums){
            if(i==0){
                found=1;
            }
            sum+=i;
            if(n < i){
                n = i;
            }
        }
        if(!found){
            return 0;
        }
        int val = ((n*(n+1))/2)-sum;
        if(val){
            return val;
        }
        else{
            return n+1;
        }
    }
};

int FindElement(vector<int> vect,int k){
    int n = vect.size();
    int hi=n-1;
    int lo=0;
    int mid=(hi+lo)/2;
    if((k>vect[hi])||(k<vect[lo])){
        return -1;
    }
    while((mid>=0) && (mid<=n-1)){
        if(vect[mid]==k){
            return 1;
        }
        else if(vect[mid]>k){
            hi = mid-1;
            mid = (lo+hi)/2;
        }
        else if(vect[mid]<k){
            lo = mid+1;
            mid = (lo+hi)/2;
        }
        if(lo>mid){
            return -1;
        }
    }
    return -1;
}

vector<int> findUnion(int arr1[],int arr2[],int n,int m){
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr1[i]]++;
    }
    for(int i=0;i<m;i++){
        mp[arr2[i]]++;
    }
    vector<int> ans;
    for(auto a:mp){
        ans.push_back(a.first);
    }
    return ans;
    
}

int main(){
    cout<<FindElement({1,2,3,5,6,7},4)<<endl;
    return 0;
}