Given an array of size n containing equal number of odd and even numbers. The problem is to arrange the numbers in such a way that all the even numbers get the even index and odd numbers get the odd index. Required auxiliary space is O(1).
Examples : 

Input : arr[] = {3, 6, 12, 1, 5, 8}
Output : 6 3 12 1 8 5 

Input : arr[] = {10, 9, 7, 18, 13, 19, 4, 20, 21, 14}
Output : 10 9 18 7 20 19 4 13 14 21 

==================================================================

void arrangeOddAndEven(int arr[], int n)
{
   int oddInd = 1;
    int evenInd = 0;
    while (true)
    {
        while (evenInd < n && arr[evenInd] % 2 == 0)
            evenInd += 2;
             
        while (oddInd < n && arr[oddInd] % 2 == 1)
            oddInd += 2;
             
        if (evenInd < n && oddInd < n)
            swap (arr[evenInd], arr[oddInd]);
             
        else
            break;
    }
}

==================================================================

vector<int> arrange_array(vector<int> arr) {
    int i = 0;
    int j = 1;
    int n = arr.size();
    while (i < n && j < n) {
        if (arr[i] % 2 != 0 && arr[j] % 2 == 0) {
            swap(arr[i], arr[j]);
            i += 2;
            j += 2;
        }
        else {
            if (arr[i] % 2 == 0) {
                i += 2;
            }
            if (arr[j] % 2 != 0) {
                j += 2;
            }
        }
    }
    return arr;
}
 