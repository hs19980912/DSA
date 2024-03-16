// GFG - Subset Sum Problem

/*
    VER IMPORTANT: In our abstraction, it is important to go till the last index of the array.
                   This will be useful for further problems based on subset sum where the elements can be 0
                   eg: LC 494. Target Sum etc.

*/

class Solution{   
public:
    
    int subsetSumExists(vector<int>& arr, int target, int index, vector<vector<int>>& dp){
        
        if(dp[target][index]!=-1){
            return dp[target][index];
        }

        if(index == arr.size()){
            if(target == 0){
                return true;
            }
            return false;
        }

        bool ans = false;

        if(arr[index] <= target){
            ans = subsetSumExists(arr, target - arr[index], index+1 , dp);
        }
        if(ans != 1){
            ans = subsetSumExists(arr, target, index+1, dp);
        }

        return  dp[target][index] = ans;
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<int>> dp(sum+1, vector<int>(arr.size()+1, -1));
        return subsetSumExists(arr, sum, 0, dp);
    }
};