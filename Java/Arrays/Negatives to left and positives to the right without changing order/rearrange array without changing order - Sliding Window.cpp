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

Here the window at any given point will only contain positive numbers.
So now at every iteration we have to add jth index to our window, 2 cases possible:
    case 1: arr[j] is positive
            Window is valid and simply move the j++ forward.
    case 2: arr[j] is negative
            eg: -1 -4 -3 -6 7 5 3 9 7 5 -2 8 7 5 -3 8 6 4
                            i            j
                        Make this to ↓
                -1 -4 -3 -6 -2 7 5 3 9 7 5 8 7 5 -3 8 6 4  
                             i           j

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