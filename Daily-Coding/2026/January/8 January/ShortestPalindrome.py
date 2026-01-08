# Tag: Rolling Hash, String Matching
# Problem Statement:


# You are given a string s. You can convert s to a palindrome by adding characters in front of it.

# Return the shortest palindrome you can find by performing this transformation.

 

# Example 1:

# Input: s = "aacecaaa"
# Output: "aaacecaaa"
# Example 2:

# Input: s = "abcd"
# Output: "dcbabcd"
 

# Constraints:

# 0 <= s.length <= 5 * 104
# s consists of lowercase English letters only.

class Solution:
    def shortestPalindrome(self, s: str) -> str:
        length=len(s)
        reversed_string = s[::-1]
        for i in range(length):
            if s[:length-i]==reversed_string[i:]:
                # we found a prefix match to the suffix of the reversed string
                return reversed_string[:i]+s
        return ""
    

# My Solution:
# The solution uses a straightforward approach to find the shortest palindrome by checking for the longest palindromic prefix.
# It iterates through the string, comparing prefixes of the original string with suffixes of the reversed string.
# When a match is found, it constructs the shortest palindrome by prepending the necessary characters from the reversed string.
# The time complexity of this solution is O(n^2) in the worst case, where n is the length of the string.