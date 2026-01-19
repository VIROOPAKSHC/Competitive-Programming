/*
Tag: 2 Pointers, Array, Sliding Window

Problem Statement:
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 10^4
s1 and s2 consist of lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;
bool checkInclusion(string s1, string s2) {
    map<char,int> base;
    int k=0;
    for(auto &c:s1) {base[c]++;k++;}
    int prev=0;
    int i=0;
    while(i<s2.size()){
        int enter_i = i;
        int copy_k = k;
        map<char,int> inclusion(base);
        while(i<s2.size() && inclusion.find(s2[i])!=inclusion.end()){
            inclusion[s2[i]]--;
            copy_k--;
            if(inclusion[s2[i]]==0){inclusion.erase(s2[i]);}
            i++;
        }
        if(copy_k==0){
            return true;
        }
        if(i>=s2.size()){
            break;
        }
        if(i>enter_i+1 || i==enter_i){
            i=enter_i+1;
        }
    }
    return false;
}

/*
My Approach:

- Initially I collected the occurrences of letters in s1 using a map and the total length using k
- Next, I went through each index in s2 and started with the existing map and length of s1 and if an occurrence of existing character from s1 occurs we try to check if there is a existence of permutation by using the map and reducing the occurrence on a copy,
- If it fails, that is the reductions was not equal to the total length of s1, then we again go back to the earlier index + 1 and restart it.


Best Approach:

- We can use a sliding window approach to solve this problem efficiently. We can maintain a frequency count of characters in s1 and a sliding window of the same length in s2. As we slide the window across s2, we can update the frequency count and check if it matches the frequency count of s1.
Code looks like this:

bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){return false;}
        vector<int> base(26,0);
        vector<int> comp(26,0);
        for(int i=0;i<s1.size();i++){
            base[s1[i]-'a']++;
            comp[s2[i]-'a']++;
        }

        if(base==comp)
            return true;

        for(int i=s1.size();i<s2.size();i++){
            comp[s2[i]-'a']++;
            comp[s2[i-s1.size()]-'a']--;
            if(comp==base)
                return true;
        }
        return false;
    }
*/