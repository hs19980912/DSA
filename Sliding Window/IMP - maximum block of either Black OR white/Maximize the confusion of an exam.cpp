// 2024. Maximize the Confusion of an Exam

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans=0;
        int l=0;
        int r=0;
        
        int change = k;
        // Aim to make T
        while(r < answerKey.size()){
            if(answerKey[r] == 'T'){
                ans = max(ans, r-l+1);
                r++;
            }else{
                // it is F, we have to change it.
                if(change>0){
                    // we can change it, so change it
                    change--;
                    ans = max(ans, r-l+1);
                    r++;
                }else{
                    // we cannot change it
                    // move the left side to the first occurance of F + 1;
                    while( l<=r && answerKey[l]!='F' ){
                        l++;
                    }
                    l++;
                    change++;
                }
            }
        }
        
        
        
        // Changing T to F
        change=k;
        l = 0;
        r = 0;
        
        while(r < answerKey.size()){
            if(answerKey[r] == 'F'){
                ans = max(ans, r-l+1);
                r++;
            }else{
                if(change>0){
                    // we can change it, so change it
                    change--;
                    ans = max(ans, r-l+1);
                    r++;
                }else{
                    while( l<=r && answerKey[l]!='T' ){
                        l++;
                    }
                    l++;
                    change++;
                }
            }
        }
        
        return ans;
    }
};