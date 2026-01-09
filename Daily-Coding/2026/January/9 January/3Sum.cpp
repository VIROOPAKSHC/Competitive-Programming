/*
Tag: Array, 2 Pointers

Problem Statement:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> answer;
    sort(nums.begin(),nums.end());
    map<int,int> mp;
    for(int i=0;i<nums.size();i++) mp[nums[i]]=i;
    for(int k=0;k<nums.size();k++){    
        if(k!=0 && nums[k]==nums[k-1]){continue;}
        int i=k+1;
        int j=nums.size()-1;
        int curr_sum;
        while(i<j){
            curr_sum=nums[i]+nums[j]+nums[k];
            if(curr_sum==0){
                
                vector<int> sett = {nums[i],nums[j],nums[k]};
                sort(sett.begin(),sett.end());
                answer.insert(sett);
                i++;
                j--;
                while (i < j && (i>=0 && nums[i] == nums[i - 1])) i++;
                while (i < j && (j<nums.size() && nums[j] == nums[j + 1])) j--;
            }
            else if(curr_sum>0){
                j--;
            }
            else{
                i++;
            }
            
        }
    }
    vector<vector<int>> ans;
    for(auto &a:answer){
        ans.push_back(a);
    }
    return ans;
}

/*
My Solution:

- Sort the array to facilitate the two-pointer technique and handle duplicates easily.
- Use a set to store unique triplets.
- Iterate through the array, fixing one element and using two pointers to find pairs that sum to
    the negative of the fixed element.
- Skip duplicate elements to avoid repeating triplets.
- Return the unique triplets as a vector of vectors.


*/