/*
Type: Arrays, Prefix Sum, Strings

Problem Statement:
You are given a 0-indexed array of strings words and a 2D array of integers queries.

Each query queries[i] = [li, ri] asks us to find the number of strings present at the indices ranging from li to ri (both inclusive) of words that start and end with a vowel.

Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

Example 1:

Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
The answer to the query [0,2] is 2 (strings "aba" and "ece").
to query [1,4] is 3 (strings "ece", "aa", "e").
to query [1,1] is 0.
We return [2,3,0].
Example 2:

Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
Output: [3,2,1]
Explanation: Every string satisfies the conditions, so we return [3,2,1].
 

Constraints:

1 <= words.length <= 10^5
1 <= words[i].length <= 40
words[i] consists only of lowercase English letters.
sum(words[i].length) <= 3 * 10^5
1 <= queries.length <= 10^5
0 <= li <= ri < words.length

*/

#include<bits/stdc++.h>
using namespace std;
vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    vector<int> isVowel;
    unordered_set<char> vowels={'a','e','i','o','u'};
    for(auto word:words){
        if(vowels.find(word[0])!=vowels.end()){
            if(vowels.find(word[word.size()-1])!=vowels.end()){
                isVowel.push_back(1);
                continue;
            }
        }
        isVowel.push_back(0);
    }

    vector<int> VowelPrefix;
    for(int i=0;i<isVowel.size();i++){
        if(i==0){
            VowelPrefix.push_back(isVowel[i]);
            continue;
        }
        VowelPrefix.push_back(isVowel[i]+VowelPrefix[i-1]);
    }

    vector<int> ans;
    for(auto query:queries){
        int answer=(VowelPrefix[query[1]]);
        if(query[0]==0){
            ans.push_back(answer);
            continue;
        }
        ans.push_back(answer-VowelPrefix[query[0]-1]);
    }
    return ans;
}

/*
My Solution:
I approached the problem this way:
- The idea is to count the number of vowel strings (first and last letter are vowels) in the query range
- To do that, I first computed the vowel status of each word and stored it in an array (vector)
- Then using the status created for each word, I created a prefix sum array to store cumulative counts
- I did this because, I noticed the queries had a length of up to 10^5, and calculating the count for each query directly would be inefficient because we would need iteration over the query range in the vowel status vector.
- Doing this way, would just need to have a difference in the cumulative counts between the right most index and the left most (un included) index to get the count of vowel strings in that range.
- Finally, I processed each query using the prefix sum array to get the count of vowel strings in the specified range and stored the results in an answer array.

This solution had 3*O(N)~O(N) time complexity and 3*O(N)~O(N) space complexity, which is efficient given the constraints. But not the best solution according to the existing ones.

Best Solution:
It has the same logic as mine, but it optimizes space by not copying elements and strings.

A bit optimized one, and is built from mine:

class Solution {
public:
    bool isValidVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> VowelPrefix(words.size(),0);
        for(int i=0;i<words.size();i++){
            int ans = isValidVowel(words[i][0]) && isValidVowel(words[i].back());
            if(i==0){
                VowelPrefix[i]=(ans);
                continue;
            }
            VowelPrefix[i]=(ans+VowelPrefix[i-1]);
        }

        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int answer=(VowelPrefix[queries[i][1]]);
            if(queries[i][0]==0){
                ans.push_back(answer);
                continue;
            }
            ans.push_back(answer-VowelPrefix[queries[i][0]-1]);
        }
        return ans;
    }
};

*/