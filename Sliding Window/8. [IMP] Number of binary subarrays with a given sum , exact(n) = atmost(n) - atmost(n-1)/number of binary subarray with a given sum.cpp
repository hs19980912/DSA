930. Binary Subarrays With Sum

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.

Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

Example 2:
Input: nums = [0,0,0,0,0], goal = 0
Output: 15

==============================================================================================

class Solution {
public:
    
    int atmost(vector<int>& nums, int goal){
        int subarrays = 0;
        int left = 0;
        int right = 0;
        int curSum = 0;
        
        while(right<nums.size()){
            curSum+=nums[right];
            while(curSum > goal && left<=right){
                curSum-=nums[left];
                left+=1;
            }
            
            subarrays+=(right-left+1);
            right+=1;
        }
        
        return subarrays;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // exact(2) = atmost(2) - atmost(1)
        int exact_2 = 0;
        int atmost_2 = atmost(nums, goal);
        int atmost_1 = atmost(nums, goal-1);
        
        exact_2 = atmost_2 - atmost_1;
        
        return exact_2;
        
        // https://www.youtube.com/watch?v=Pkqq6kv2E6k
    }
};