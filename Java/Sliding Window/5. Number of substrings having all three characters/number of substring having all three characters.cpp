1358. Number of Substrings Containing All Three Characters

Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.

Example 1:
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

Example 2:
Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

Example 3:
Input: s = "abc"
Output: 1
======================================================================

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int left = 0;
        int right = 0;
        unordered_map<char, int> m;
        m['a'] = 0;
        m['b'] = 0;
        m['c'] = 0;
        
/*
        current window is from left to right -1,
        is this window valid?? Does it contain all 3 chars?
        if yes, 
            Then all the substring of the form 
            [left...right-1], [left...right], [left...right+1], [left...size] are valid.
            ans += (s.size() - right + 1); takes care of it.
            if condition handles this
        if No,
            then we want more chars, keep expanding the window to the right keeping 
            left as constant till we get a valid subtring.
            else condition takes care for it.
            
*/
        
        while(right<=s.size()){
            if (m['a'] > 0 && m['b'] > 0 && m['c'] > 0) {
                ans += (s.size() - right + 1);
                m[s[left]] -= 1;
                left += 1;
            } else {
                if (right < s.size()) {
                    m[s[right]] += 1;
                }
                right += 1;
            }
        }

        return ans;
    }
};