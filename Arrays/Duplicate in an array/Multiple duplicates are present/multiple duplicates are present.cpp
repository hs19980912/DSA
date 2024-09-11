Duplicates in an array in O(n) and by using O(1) extra space

Input: n = 7 , array = {1, 2, 3, 1, 3, 6, 6}
Output: 1, 3 and 6.
Explanation: Duplicate element in the array are 1 , 3 and 6

Input: n = 6, array = {5, 3, 1, 3, 5, 5}
Output: 3 and 5.
Explanation: Duplicate element in  the array are 3 and 5

----------------------------------------------------------------------
Approach: The basic idea is based on the hash map to solve the problem. But there is a catch, the numbers in the array are from 0 to n-1, and the input array has length n. So, the input array itself can be used as a hash map. While traversing the array, if an element a is encountered then increase the value of a%n‘th element by n. The frequency can be retrieved by dividing the a%n‘th element by n. 

a%n will always return the original value which was present at arr[index]

Algorithm:  
1. Traverse the given array from start to end.
2. For every element in the array increment the arr[i]%n‘th element by n.
3. Now traverse the array again and print all those indices i for which arr[i]/n is greater than 1. Which guarantees that the number n has been added to that index.

assume n = 10
original: {1, 2,  3,  1,  3, 6, 6}
   index:  0  1   2   3   4  5  6 

final:    {1, 22, 13, 21, 3, 6, 26} 
   index:  0  1   2   3   4  5  6

index 1, 3, 6 are duplicates because arr[i]%10 is >= 2 

----------------------------------------------------------------------

void printRepeating(int arr[], int n)
{
    // First check all the values that are
    // present in an array then go to that
    // values as indexes and increment by
    // the size of array
    for (int i = 0; i < n; i++) 
    {
        int index = arr[i] % n;
        arr[index] += n;
    }

    // Now check which value exists more
    // than once by dividing with the size
    // of array
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] / n) >= 2)
            cout << i << " ";
    }
}

// Driver code
int main()
{
    int arr[] = { 1, 6, 3, 1, 3, 6, 6 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "The repeating elements are: \n";

    // Function call
    printRepeating(arr, arr_size);
    return 0;
}
