// Author - Chekuri Viroopaksh
// Day 5 - 16th of June, 2024
// Striver's A2Z DSA sheet

#include<bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        cout<<left<<" "<<right<<endl;
        cout<<sum<<endl;
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int lo = 0;
        int hi = nums.size()-1;
        int mid = (lo+hi)/2;
        
        while(lo<=hi){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                hi = mid-1;
                mid = (lo+hi)/2;
            }
            else{
                lo = mid+1;
                mid = (lo+hi)/2;
            }
            if((lo>nums.size()-1)||(hi>nums.size()-1)){
                break;
            }
        }
        return -1;
    }
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        long long int lo=0;
        long long int hi=n-1;
        long long int mid=(lo+hi)/2;
        while(lo<=hi){
            if(lo==hi){
                if(lo==0){
                    if(v[lo]>x){
                        return -1;
                    }
                    else{
                        return lo;
                    }
                }
                else if(hi==n-1){
                    if(v[hi]<=x){
                        return hi;
                    }
                }
            }
            if(v[mid]==x){
                return mid;
            }
            else if(v[mid]>x){
                
                hi=mid-1;
                mid=(lo+hi)/2;
            }
            else{
                if(v[mid+1]>x){
                    return mid;
                }
                lo=mid+1;
                mid=(lo+hi)/2;
            }
        }
        return -1;
    }
    int searchInsert(vector<int>& nums, int target) {
        int lo=0;
        int hi=(nums.size()-1);
        int mid=(lo+hi)/2;
        while(lo<=hi){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                if(mid>0 && nums[mid-1]<target){
                    return mid;
                }
                hi=mid-1;
                mid=(lo+hi)/2;
            }
            else{
                if(mid<nums.size()-1 && (nums[mid+1]>target)){
                    return mid+1;
                }
                lo=mid+1;
                mid=(lo+hi)/2;
            }
        }
        return hi+1;
    }
};

int main()
{
    vector<int> a = {2, 3, 5, 1, 9, -3, 4, 8};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
