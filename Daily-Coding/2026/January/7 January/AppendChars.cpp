/*
Tag: Arrays, Strings

Problem Statement:

You are given two strings s and t consisting of only lowercase English letters. Return the minimum number of characters that need 
to be appended to the end of s so that t becomes a subsequence of s.

A subsequence is a string that can be derived from another string by  deleting some or no characters without changing the order of
the remaining characters.

Constraints:

1 <= s.length, t.length <= 10^5
s and t consist only of lowercase English letters.

Example 1:
Input: s = "coaching", t = "coding"
Output: 4
Explanation: Append the characters "ding" to the end of s so that s = "coachingding".
Now, t is a subsequence of s ("coachingding").
It can be shown that appending any 3 characters to the end of s will never make t a subsequence.

*/

#include <bits/stdc++.h>
using namespace std;

int appendCharacters(string s, string t) {
    int i=0;
    int j=0;
    int n=s.size();
    int m=t.size();
    while(i<=n-1 && j<=m-1){
        if(s[i]==t[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    if(i==n && j!=m){
        return m-j;
    }
    else if(i!=n && j==m){
        return 0;
    }
    else if(i==n && j==m){
        return 0;
    }
return m-j;
}

/*
My Solution:

The core idea is to build subsequence t from string s by adding as minimum characters as possible at the end of s, and subsequences
are contiuous while skipping characters in the original string but in the same order. From the question it is guaranteed that there will definitely
be a subsequence from the given s, which means the order of letters in string t will be as they are in the string s. 
As we want to add minimum number of characters we only add the remaining characters that do not appear in the sequence in string s when compared to string t.

Approach
- Initialize 2 pointers for each string.
- Traverse through both strings until we reach the end of either string
- If characters at both pointers match, move both pointers forward.
- If characters do not match, move pointer of string s forward.
- After the loop, if pointer of string t has not reached the end, the remaining characters in t need to be appended to s.

This is the best solution according to time complexity O(n) and space complexity O(1)
*/