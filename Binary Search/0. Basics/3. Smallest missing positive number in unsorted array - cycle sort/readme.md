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
                    AND,  The number must be different than the correct number for that index.
                    if True:
                        swap the number -> once swapped, the swapped number must be analyzed again.
                        hence we do not increment i.
                    if False:
                        just increment i
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
