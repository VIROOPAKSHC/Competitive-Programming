/*
Tag: Two Pointers, Sorting, Greedy

Problem Statement:
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

 

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
Example 3:

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
 

Constraints:

1 <= people.length <= 5 * 104
1 <= people[i] <= limit <= 3 * 104
*/
#include <bits/stdc++.h>
using namespace std;
int numRescueBoats(vector<int>& people, int limit) {
        int c=0;
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1,curr=0;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                i++;
            }
            c++;
            j--;
        }
        return c;
}

/*
My Approach:

- As the boat can carry at most two people, we can sort the array and use two pointers to find the minimum number of boats required.
- We can initialize two pointers, one at the beginning of the array and one at the end of the array. We can check if the sum of the weights of the people at the two pointers is less than or equal to the limit. If it is, we can move both pointers towards the center of the array. If it is not, we can move only the pointer at the end of the array towards the center. We can keep track of the number of boats required and return it at the end.


*/