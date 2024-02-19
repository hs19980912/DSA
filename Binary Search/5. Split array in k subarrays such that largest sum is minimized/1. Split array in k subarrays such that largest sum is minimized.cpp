410. Split Array Largest Sum

Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 
Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.


Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.


=========================================================================
class Solution {
public:

    int findParts(vector<int>& arr, int sumLimit){
        int parts = 1;
        int curSum = 0;
        for(int i=0; i<arr.size(); ++i){
            if(curSum + arr[i] <= sumLimit){
                curSum+=arr[i];
            }else{
                parts+=1;
                curSum = arr[i];
            }
        }

        return parts;
    }

    int splitArray(vector<int>& nums, int k) {
        long long int maxEle = INT_MIN;
        long long int sum = 0;

        for(int i=0; i<nums.size(); ++i){
            maxEle = max(maxEle, nums[i]);
            sum+=nums[i];
        }

        long long ans = -1;

        long long l = maxEle;
        long long r = sum;

        while(l <= r){

            long long curSum = l + (r - l)/2;
            int parts = findParts(nums, curSum);

            if(parts > k){
                // curSum is smaller than expected beacuse we need more parts to fit our array. increase the curSum;
                l = curSum + 1;
            }else{ // parts <= k
                // curSum is larger/sufficient to fit array in k parts.
                // decrese the curSum to check for more optimized ans;
                ans = curSum;
                r = curSum - 1;
            }

        }

        return ans;
    }
};