// Author - Chekuri Viroopaksh
// Day 13 - 24 June, 2024
// Striver's A2Z DSA sheet
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int el1 = INT_MIN,el2 = INT_MIN,cnt1=0,cnt2=0;
        for(int i:nums){
            if(cnt1==0 && el2!=i){
                cnt1=1;
                el1=i;
            }
            else if(cnt2==0 && el1!=i){
                cnt2=1;
                el2=i;
            }
            else if(el1==i){
                cnt1++;
            }
            else if(el2==i){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1=0;
        cnt2=0;
        for(int i:nums){
            if(i==el1)
                cnt1++;
            else if(i==el2){
                cnt2++;
            }
        }
        if(cnt1 >= int(n/3)+1)
            ans.push_back(el1);
        if(cnt2 >= int(n/3)+1)
            ans.push_back(el2);
        return ans;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size(); //size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    //calculating the quadruplets:
    for (int i = 0; i < n; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }

    return ans;
    }
    int findFirstPosition(vector<int>&nums , int target){
        int index=-1;

        int start = 0;
        int end   = nums.size() - 1;
        
        
        while(start<=end){
            int mid = start + (end - start) / 2;
            
            if(nums[mid] == target) {
                
                index = mid;
                end   = mid - 1; 

            }else if(nums[mid] > target) {
                end = mid - 1;

            }else {
                start = mid + 1;
            }
        }

        return index;
    }
    

    int findLastPosition(vector<int>&nums , int target){
        int index=-1;

        int start = 0;
        int end   = nums.size() - 1;
        
        
        while(start<=end){
            int mid = start + (end - start) / 2;
            
            if(nums[mid] == target) {
                index = mid;
                start = mid + 1;

            }else if(nums[mid] > target) {
                end = mid - 1;

            }else {
                start = mid + 1;
            }
        }
        return index;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int firstPosition = -1;
        int lastPosition  = -1;


        firstPosition = findFirstPosition (nums,target);
        lastPosition  = findLastPosition  (nums,target);


        return {firstPosition , lastPosition};
    }
};

int main(){
    return 0;
}