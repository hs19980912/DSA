class Solution {
public:
    int ans;
    int l, r;
    
    bool isSmallcase(char& a){
        return a>='a' && a<='z';
    }
    
    void longestNice(string& str, int start, int end){
        if(end-start+1 < 2) return;
        
        unordered_set<char> s;
        
        for(int i=start; i<=end; ++i){
            s.insert(str[i]);
        }
        
        int i=start;
        
        while(i<=end){
            // will analyze ith index
            if(isSmallcase(str[i])){
                if(s.find('A' + str[i] - 'a') == s.end()){
                    // didnt find the char
                    longestNice(str, start, i-1);
                    longestNice(str, i+1, end);
                    return;
                }
            }else{
                // when str[i] is large case
                if(s.find('a' + str[i] - 'A') == s.end()){
                    // didnt find the character
                    longestNice(str, start, i-1);
                    longestNice(str, i+1, end);
                    return;
                }
            }
            
            ++i;
        }
        
        // if we have reached till here
        // means, the entire [start, end] is a possible answer.
        if(end-start+1 >= ans){
            if((end-start+1 > ans) || (end-start+1 == ans && start < l) ){
                ans = end-start+1;  // new length of the answer
                l = start;
                r = end;
            }
        }
        return;
    }
    
    string longestNiceSubstring(string s) {
        ans = 0;
        l=INT_MAX;
        longestNice(s, 0, s.size()-1);
        
        if(ans == 0){
            return "";
        }else{
            return s.substr(l, r-l+1);
        }
    }
};