class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest = 0;
        int left = 0;
        int right = 0;
        unordered_map<char, int> m;
        int maxFre = 0;
        
        while(right < s.size()){
            m[s[right]]+=1;
            maxFre = max(maxFre, m[s[right]]);
            int curLen = right - left + 1;
            if(curLen-maxFre <= k){
                longest = max(longest, curLen);
            }else{
                m[s[left]]-=1;
                left+=1;
            }
            right+=1;
        }
        
        return longest;
    }
};