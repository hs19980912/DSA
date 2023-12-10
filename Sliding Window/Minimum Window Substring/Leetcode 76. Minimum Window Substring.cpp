class Solution {
public:

    bool smallcase(char c){
        return c>='a' && c<='z';
    }

    string minWindow(string s, string t) {
        if(t.size() > s.size()){
            return "";
        }
        vector<int> smap(53, 0);
        vector<int> tmap(53, 0);

        for(int i=0; i<t.size(); ++i){
            char curChar = t[i];
            if(smallcase(curChar)){
                tmap[curChar-'a']++;
            }else{
                tmap[curChar-'A'+26]++;
            }
        }

        int ans = INT_MAX;
        int leftAns = -1;
        int rightAns = -1;

        int count=0;
        int left=0;
        int right = -1;
        int len = s.size();
        char curChar;
        while(right < len){
            if(count == t.size()){
                curChar = s[left];
                if(smallcase(curChar)){
                    if(smap[curChar-'a'] == tmap[curChar-'a']){
                        count--;
                    }
                    smap[curChar-'a']--;
                }else{
                    if(smap[curChar-'A'+26] == tmap[curChar-'A'+26]){
                        count--;
                    }
                    smap[curChar-'A'+26]--;
                }
                left+=1;
            }else if(count < t.size()){
                right++;
                if(right<s.size()){
                    curChar = s[right];
                    if(smallcase(curChar)){
                        smap[curChar-'a']++;
                        if(smap[curChar-'a'] <= tmap[curChar-'a']){
                            count+=1;
                        }
                    }else{
                        smap[curChar-'A' + 26]++;
                        if(smap[curChar-'A'+26] <= tmap[curChar-'A'+26]){
                            count+=1;
                        }
                    }
                }
            }

            if(count == t.size()){
                if(right-left+1 < ans){
                    
                    leftAns = left;
                    rightAns = right;
                    ans = rightAns - leftAns + 1;
                }
            }
        }
        
        
        if(leftAns==-1){
            // We were unable to find any possible answer,
            // hence no possile answer exists
            return "";
        }

        else return s.substr(leftAns, ans);
    }
};