int lcs(string &str1, string &str2){
    // Write your code here.
    int ans=0;
    int dp[1001][1001];

    for(int i=0; i<str2.size(); ++i){
        dp[str1.size()][i] = 0;
    }
    for(int i=0; i<=str1.size(); ++i){
        dp[i][str2.size()] = 0;
    }

    for(int i=str1.size()-1; i>=0; i--){
        for(int j=str2.size()-1; j>=0; j--){
            
            if(str1[i] == str2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }else{
                dp[i][j] = 0;
            }
            
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}