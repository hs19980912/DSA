Longest K unique characters substring
Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.

Example 1:
Input:
S = "aabacbebebe", K = 3
Output: 
7
Explanation: 
"cbebebe" is the longest substring with 3 distinct characters.

Example 2:
Input: 
S = "aaaa", K = 2
Output: -1
Explanation: 
There's no substring with 2 distinct characters.

====================================================================

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int ans = -1;
        int left = 0;
        int right = 0;
        unordered_map<char, int> contain;

        /* I have to include right index in my window, my window at any point in the loop WILL end at right.Now, what shall I do to make this window valid. */
        while(right < s.size()){
            char curChar = s[right];
            contain[curChar]+=1;
            while(contain.size() > k){
                contain[s[left]]-=1;
                if(contain[s[left]] == 0){
                    contain.erase(s[left]);
                }
                left+=1;
            }
            if(contain.size() == k)
                ans = max(ans, right-left+1);
            right+=1;
        }
    
        return ans;
    }
};