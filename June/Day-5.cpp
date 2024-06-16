#include<bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
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
};

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
