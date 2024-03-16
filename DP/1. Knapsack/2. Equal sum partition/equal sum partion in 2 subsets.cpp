class Solution{
public:

    int subsetSumEqual(int arr[], int size, int index, int target, vector<vector<int>>& dp){
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        if(index == size){
            if(target == 0){
                return dp[index][target] = 1;
            }
            return dp[index][target] = 0;
        }

        bool ans = false;

        if(arr[index] <= target){
            ans = subsetSumEqual(arr, size, index+1, target - arr[index], dp);
        }   
        if(ans == false){
            ans = subsetSumEqual(arr, size, index+1, target, dp);
        }

        return dp[index][target] = ans;
    }

    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0; i<N; ++i){
            sum+=arr[i];
        }

        if(sum%2 != 0){ // Total sum is odd
            return 0;
        }

        sum = sum/2;

        vector<vector<int>> dp(N+1, vector<int>(sum+1, -1));
        return subsetSumEqual(arr, N, 0, sum, dp);
    }
};