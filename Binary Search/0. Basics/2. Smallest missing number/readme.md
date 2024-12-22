### When only non-negative elements are present

Given a sorted array of non-negative distinct integers, find the smallest missing non-negative element in it.

**Input:** [0, 1, 2, 6, 9, 11, 15]  
**Output:** 3

**Input:** [1, 2, 3, 4, 6, 9, 11, 15]  
**Output:** 0

**Input:** [0, 1, 2, 3, 4, 5, 6]  
**Output:** 7

[Link](https://www.techiedelight.com/?problem=SmallestMissingNumber)
[Link](https://www.geeksforgeeks.org/find-the-first-missing-number/)

    Algorithm: 
    We are given that the Array is sorted and contains only elements between 0 and n.
    
    Our best(complete) case becomes: 0 1 2 3 4 ... n
    every index has the value equal to the index itself.

    What shall we find?
    The first number which doesnt lie at its proper index.
    Simple. Proper index is the value of the number itself.

    Here the ans can be between 0 to n. Now we just start a binary search.

    Note: It is a good example where we should not see the
          input array as True or false. Here we see the entire
          number line from 0 to n as True or False. Or in other
          words, The entire range of answer as true or false.
    



<details>
<summary><span style="font-size:0.9em; font-family: 'consolas', monospace;">code</span>
</summary>


```cpp
int findSmallestMissingNumber(vector<int> const &nums)
{
    int ans = nums.size();
    int left = 0;
    int right = nums.size();
    while(left <= right){
        int mid = left + (right-left)/2;
        if(mid < nums.size()){
            if(mid == nums[mid]){
                left = mid+1;
            } else {
                ans = mid;
                right = mid-1;
            }
        } else {
            right = mid-1;
        }
    }
    return ans;
}
```
</details>

----
