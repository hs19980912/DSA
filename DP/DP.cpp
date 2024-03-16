
######################################################################################################
★ GENERAL  


1. Longest Arithmetic Progression.
Given an array called A[] of sorted integers having no duplicates, find the length of the Longest Arithmetic Progression (LLAP) in it.

Example 1:

Input:
N = 6
set[] = {1, 7, 10, 13, 14, 19}
Output: 4
Explanation: The longest arithmetic 
progression is {1, 7, 13, 19}.
Example 2:

Input:
N = 5
A[] = {2, 4, 6, 8, 10}
Output: 5
Explanation: The whole set is in AP.

# Code 1
Here Top down DP is used, slower than bottom up DP.
    // return the lenght of the LAP ending at i if possible 
    int findLLAP(int A[], int size, int diff, int i, vector<vector<int>>& dp){
        if(i < 0){
            return 0;
        }
        
        if(dp[diff][i]!=-1){
            return dp[diff][i];
        }
        
        int ans = 0;
        
        for(int j=i; j>=0; --j){
            if(A[i+1] - A[j] == diff){
                ans = max( ans , 1 + findLLAP(A, size, diff, j-1, dp) );
                return 1 + findLLAP(A, size, diff, j-1, dp);
            }
        }
        
        return dp[diff][i] = ans;
    }

    int lengthOfLongestAP(int A[], int n) {
        if(n <= 2){
            return n;
        }
        vector<vector<int>> dp(10001, vector<int>(1001, -1));
        int ans = 0;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                int diff = A[j] - A[i];
                int curAns = 2 + findLLAP(A, n, diff, i-1, dp);
                // dp[diff][j] = curAns;
                ans = max(ans, curAns);
            }
        }
        
        return ans;
    }

# Code 2:
Here Bottom up DP is used.

------------------------------------------------------------------------------------------------------------------------