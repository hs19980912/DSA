# DSA

### initialize 2D vector after declaration
```
vector<vector<int>> dp;
dp.resize(5, vector<int>(10, -4));
```
--------------------------------
### TAKE ENTIRE string with spaces as input
```   
string s;
getline(cin, s);
```    
TAKE ENTIRE string with spaces as input.
aabdfjs dfjlkjs fjdsjhf  poqiopjf  f  fd  dssdfsd

--------------------------------
### priority_queue
```
priority_queue<int> pq; // max priority-Queue
priority_queue<int, vector<int>, greater<int>> pq; // min priority queue
```
#### Sorting
```
int arr[] = {4, 6, 2, 7, 9};
sort(arr, arr+5); // ascending
sort(arr, arr+5, greater<int>());  // Descending 
```
### *** IMPORTANT ***
When using long long int,
```
use sort(arr, arr+5, greater<long long int>());
```
--------------------------------
### sorting vector using sort() - Using sort(begin(nums), end(nums))
```cpp
vector<int> nums(10);
...
sort(begin(nums), end(nums)); // works
sort(nums.begin(),nums.end()); // also works

Then replace vector:

int nums[10];
...
sort(begin(nums), end(nums)); // still works
sort(nums.begin(),nums.end()); // doesn't compile anymore. Built-in arrays don't have `.begin()` and `end()` methods.
```

--------------------------------
### Assert in C++

#include <assert.h>
assert(x==7);

--------------------------------
#ifndef ANIMAL
#define ANIMAL

class Animal {
    // Code
};

#endif
