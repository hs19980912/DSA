# 🌴 DSA Patterns
   <details>
     <summary>Subarray sum problems - generally involves <b>prefix sum</b></summary>

     • Find the number of subarrays with a sum equal to k.  
     • Find the longest subarray with a sum equal to k.  
     • Check if a subarray with a given sum exists.  
     • Count subarrays with a sum divisible by k.

   </details>


---
# 🌴 Notes

### initialize 2D vector after declaration
```cpp
vector<vector<int>> dp;
dp.resize(5, vector<int>(10, -4));
```
--------------------------------
### TAKE ENTIRE string with spaces as input
```cpp   
string s;
getline(cin, s);
```    
TAKE ENTIRE string with spaces as input.
aabdfjs dfjlkjs fjdsjhf  poqiopjf  f  fd  dssdfsd

--------------------------------
### priority_queue
```cpp
priority_queue<int> pq; // max priority-Queue
priority_queue<int, vector<int>, greater<int>> pq; // min priority queue
```
--------------------------------
### Sorting
```cpp
int arr[] = {4, 6, 2, 7, 9};
sort(arr, arr+5); // ascending
sort(arr, arr+5, greater<int>());  // Descending 
```
### *IMPORTANT*
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
### sorting 2 vectors keeping the index mapping
used in Activity selection, Meeting Room
#### method 1 - using lamda
```cpp
void sortTwoArrays(vector<int>& A, vector<int>& B) {
    int n = ;
    // Create a vector of indices
    vector<int> indices(n);
    
    // Initialize the indices to {0, 1, 2, ..., n-1}
    for (int i = 0; i < n; ++i) {
        indices[i] = i;
    }

    sort(indices.begin(), indices.end(), [&A](int i, int j) {
        return A[i] < A[j];
    });

    // Create copies of A and B to hold the sorted values
    vector<int> sortedA(n), sortedB(n);

    for (int i = 0; i < n; ++i) {
        sortedA[i] = A[indices[i]];
        sortedB[i] = B[indices[i]];
    }

    A = sortedA;
    B = sortedB;
}
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
