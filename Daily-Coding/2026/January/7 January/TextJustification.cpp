/*
Tag: Arrays, String, Simulation

Problem Statement:

Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
 

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
Example 3:

Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
 

Constraints:

1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth

*/
#include<bits/stdc++.h>
using namespace std;
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> curr_line;
    int word_len_sum = 0;
    vector<string> ans;
    int i=0;
    for(i=0;i<words.size();i++){
        if(word_len_sum+curr_line.size()+words[i].size()>maxWidth){
            int diff=maxWidth-curr_line.size()+1-word_len_sum;
            int k,p;
            string answer="";
            if(curr_line.size()==1){
                string remaining=string(maxWidth-curr_line[0].size(),' ');
                answer=curr_line[0]+remaining;
            }
            else{
                k=(diff/(curr_line.size()-1))+1;
                p=diff%(curr_line.size()-1);
                string space_string=string(k,' ');
                // create the string
                int k=0;
                for(k=0;k<curr_line.size()-1;k++){
                    auto &word=curr_line[k];
                    answer+=word+space_string;
                    if(p){
                        answer+=' ';
                        p--;
                    }
                }
                answer+=curr_line[k];
            }
            // append it to the answer
            cout<<answer<<endl;
            ans.push_back(answer);
            // clear the vector, and zero the word_len_sum
            curr_line.clear();
            word_len_sum=0;

        }
        word_len_sum+=words[i].size();
        curr_line.push_back(words[i]);

        if(i==words.size()-1){
            string last_word="";

            for(int k=0;k<curr_line.size()-1;k++){
                auto &word=curr_line[k];
                last_word=last_word+word+' ';

            }
            last_word+=curr_line.back();
            

            string remaining="";
            int c=last_word.size();
            if(maxWidth-c){remaining=string(maxWidth-c,' ');}
            
            last_word+=remaining;
            ans.push_back(last_word);
            break;
        }

        
        
    }
    
    return ans;
}

/*
My Solution:

- Basically we want to have words in a line with spaces such that the total length is maxWidth.
- To do that, first we need to understand how many words can fit in a line.
- We keep the words till now in a temporary vector, sum of all lengths of words in a variable.
- Now, while adding a new word we check if the total length + space for each word + length of the new word exceeds the maxWidth.
- If it does, we need to only create a line with the existing words in the temporary vector and evenly space them.
- To do so, we need to find the difference between maxWidth and the sum of lengths of words in the temporary vector and then distribute it evenly.
- To distribute, we need to find the division and modulus of the difference with number of spaces (number of words - 1) because for all the lines except for the last one we only add spaces between the words.
- If there is only one word in the line, we just add spaces to the end of the word.
- After creating the line, we clear the temporary vector and reset the sum of lengths variable.
- Finally, we need to handle the last line separately because it needs to be left justified, so we just add words with a single space and fill the remaining length with spaces.


This is the best solution.
*/