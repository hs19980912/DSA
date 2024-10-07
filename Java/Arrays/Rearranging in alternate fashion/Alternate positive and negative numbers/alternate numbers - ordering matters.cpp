Alternate positive and negative numbers
Given an unsorted array arr containing both positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
Note: Array should start with a positive number and 0 (zero) should be considered a positive element.

Examples:

Input: arr[] = [9, 4, -2, -1, 5, 0, -5, -3, 2]
Output: 9 -2 4 -1 5 -5 0 -3 2
Explanation: Positive elements : [9,4,5,0,2]
Negative elements : [-2,-1,-5,-3]
As we need to maintain the relative order of postive elements and negative elements we will pick each element from the positive and negative and will store them. If any of the positive and negative numbersare completed. we will continue with the remaining signed elements.
The output is 9,-2,4,-1,5,-5,0,-3,2.

Input: arr[] = [-5, -2, 5, 2, 4, 7, 1, 8, 0, -8]
Output: 5 -5 2 -2 4 -8 7 1 8 0
Explanation : Positive elements : [5,2,4,7,1,8,0]
Negative elements : [-5,-2,-8]
The output is 5, -5, 2, -2, 4, -8, 7, 1, 8, 0.

====================================================================================

Naïve Approach: To solve the problem follow the below idea:

The problem can be easily solved if O(n) extra space is allowed.
We can store the positive values and negative values in two separate data structures.
We will start filling the original array with alternating negative and positive values in the same order 
in which it appears in the original array.

class Solution {
  public:

    void rearrange(vector<int> &arr) {
        vector<int> positive;
        vector<int> negative;
        for(int i=0; i<arr.size(); ++i){
            if(arr[i]>=0){
                positive.push_back(arr[i]);
            }else{
                negative.push_back(arr[i]);
            }
        }
        
        int i=0;
        while(i<positive.size() && i<negative.size()){
            arr[2*i] = positive[i];
            arr[2*i + 1] = negative[i];
            ++i;
        }
        
        if(i==negative.size()){
            int index = 2*i;
            while(i<positive.size()){
                arr[index] = positive[i];
                ++i;
                ++index;
            }
        }
        
        if(i==positive.size()){
            int index = 2*i;
            while(i<negative.size()){
                arr[index] = negative[i];
                ++i;
                ++index;
            }
        }
        
    }
};

=========================================================================================

Optimal Approach: To solve the problem in O(1) Auxiliary space follow the below idea:

The idea is to process the array from left to right. While processing, find the first out-of-place element in the remaining unprocessed array. An element is out of place if it is negative and at odd index (0-based index), or if it is positive and at even index (0-based index). Once we find an out-of-place element, we find the first element after it with an opposite sign. We right rotate the subarray between these two elements (including these two).

Illustration:

Let the array be arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 }

First iteration: 

{ -5, '-2', 5, 2, 4, 7, 1, 8, 0, -8 } , -2 appears on odd index position and is out of place.
We will look for the first element that appears with an opposite sign
{ -5, '-2', '5', 2, 4, 7, 1, 8, 0, -8 } => perform rotation of subarray between this two elements
{ -5, 5, -2, 2, 4, 7, 1, 8, 0, -8 }
Second iteration: 

{ -5, 5, -2, 2, '4', 7, 1, 8, 0, -8 } , 4 is out of place.
{ -5, 5, -2, 2, '4', 7, 1, 8, 0, '-8' } => -8 is of different sign 
{ -5, 5, -2, 2, -8, 4, 7, 1, 8, 0 } => after performing right rotation between 4 to -8
resultant array arr[] = { -5, 5, -2, 2, -8, 4, 7, 1, 8, 0 }

Follow the steps to solve the problem:

Maintain a variable to mark if the element is in its correct position or not. Let the variable be outofplace. Initially, it is -1.
We will iterate over the array.
If outofplace is -1, we will check if the current index is out of place.
If the current index is out of place we will update the outofplace with the index value.
Else we will keep the value as it is.
If the outofplace is not -1, we will search for the next index which has a different sign than that of the value that is present in outofplace position.
Now we will pass this two positions to right rotate our array.
Update the value of outofplace by 2 unit (because previously valid elements will now become the out-of-place elements).


#include <iostream>
#include <vector>
using namespace std;

// Function to right rotate elements between outofplace and current
void right_rotate(vector<int>& arr, int outofplace, int current) {
    int temp = arr[current];
    for (int i = current; i > outofplace; --i) {
        arr[i] = arr[i - 1];
    }
    arr[outofplace] = temp;
}

// Function to rearrange the array
void rearrange(vector<int>& arr) {
    int n = arr.size();
    int outofplace = -1;

    for (int index = 0; index < n; ++index) {
        // Check if the element is out of place
        if (outofplace == -1) {
            // We are looking for the first out-of-place element
            if ((arr[index] >= 0 && index % 2 == 1) || (arr[index] < 0 && index % 2 == 0)) {
                outofplace = index;
            }
        } else {
            // We found an out-of-place element, now look for the next element to fix it
            if ((arr[index] >= 0 && arr[outofplace] < 0) || (arr[index] < 0 && arr[outofplace] >= 0)) {
                // We need to rotate the elements between outofplace and the current index
                right_rotate(arr, outofplace, index);

                // Update outofplace index
                // If the gap between current and outofplace is 2 or more, the next element will be out of place
                if (index - outofplace >= 2) {
                    outofplace += 2;
                } else {
                    outofplace = -1;
                }
            }
        }
    }
}

// Example usage
int main() {
    vector<int> arr = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    
    rearrange(arr);

    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
