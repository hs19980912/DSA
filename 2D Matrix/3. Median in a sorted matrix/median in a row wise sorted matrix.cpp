Median in a row-wise sorted Matrix

-> Follows the same logic of Kth smallest element in sorted matrix

Given a row-wise sorted matrix where the number of rows and columns is always odd, find the median of the matrix.

Examples:
Input: mat = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]
Output: 5, Explanation: Sorting matrix elements gives us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
Input: mat = [[1], [2], [3]]
Output: 2, Explanation: Sorting matrix elements gives us {1,2,3}. Hence, 2 is median
Input: mat = [[3], [5], [8]]
Output: 5, Explanation: Sorting matrix elements gives us {3,5,8}. Hence, 5 is median.
Constraints
1 <= mat[i][j] <= 2000

link: https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
=================================================================================================================

int n, m;

int findSmallerAndEqual(vector<vector<int>>& arr, int num){
    int total = 0;
    for(int i=0; i<n; ++i){
        int j = m-1;
        while(j>=0 && arr[i][j]>num){
            j--;
        }

        total+=j+1;
    }

    return total;
}

int median(vector<vector<int>> &mat) {
    n = mat.size();
    m = mat[0].size();
    int k = 1 + (n*n)/2;
    
    int l = 0;
    int r = 2000;
    int ans = -1;
    while(l<=r){
        int mid = l + (r-l)/2;
        int smallerOrEqual = findSmallerAndEqual(mat, mid);
        if(smallerOrEqual >= k){
            ans = mid;
            r = mid - 1;
        }else if(smallerOrEqual < k){
            l = mid + 1;
        }
    }

    return ans;
}