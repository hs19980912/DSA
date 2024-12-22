### Cycle Sort - smallest positive missing number in an unsorted array

Given an unsorted array arr[] with both positive and negative elements, the task is to find the smallest positive number missing from the array.\
Note: You can modify the original array.

**Input** = [2, -3, 4, 1, 1, 7]\
**Output**: 3

**Input** = [5, 3, 2, 5, 1]\
**Output**: 4

**Input** = [-8, 0, -1, -4, -3]\
**Output**: 1 

[LC](https://leetcode.com/problems/first-missing-positive/)
[gfg](https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/)

```
Note:   Ultimately we want our arr to look like:  [1 2 3 4 5 * * * * * ..]
        * can be any elements that do not fit in the sequence, eg 0, -1, 78, 19 etc.
        [1 2 3 4 5 0 -1 8 -9 12]
        [1 2 3 4 5 2 3 -1 9]
```
```
Algo:   Given an arr of length n
        while loop currently at i,
        if arr[i] lies in [1, n] AND index arr[i]-1(ie, its correct index) does not contain arr[i](ie. its correct value)
            swap(arr[i], arr[correct_index]) to transfer arr[i] at its correct index
        else:
            i++;
            
        when swap happens, do not increment i as the element which comes 
        in place after swapping has to be analyzed.

Execution:
        At the current index i:
        Condition:  The number must be greater than 0, and <= length of the arr.
                    AND,  A correct duplicate should not already be present at its place, then swap
                    if True:
                        swap the number -> once swapped, the swapped number must be analyzed again.
                        hence we do not increment i.
                    if False:
                        just increment i

A correct duplicate should not already be present at its place, then swap:
eg 1.
current arr = [3 2 3 4 8 2 7 1], current i = 0;
Shall we swap arr[i] with arr[2]?
NO, because a duplicate correct value "3" is already present at arr[2].

eg 2.
current arr = [3 2 3 4 1 2 7 8], current i = 4;
Shall we swap arr[i] i.e. arr[4] with its correct index?
YES, correct index of arr[i] is 0, currently arr[i] or arr[4] is 1, its correct index should be 0
and at 0th index 3 is present, which is the incorrect value. So swap arr[0] with arr[4].

eg 3.
current arr = [1 2 3 4 3 2 7 8], current i = 4;
Shall we swap?
NO, because a duplicate correct value "3" is already present at arr[2] (ie, its correct position)
                             
```

<details>
<summary><span style="font-size:0.9em; font-family: 'consolas', monospace;">code</span>
</summary>


```cpp
    int firstMissingPositive(vector<int>& nums) {
        // cycle-sort
        int i=0;
        while(i<nums.size()){
            if(nums[i]>0 && nums[i]<=nums.size() && nums[i]!=nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }else{
                ++i;
            }
        }
        
        i = 0;
        while(i<nums.size()){
            if(nums[i]!=i+1){
                return i+1;
            }
            ++i;
        }
        
        return i+1;
    }
```
</details>
