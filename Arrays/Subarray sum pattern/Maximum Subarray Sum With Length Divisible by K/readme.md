## Maximum subarray sum with length divisible by K

> ❗ Maintain minimum prefix sum ending at every possible index%k.

You are given an array of integers nums and an integer k. Return the maximum sum of a subarray of nums, such that the size of the subarray is divisible by k.

Example 1:

Input: nums = [1,2], k = 1

Output: 3

Explanation:
The subarray [1, 2] with sum 3 has length equal to 2 which is divisible by 1.

Example 2:

Input: nums = [-1,-2,-3,-4,-5], k = 4

Output: -10

Explanation:
The maximum sum subarray is [-1, -2, -3, -4] which has length equal to 4 which is divisible by 4.

Example 3:

Input: nums = [-5,1,2,-3,4], k = 2

Output: 4

Explanation:
The maximum sum subarray is [1, 2, -3, 4] which has length equal to 4 which is divisible by 2.

```cpp
long long maxSubarraySum(vector<int>& nums, int k) {
    
    long long int ans = -1000000000000000;
    long long int curSum = 0;
    vector<long long int> m(k);
    m[0] = 0;
    for(int i=0; i<k-1; ++i){
        curSum += nums[i];
        m[i+1] = curSum;
    }
    
    for(int i=k-1; i<nums.size(); ++i){
        curSum+=nums[i];
        int curIndex = i+1;
        ans = max(ans, curSum-m[curIndex%k]);
        m[curIndex%k] = min(m[curIndex%k], curSum);
    }
    
    return ans;
}
```