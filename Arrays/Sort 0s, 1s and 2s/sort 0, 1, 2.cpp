Sort 0s, 1s and 2s
Given an array arr containing only 0s, 1s, and 2s. Sort the array in ascending order.

Examples:
Input: arr[]= [0, 2, 1, 2, 0]
Output: 0 0 1 2 2
Explanation: 0s 1s and 2s are segregated into ascending order.

Input: arr[] = [0, 1, 0]
Output: 0 0 1
Explanation: 0s 1s and 2s are segregated into ascending order.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

=====================================================================================

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int i=0;            // Everyting before i contains 0's
        int j=0;            // Everything bw [i ... j-1] contains 1's
        int k=arr.size()-1; // Everything after this contains 2's
                            // current analyze j index        

        while(j<=k){
            if(arr[j]==1){
                ++j;
                continue;
            }
            else if(arr[j]==0){
                swap(arr[i], arr[j]);
                ++j;
                ++i;
            }else{ // if(arr[k] == 2)
                swap(arr[j], arr[k]);
                k--;
            }
        }
    }
};