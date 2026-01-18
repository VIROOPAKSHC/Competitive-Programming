/*
Tag: Stack

Problem Statement:
You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.
 

Example 1:

Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".
Example 2:

Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters and stars *.
The operation above can be performed on s.
*/

#include<bits/stdc++.h>
using namespace std;
string removeStars(string s) {
    int n=s.size();
    vector<int> indxs(n,0);
    int prev=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='*'){
            prev++;
            indxs[i]=1;
        }
        else{
            indxs[i]=prev>0?1:0;
            if(prev>0)
                prev--;
            
        }
        
    }
    string final="";
    for(int i=0;i<s.size();i++){
        if(indxs[i]==0){
            final+=s[i];
        }
    }
    return final;
}

/*
My Approach:

- Create a vector of indices indicating that if the character should be in the final string or not, 
- To know so, we need to traverse from the back side and if a star appears, you should not add the character before it, if multiple appears, the length of stars are the length of chars that need to be skipped
- And at every index, if the count of stars before it is >0, we say the character at that index should not be in the final string.

- We create an empty string and add chars from allowed indices accordingly.


*/