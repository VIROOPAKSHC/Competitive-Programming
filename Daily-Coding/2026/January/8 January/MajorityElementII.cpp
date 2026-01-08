/*
Tag: Sorting, Array, Counting

Problem Statement:

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 10^4
-10^9 <= nums[i] <= 10^9
 

Follow up: Could you solve the problem in linear time and in O(1) space?
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    if(nums.size()==1){
        return nums;
    }
    if(nums.size()==2){
        unordered_set<int> ans;
        for(auto &i:nums)ans.insert(i);
        vector<int> answer;
        for(auto &i:ans) answer.push_back(i);
        return answer;
    }
    sort(nums.begin(),nums.end());
    unordered_set<int> ans;
    int i=0,n=nums.size();
    while(i<n){
        int first=i;
        int added=0;
        i+=1;
        while(i<n && nums[i]==nums[i-1]){
            if((i-first)>=floor(n/3) && added==0){
                ans.insert(nums[i]);
                added=1;
            }
            i++;
        }

        if(first==i){
            i++;
        }
    }
    vector<int> answer;
    for(auto &i:ans) answer.push_back(i);
    return answer;
}

/*
My Solution:

- Handle edge cases for arrays of size 1 and 2.
- Sort the input array to group identical elements together.
- Initialize an unordered set to store the majority elements.
- Iterate through the sorted array, counting occurrences of each element.
- If an element's count exceeds ⌊ n/3 ⌋, add it to the set.
- Convert the set to a vector and return it.


*/