class Solution{
  public:
    int maxPriceWhenRodStartAtIndex(int price[], int size, int curLen, vector<int>& dp){
        if(dp[curLen]!=-1){
            return dp[curLen];
        }
        if(curLen==0){
            return dp[curLen] = 0;
        }
        int ans = price[curLen - 1];

        for(int part1 = 1; part1<=curLen-1; ++part1){
            int curAns=0;
            curAns += maxPriceWhenRodStartAtIndex(price, size, part1, dp);
            curAns += maxPriceWhenRodStartAtIndex(price, size, curLen - part1, dp);
            ans = max(ans, curAns);
        }

        return dp[curLen] = ans;
    }

    int cutRod(int price[], int n) {
        //code here
        vector<int> dp(n+1, -1);
        return maxPriceWhenRodStartAtIndex(price, n, n, dp);
    }
};