Arranging the array
You are given an array of size N. Rearrange the given array in-place such that all the negative numbers occur before all non-negative numbers.
(Maintain the order of all -ve and non-negative numbers as given in the original array).

Example 1:

Input:
N = 4
Arr[] = {-3, 3, -2, 2}
Output:
-3 -2 3 2
Explanation:
In the given array, negative numbers
are -3, -2 and non-negative numbers are 3, 2. 

Example 2:

Input:
N = 4
Arr[] = {-3, 1, 0, -2}
Output:
-3 -2 1 0
Explanation:
In the given array, negative numbers
are -3, -2 and non-negative numbers are 1, 0.
==============================================================================================

class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            // Your code goes here
            int l = 0;
            int r = 0;
            while(r<n){
                if(arr[r]>=0){
                    r+=1;
                }else{
                    int k = r;
                    while(k>l){
                        swap(arr[k-1], arr[k]);
                        k-=1;
                    }
                    l+=1;
                    r+=1;
                }
            }
            
        }
};