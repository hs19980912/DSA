992. Subarrays with K Different Integers

Given an integer array nums and an integer k, return the number of good subarrays of nums.
A good array is an array where the number of different integers in that array is exactly k.
For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 
Example 1:
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

Example 2:
Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

============================================================================================
class Solution {
public:
    
    int atmostK(vector<int>& arr, int k){
        int subarrays = 0;
        int l = 0;
        unordered_map<int, int> m; // number -> frequency
        
        /*At every iteration window will end at right index, Now
        if current window has "atmost k different elements" then
        total number of subtrings ending at right index having 
        atmost k differnt substring is = right - len + 1
        why is it so?? 
        [r]
        [r-1, r]
        [r-2, r-1, r]
        ...
        [l, ... r]
        Total substring possible = r-l+1       */
        for(int r=0; r<arr.size(); ++r){
            m[arr[r]]+=1;
            if(m.size()<=k){
                subarrays+=r-l+1;
            }else{
                while(m.size()>k && l<=r){
                    m[arr[l]]-=1;
                    if(m[arr[l]] == 0){
                        m.erase(arr[l]);
                    }
                    l+=1;
                }
                subarrays+=r-l+1;
            }
        }
        return  subarrays;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int exact_n = 0;
        int atmost_n = atmostK(nums, k);
        int atmost_n_1 = atmostK(nums, k-1);
        
        exact_n = atmost_n - atmost_n_1;
        return exact_n;
        // https://www.youtube.com/watch?v=Pkqq6kv2E6k
    }
};