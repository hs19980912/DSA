// 424. Longest Repeating Character Replacement
class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size() == 0){
            return 0;
        }
        vector<int> fre(26, 0);
        
        int ans = 0;
        int l=0;
        int r=0;
        fre[s[r] - 'A']++;
        
        while(r<s.size()){
            // will analyze between [l , r]
            // fre is already set
            
            int maxCharSize = -1;
            // what is the current maxChar in range [l, r]
            for(int i=l; i<=r; ++i){
                maxCharSize = max(maxCharSize, fre[s[i] -'A']);
            }
            
            if(r-l+1 - maxCharSize <= k){
                // it is a valid sequence
                ans = max(ans, r-l+1);
                ++r;
                if(r < s.size()){
                    fre[s[r] - 'A']++;
                }
            }else{
                // This cannot be a valid sequence
                // but we have to consider the rth element
                // remove the ith element
                fre[s[l] - 'A']--;
                l++;
            }
        }
        
        return ans;
    }
};