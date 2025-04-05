LC 2799. Count Complete Subarrays in an Array

You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.
Example 1:

Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
Example 2:

Input: nums = [5,5,5,5]
Output: 10
Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.

=================================================================

It follows the same pattern, Subarray(exact(n)) = Subarray(atmost(n)) - Subarray(atmost(n-1));


    int numSubArrays(vector<int>& arr, int k){
        int ans = 0;
        int i = 0;
        int j = 0;
        int n = arr.size(); 
        unordered_map<int, int> store;

        while(j<n){
            store[arr[j]]+=1;
            while(store.size()>k){
                store[arr[i]]-=1;
                if(store[arr[i]]==0){
                    store.erase(arr[i]);
                }
                i+=1;
            }
            ans+=(j-i+1);
            j+=1;
        }

        return ans;
    }

    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> store;
        for(int i=0; i<nums.size(); ++i){
            store.insert(nums[i]);
        }
        int uniques = store.size();
        int atmostN = numSubArrays(nums, uniques);
        int atmostN_1 = numSubArrays(nums, uniques-1);

        int exact_n = atmostN - atmostN_1;

        return exact_n;
    }