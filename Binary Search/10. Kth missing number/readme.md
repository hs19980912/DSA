### Kth missing positive number

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.

**Input**: [2,3,4,7,11], k = 5   
**Output**: 9  
**Explanation**: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

**Input**: [1,2,3,4], k = 2  
**Output**: 6  
**Explanation**: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

[LC 1539](https://leetcode.com/problems/kth-missing-positive-number/)

```
Note: Here we do simple binary search hopping on the input array.
```
```
Algorithm: 
input: [2 3 4 7 11]
        0 1 2 3 4

There are some missing numbers, lets expand the array
1 2 3 4 5 6 7 8 9 10 11 12 13
  ‾ ‾ ‾     ‾        ‾
Standing at any index in the original arr, we can say that
"at this index, we have missed n numbers behind"
eg, at index 0, we have missed 1 numbers
    at index 1, we have missed 1 numbers
    at index 2, we have missed 1 numbers
    at index 3, we have missed 3 numbers
    at index 4, we have missed 6 numbers.

So during binary search hoping, our abstraction becomes:
at the m index, how many numbers we have missed?
if it is < than required k, then the element at which we are currently standing, "element + missing" can be a prospective number, update ans and move to the right.
if > the required k, means we have already left the prospective number behind, and we cannot get any propsective ans from here, move to the left.

Like all other binary search problems, we have to find the best possible answer, that will be our answer.
eg, at index 0, we have missed 1 numbers, so 2 + 4 = 6 can be a possible ans, improve it.
    at index 1, we have missed 1 numbers, so 3 + 3 = 6 can be a possible ans, improve it.
    at index 2, we have missed 1 numbers, so 4 + 2 = 6 can be a possible ans, improve it.
    at index 3, we have missed 3 numbers, so 7 + 2 = 9 can be a possible ans, improve it.
    at index 4, we have missed 6 numbers, No, we have already missed 6 numbers, no ans possible.
```

```cpp
    int findKthPositive(vector<int>& arr, int k) {
        int ans = k;    // "ans" should at least be k
        int l = 0;
        int r = arr.size()-1;

        while(l<=r){
            int mid = l+(r-l)/2;
            int eleMissed = arr[mid]-(mid+1);
            if(eleMissed<k){
                ans = arr[mid]+(k-eleMissed);
                // go the right, can get better answer
                l = mid+1;
            }else{
                // eleMissed > k
                r = mid-1;
            }
        }

        return ans;
    }
```
