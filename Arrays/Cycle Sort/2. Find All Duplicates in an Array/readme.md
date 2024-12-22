## Find all duplicates in an array
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

**Input**: [4,3,2,7,8,2,3,1]\
**Output**: [2,3]

**Input**: [1,1,2]\
**Output**: [1]

**Input**: [1]\
**Output**: []

[LC](https://leetcode.com/problems/find-all-duplicates-in-an-array/)

```cpp
  vector<int> findDuplicates(vector<int>& nums) {
      int i = 0;
      int n = nums.size();
      // cycle-sort
      // Making the arr in form [1 2 3 4 5 * * * ]
      while(i<nums.size()){
          if(nums[i]!=nums[nums[i]-1]){
              swap(nums[i], nums[nums[i]-1]);
          }else{
              ++i;
          }
      }
      
      vector<int> finalAns;
      for(int i=0; i<n; ++i){
          if(nums[i]!=i+1){
              finalAns.push_back(nums[i]);
          }
      }
      
      return finalAns;
  }
```
