424. Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.

=================================================

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int left = 0;
        int right = 0;
        int maxFre = 0;
        vector<int> fre(26, 0);
        /*
        at every iteration, we will consider the susbtring ending at right index.
        If it is a valid susbtring, it is a possible ans.
        if not, start reducing the window to make it a valid susbtring and make it a possible ans.
        */
        for(int right=0; right<s.size(); ++right){
            fre[s[right]-'A']++;
            maxFre = max(maxFre, fre[s[right]-'A']);
            int len = right - left + 1;
            if(len - maxFre <= k){
                maxLen = max(maxLen, len);
            }else{
                if( (len - maxFre) > k && left < right){
                    fre[s[left]-'A']-=1;
                    left+=1;
                    for(int i=0; i<26; ++i){                            // This for loop is not needed
                        maxFre = max(maxFre, fre[i]);
                    }
                    len = right - left + 1;
                }
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};