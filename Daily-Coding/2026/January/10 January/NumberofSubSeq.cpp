/*
Tag: 2 Pointers, Modular Exponentiation, Sorting, Array

Problem Statement:
You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

 
Example 1:

Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)
Example 2:

Input: nums = [3,3,6,8], target = 10
Output: 6
Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
Example 3:

Input: nums = [2,3,3,4,6,7], target = 12
Output: 61
Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
Number of valid subsequences (63 - 2 = 61).
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
1 <= target <= 10^6
 

*/

#include <bits/stdc++.h>
using namespace std;
int numSubseq(vector<int>& nums, int target) {
    int ans=0;
    int num=1e9+7;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<int> pow2mod(n);
    pow2mod[0]=1;
    for(int i=1;i<n;i++){
        pow2mod[i]=(pow2mod[i-1]*2)%num;
    }
    int i=0;
    int j=nums.size()-1;
    while(i<=j){
        if(nums[i]+nums[j]<=target){
            int diff=j-i;
            ans=(ans+pow2mod[diff])%num;
            i++;
        }
        else{
            j--;
        }
    }
    return ans;
}


/*
My Solution:

- Sort the array to easily access minimum and maximum elements.
- Use two pointers, one starting at the beginning (i) and the other at the end (j) of the sorted array.
- If the sum of the elements at these pointers is less than or equal to the target, 
all subsequences formed by including the element at i and any combination of elements between i and j are valid. The number of such subsequences is 2^(j-i). Add this to the answer and move the left pointer (i) to the right.
- If the sum is greater than the target, move the right pointer (j) to the left to try and 
reduce the sum.
- Precompute powers of 2 modulo 10^9 + 7 to efficiently calculate the
number of subsequences.
- Continue this process until the two pointers meet.
- Return the final answer modulo 10^9 + 7.

- Sorting the array allows us to efficiently find valid subsequences by leveraging the properties of sorted order.
- The two-pointer technique helps in reducing the search space and efficiently counting valid subsequences.
- Precomputing powers of 2 ensures that we can quickly calculate the number of subsequences without recalculating powers repeatedly.

This is the best solution.
*/