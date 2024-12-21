```cpp
    int findMin(vector<int>& nums) {
        int ans = -1;
        int left = 0;
        int right = nums.size()-1;
        int last = nums.size()-1;
/*
        Condition: arr[mid]<=arr[last]  gives TRUE
        find: Find the FIRST TRUE
        
        4 5 6 7 1 2 3
        F F F F T T T
        
        1 2 3 4 5
        T T T T T
        
        2 3 4 5 1
        F F F F T
*/        
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]<=nums[last]){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        
        return nums[ans];
    }
```

[Question](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)