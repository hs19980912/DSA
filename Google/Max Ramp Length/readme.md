---
comments: true
edit_url: https://github.com/doocs/leetcode/edit/main/solution/0900-0999/0962.Maximum%20Width%20Ramp/README_EN.md
tags:
    - Stack
    - Array
    - Two Pointers
    - Monotonic Stack
---

<!-- problem:start -->

# [962. Maximum Width Ramp](https://leetcode.com/problems/maximum-width-ramp)
> Farthest greater number
## Description 1:

<!-- description:start -->

<p>A <strong>ramp</strong> in an integer array <code>nums</code> is a pair <code>(i, j)</code> for which <code>i &lt; j</code> and <code>nums[i] &lt;= nums[j]</code>. The <strong>width</strong> of such a ramp is <code>j - i</code>.</p>

<p>Given an integer array <code>nums</code>, return <em>the maximum width of a <strong>ramp</strong> in </em><code>nums</code>. If there is no <strong>ramp</strong> in <code>nums</code>, return <code>0</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [6,0,8,2,1,5]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [9,8,1,0,1,9,4,0,4,1]
<strong>Output:</strong> 7
<strong>Explanation:</strong> The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.
</pre>

<p>&nbsp;</p>

## Description 2:

Find maximum length of a substring of a string with first charachter lexicographically smaller than its last charachter.

assume string length 10^5 char long, assume 26 small case english letters in string

solve it in linear time.

<pre>
input : "dbabcb"
output : 4
</pre>

[Link](https://leetcode.com/discuss/post/4834179/google-l4-onsite-by-anonymous_user-eqlw/)

<!-- description:end -->
<p>&nbsp;</p>

## Solutions

<!-- solution:start -->

### Solution 1: Sliding Window

#### C++

```cpp
int maxWidthRamp(vector<int>& nums) {
    int n = nums.size();
    vector<int> maxFromRight(n);
    maxFromRight[n-1] = nums[n-1];

    for(int i=n-2; i>=0; --i){
        maxFromRight[i] = max(maxFromRight[i+1], nums[i]);
    }

    int finalAns = 0;

    int i=0;
    int j=0;

    while(i<n && j<n){
        while(j<n && nums[i]<=maxFromRight[j]){
            j+=1;
        }
        finalAns = max(finalAns, j-1-i);
        i+=1;
    }

    return finalAns;
}
```
>Maximum Width Ramp - Leetcode 962 - NeetCode

### Solution 2: Monotonic stack

#### C++

```cpp
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            if (stk.empty() || nums[stk.top()] > nums[i]) stk.push(i);
        }
        int ans = 0;
        for (int i = n - 1; i; --i) {
            while (!stk.empty() && nums[stk.top()] <= nums[i]) {
                ans = max(ans, i - stk.top());
                stk.pop();
            }
            if (stk.empty()) break;
        }
        return ans;
    }
};
```

