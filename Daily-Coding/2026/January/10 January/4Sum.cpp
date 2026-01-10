/*
Tag: 2 Pointers, Array

Problem Statement:
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if(nums.size()<=3){
        return {};
    }
    set<vector<int>> ans_set;
    map<int,int> mp;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            int k=j+1;
            int l=nums.size()-1;
            while(k<l){
                long long curr_sum=0;
                curr_sum+=nums[i];
                curr_sum+=nums[j];
                curr_sum+=nums[k];
                curr_sum+=nums[l];
                if(curr_sum==target){
                    vector<int> ans={nums[i],nums[j],nums[k],nums[l]};
                    sort(ans.begin(),ans.end());
                    ans_set.insert(ans);
                    k++;
                    l--;
                }
                else if(curr_sum<target){
                    k++;
                }
                else{
                    l--;
                }
            }
        }
    }

    vector<vector<int>> answer;
    for(auto &a:ans_set)
        answer.push_back(a);
    
    return answer;
}

/*
My Solution:

- Straight forward 2 nested loops to fix first two elements of quadruplet.
- Then use 2 pointers approach to find other two elements such that their sum along with first two elements is equal to target.

- Use set to avoid duplicates.


*/