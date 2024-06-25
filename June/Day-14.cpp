// Author - Chekuri Viroopaksh
// Day 14 - June 25, 2024
// Striver's A2Z DSA sheet
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int FindPivot(vector<int> arr,int start,int end){
    if(start>end){
        return -1;
    }
    if(start==end){
        return start;
    }
    int mid=(start+end)/2;
    if(mid<end && arr[mid]>arr[mid+1]){
        return mid;
    }
    if(mid > start && arr[mid]<arr[mid-1]){
        return mid-1;
    }
    if(arr[start]>=arr[mid]){
        return FindPivot(arr,start,mid-1);
    }
    return FindPivot(arr,mid+1,end);
}
int binarySearch(vector<int> arr, int low,
                 int high, int key)
{
    if (high < low)
        return -1;
 
    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (key == arr[mid])
        return mid;
 
    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
 
    // else
    return binarySearch(arr, low, (mid - 1), key);
}
int BinSearchInSortedRotatedArray(vector<int> arr,int key){
    int n=arr.size();
    int pivot=FindPivot(arr,0,n-1);
    if(pivot==-1){
        return binarySearch(arr,0,n-1,key);
    }
    if (arr[pivot] == key)
        return pivot;
 
    if (arr[0] <= key)
        return binarySearch(arr,0, pivot - 1, key);
 
    return binarySearch(arr,pivot + 1, n - 1, key);
}

    int search(vector<int>& nums, int target) {
        
        return BinSearchInSortedRotatedArray(nums,target);
    }
};

vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        map<int,int> mp;
        for(int i:nums1){
            mp[i]=1;
        }
        map<int,int> mp2;
        for(int i:nums2){
            mp2[i]=1;
        }
        map<int,int> mp3;
        for(int i:nums3){
            mp3[i]=1;
        }
        map<int,int> finl;
        for(auto a:mp){
            finl[a.first]++;
        }
        for(auto a:mp2){
            finl[a.first]++;
        }
        
        for(auto a:mp3){
            finl[a.first]++;
        }
        vector<int> v;
        for(auto a:finl){
            if(a.second >= 2){
                v.push_back(a.first);
            }
        }
    return v;
    }

int numberOfPoints(vector<vector<int>>& nums) {
        map<int,int> mp;
        for(auto a:nums){
                for(int i=a[0];i<=a[1];i++){
                    mp[i]++;
                }
            
        }
        return mp.size();
    }

int main(){

    return 0;
}