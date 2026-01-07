/*
Tag: Arrays, Hashtable, String

Problem Statement:
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.
Return any permutation of s that satisfies this property.


Example 1:

Input: order = "cba", s = "abcd"

Output: "cbad"

Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".

Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

Example 2:

Input: order = "bcafg", s = "abcd"

Output: "bcad"

Explanation: The characters "b", "c", and "a" from order dictate the order for the characters in s. The character "d" in s does not appear in order, so its position is flexible.

Following the order of appearance in order, "b", "c", and "a" from s should be arranged as "b", "c", "a". "d" can be placed at any position since it's not in order. The output "bcad" correctly follows this rule. Other arrangements like "dbca" or "bcda" would also be valid, as long as "b", "c", "a" maintain their order.

 

Constraints:

1 <= order.length <= 26
1 <= s.length <= 200
order and s consist of lowercase English letters.
All the characters of order are unique.

*/

#include<bits/stdc++.h>
using namespace std;
string customSortString(string order, string s) {
    string ans="";
    map<char,int> mp;
    for(auto &c:s){
        mp[c]++;
    }
    for(auto &c:order){
        ans+=string(mp[c],c);
        mp[c]=0;
    }
    for(auto &it:mp){
        if(it.second!=0){
            ans+=string(it.second,it.first);
        }
    }
    return ans;
}

/*
My Solution:

- Just count the frequency of each character in the string s using a hashtable. 
- Now, by following the order in the string order, append the characters to the answer string according to their frequency.
- This enables all the characters according to the order in the answer string, now add the leftover characters in any order, it does not matter.

This is the best Time Complex Solution possible for this problem.
*/