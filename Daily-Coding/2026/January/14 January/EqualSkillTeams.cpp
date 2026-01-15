/*
Tag: Two Pointers, Array

Problem Statement:

You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.

The chemistry of a team is equal to the product of the skills of the players on that team.

Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.

 

Example 1:

Input: skill = [3,2,5,1,3,4]
Output: 22
Explanation: 
Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each team has a total skill of 6.
The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.
Example 2:

Input: skill = [3,4]
Output: 12
Explanation: 
The two players form a team with a total skill of 7.
The chemistry of the team is 3 * 4 = 12.
Example 3:

Input: skill = [1,1,2,3]
Output: -1
Explanation: 
There is no way to divide the players into teams such that the total skill of each team is equal.
 

Constraints:

2 <= skill.length <= 105
skill.length is even.
1 <= skill[i] <= 1000
*/
#include<bits /stdc++.h>
using namespace std;
long long dividePlayers(vector<int>& skill) {
    sort(skill.begin(),skill.end());
    if(skill.size()%2!=0 || skill.size()<=1){
        return -1;
    }
    int s=skill.back()+skill[0];
    int i=1;
    int j=skill.size()-2;
    long long prod = skill[0]*skill.back();
    while(i<j){
        if(skill[i]+skill[j]==s){
            prod+=(skill[i]*skill[j]);
            i++;
            j--;
        }
        else{
            return -1;
        }
    }
    return prod;
}

/*
My Solution:

- Sort the skill into a non-decreasing order, we do this because of a simple explanation:
=> We need equal sum teams, so that means we need teams like (a,k-a), (b,k-b) and so on, 
so if we sort the skill, we can easily check if the first and last element of the skill 
array sum up to the same value, if they do then we can check for the next pair and so on, 
if they don't then we can return -1.

- We can use two pointers to check for the pairs, one pointer at the beginning of the array and 
one pointer at the end of the array, we can check if the sum of the elements at these 
pointers is equal to the sum of the first and last element, if it is then we can add the 
product of these two elements to our answer and move the pointers towards the center, 
if it is not then we can return -1.



*/