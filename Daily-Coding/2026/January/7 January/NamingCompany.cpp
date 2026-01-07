/*
Tag: Array, String, Hash Table, Bit Manipulation

Problem Statement:

You are given an array of strings ideas that represents a list of names to be used in the process of naming a company. The process of naming a company is as follows:

Choose 2 distinct names from ideas, call them ideaA and ideaB.
Swap the first letters of ideaA and ideaB with each other.
If both of the new names are not found in the original ideas, then the name ideaA ideaB (the concatenation of ideaA and ideaB, separated by a space) is a valid company name.
Otherwise, it is not a valid name.
Return the number of distinct valid names for the company.

 

Example 1:

Input: ideas = ["coffee","donuts","time","toffee"]
Output: 6
Explanation: The following selections are valid:
- ("coffee", "donuts"): The company name created is "doffee conuts".
- ("donuts", "coffee"): The company name created is "conuts doffee".
- ("donuts", "time"): The company name created is "tonuts dime".
- ("donuts", "toffee"): The company name created is "tonuts doffee".
- ("time", "donuts"): The company name created is "dime tonuts".
- ("toffee", "donuts"): The company name created is "doffee tonuts".
Therefore, there are a total of 6 distinct company names.

The following are some examples of invalid selections:
- ("coffee", "time"): The name "toffee" formed after swapping already exists in the original array.
- ("time", "toffee"): Both names are still the same after swapping and exist in the original array.
- ("coffee", "toffee"): Both names formed after swapping already exist in the original array.
Example 2:

Input: ideas = ["lack","back"]
Output: 0
Explanation: There are no valid selections. Therefore, 0 is returned.
 

Constraints:

2 <= ideas.length <= 5 * 10^4
1 <= ideas[i].length <= 10
ideas[i] consists of lowercase English letters.
All the strings in ideas are unique.
*/

#include<bits/stdc++.h>
using namespace std;

long long distinctNames(vector<string>& ideas) {
    // group the names by the first letter

    // now we only have 26 different letters and different number of suffixes in each

    // what we want to have, is to replace the first letter, or in another words replace the suffixes, 
    // and mix match, while doing so, we do not want to end up with 2 words from the existing set again.

    // we can achieve this by looking at the suffixes in other character that we are looking at, inside the grouping
    // then if not, we can increase the counts from that character, and similarly do that for all character pairs.

    unordered_set<string> groups[26];
    for(auto &idea:ideas){
        groups[idea[0]-'a'].insert(idea.substr(1)); // group the suffixes with the first letters
    }

    long long total = 0;
    for(int i=0;i<26;i++){
        for(int j=i+1;j<26;j++){
            long long c1=0;
            long long c2=0;
            for(auto &suff:groups[i]){
                if(!groups[j].count(suff)){
                    c1++;
                }
            }
            for(auto &suff:groups[j]){
                if(!groups[i].count(suff)){
                    c2++;
                }
            }
            total+=c1*c2;
        }
    }
    return total*2;
}

/*
My Solution: An Inspiration from the editorial (did not form a full idea.)

- Group the suffixes by their first letters.
- Now for each pair of letters, check the number of words in each sets that do not exist in the other
- Multiply the counts to indicate the number of combinations possible between the two sets.
- Finally multiply the total by 2 to account for 2 arrangements in the company name where either could be first and last.


*/