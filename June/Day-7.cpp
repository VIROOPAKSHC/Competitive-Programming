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

int maxSubArray(vector<int>& nums) {
        long long maxi = LONG_MIN;
        long long summ = 0;
        for(int i:nums){
            summ += i;
            maxi = max(maxi,summ);
            summ = max(long (0),long(summ));
        }
        return maxi;
}

vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> neg;
        vector<int> pos;
        for(int i:nums){
            if(i>0) pos.push_back(i);
            else neg.push_back(i);
        }
        int a=0,b=0;
        for(int i=0;i<nums.size();i++){
            if(i%2) nums[i]=neg[b++];
            else nums[i]=pos[a++];
        }
        return nums;
}

int maxProfit(vector<int>& prices) {
        int buy=INT_MAX,sell=0;
        for(int i=0;i<prices.size();i++){
            buy=min(buy,prices[i]);
            sell=max(sell,prices[i]-buy);
        }
       return sell;
    }

void nextPermutation(vector<int>& nums) {
        int pos=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pos=i;
                break;
            }
        }
        
        if(pos==-1){
            reverse(nums,0);
        }
        else{
            int pos2=-1;
            for(int i=nums.size()-1; i>=0; i--){
                if(nums[i]>nums[pos]){
                    pos2=i;
                    break;
                }
            }
            swap(nums,pos,pos2);
            reverse(nums,pos+1);
        }
    }
    void swap(vector<int>& nums,int i,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    void reverse(vector<int>& nums,int start){
        int i=start;
        int j=nums.size()-1;
        while(i<j){
            swap(nums,i,j);
            i++;
            j--;
        }
    }

int main(){

}