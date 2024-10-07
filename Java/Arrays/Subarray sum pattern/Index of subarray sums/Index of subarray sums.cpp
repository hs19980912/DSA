Indexes of Subarray Sum
Given an unsorted array arr of size n that contains only non negative integers, find a sub-array (continuous elements) that has sum equal to s. You mainly need to return the left and right indexes(1-based indexing) of that subarray.

In case of multiple subarrays, return the subarray indexes which come first on moving from left to right. If no such subarray exists return an array consisting of element -1.

Examples:

Input: arr[] = [1,2,3,7,5], n = 5, s = 12
Output: 2 4
Explanation: The sum of elements from 2nd to 4th position is 12.

=========================================================================

class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        // Your code here
        unordered_map<long long, int> m;  // sum -> first index
        long long sum = 0;
        m[0]=0;
        for(int i=0; i<arr.size(); ++i){
            sum+=arr[i];

            if(m.find(sum-s)!=m.end()){
                return {m[sum-s]+1, i+1};
            }
            
            if(m.find(sum)==m.end()){
                m[sum] = i+1;
            }
        }
        
        return {-1};
    }
};