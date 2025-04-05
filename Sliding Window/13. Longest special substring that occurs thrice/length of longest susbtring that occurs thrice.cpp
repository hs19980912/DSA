LC 2982. Find Longest Special Substring That Occurs Thrice

You are given a string s that consists of lowercase English letters.

A string is called special if it is made up of only a single character. For example, the string "abc" is not special, whereas the strings "ddd", "zz", and "f" are special.

Return the length of the longest special substring of s which occurs at least thrice, or -1 if no special substring occurs at least thrice.

A substring is a contiguous non-empty sequence of characters within a string.

Example 1:
Input: s = "aaaa"
Output: 2
Explanation: The longest special substring which occurs thrice is "aa": substrings "aaaa", "aaaa", and "aaaa".
It can be shown that the maximum length achievable is 2.

Example 2:
Input: s = "abcdef"
Output: -1
Explanation: There exists no special substring which occurs at least thrice. Hence return -1.

Example 3:
Input: s = "abcaba"
Output: 1
Explanation: The longest special substring which occurs thrice is "a": substrings "abcaba", "abcaba", and "abcaba".
It can be shown that the maximum length achievable is 1.


Algorithm:
Hint!!

Simply do Binary Search on the window size and you are good to go....
A pretty nice problem involving both Sliding Window and Binary Search.
====================================================================================================================

bool longestSpecialSubstring(string& s, int k){
    if(k == 0){
        return true;
    }
    vector<int> count(26, 0);
    unordered_map<char, int> m;
    for(int i=0; i<k; ++i){
        m[s[i]]+=1;
    }

    int i=0;
    int j=k-1;

    // analyzing the current window ending at j th index
    while(j<s.size()){
        if(m.size() == 1){
            count[s[j]-'a']+=1;
            if(count[s[j]-'a']>=3){
                return true;
            }
        }

        // 1. Remove i th index from window
        m[s[i]]-=1;
        if(m[s[i]]==0){
            m.erase(s[i]);
        }
        
        // 2. increment i
        i+=1;
        
        // 3. add j+1 th index (if possibe)
        if(j+1 < s.size()){
            m[s[j+1]]+=1;
        }
        j+=1;
    }

    return false;
}

int maximumLength(string s) {
    int l = 0;
    int r = s.size()-1;
    int ans = 0;
    while(l<=r){
        int mid = l + ((r-l)/2);
        bool isPossible = longestSpecialSubstring(s, mid);
        if(isPossible){
            // some answer has been found, lets increase the window to find a better ans.
            ans = max(ans, mid);
            l = mid+1; 
        }else{
            // decrease the window
            r = mid-1;
        }
    }
    return ans==0?-1:ans;
}