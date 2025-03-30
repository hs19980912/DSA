## Longest Nice Subarray

```
a | b | c ^ a 

This operation will unset the intersection of the set bits present in a|b|c and a.
```

[LC](https://leetcode.com/problems/longest-nice-subarray/)

<details>
<summary><span style="font-size:1em; font-family: 'consolas', monospace;">Hint 1</span>
</summary>

```
Use a Sliding Window Approach to go over the subarrays.
```
</details>

<details>
<summary><span style="font-size:1em; font-family: 'consolas', monospace;">Hint 2</span>
</summary>

```
Maintain a bitmask representing the bitwise OR of all elements. This mask must satisfy (mask & nextElement) == 0 before adding the next element.
```
</details>

<details>
<summary><span style="font-size:1em; font-family: 'consolas', monospace;">Hint 3</span>
</summary>

```
To remove elements from the left of the sliding window, update the mask by unsetting their bits (using XOR (or subtraction) works here since the subarray has no overlapping bits). So simply implement mask ^ left element
```
</details>


<details>
<summary><span style="font-size:1em; font-family: 'consolas', monospace;">Hint 4</span>
</summary>

```
If the next element causes a conflict, move the left pointer until the conflict is resolved ((mask & nextElement) == 0), then continue adding new elements.
```
</details>


<details>
<summary><span style="font-size:1em; font-family: 'consolas', monospace;">Code</span>
</summary>

```cpp
int longestNiceSubarray(vector<int>& nums) {
    int i = 0, maxAns = 0, curOR = 0;

    for (int j = 0; j < nums.size(); ++j) {
        while ((curOR & nums[j]) != 0) {
            curOR ^= nums[i];
            i++;
        }
        
        curOR |= nums[j];
        maxAns = max(maxAns, j - i + 1);
    }
    
    return maxAns;
}
```
</details>