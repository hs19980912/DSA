3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

=====================================================================================================

    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        
        int left = 0;
        int right = 0;
        vector<bool> present(256, false);
        
        // Consider right, whether it should be included or not?
        while(right < s.size()){
            char curChar = s[right];
            if(present[curChar] == false){
                present[curChar] = true;
            }else{
                while(left<right && curChar!=s[left]){
                    present[s[left]] = false;
                    left+=1;
                }
                if(left!=right){
                    left+=1;
                }
            }

            ans = max(ans, right - left + 1);
            right+=1;            
        }
        
        return ans;
    }