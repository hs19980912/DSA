74. Search a 2D Matrix

You are given an m x n integer matrix matrix with the following two properties:
1. Each row is sorted in non-decreasing order.
2. The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.


------------------------------------------------------------------------------------

OBSERVATIONS:
By the above 2 properties, matrix will also become column sorted in nature.


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int ans = -1;
    int l = 0;
    int r = n-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(matrix[mid][0] == target){
            return true;
        }else if(matrix[mid][0] < target){
            l = mid + 1;
            ans = mid;
        }else{  
            // when matrix[mid][0] > target
            r = mid-1;
        }
    }
    
    if(ans == -1){
        return false;
    }

    int row = ans;
    ans = -1;
    l = 0;
    r = m-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(matrix[row][mid] == target){
            return true;
        }else if(matrix[row][mid]<target){
            l = mid+1;
        }else{
            // when matrix[row][mid] > target
            r = mid-1;
        }
    }

    return false;
}
