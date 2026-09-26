/*
3. Longest Substring Without Repeating Characters
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring

*/.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string sub;
        int maxLen = 0;

        for (char ch : s) {
            while (sub.find(ch) != string::npos) {
                sub.erase(0, 1);
            }
            sub.push_back(ch);
            maxLen = max(maxLen, (int)sub.size());
        }
        return maxLen;
    }
};
