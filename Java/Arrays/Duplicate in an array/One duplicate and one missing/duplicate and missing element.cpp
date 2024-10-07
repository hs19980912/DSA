Missing and Repeating in an Array in O(1) space

Given an unsorted array of size n. Array elements are in the range of 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. Find these two numbers.

Input: arr[] = {3, 1, 3}
Output: Missing = 2, Repeating = 3
Explanation: In the array, 2 is missing and 3 occurs twice 

Input: arr[] = {4, 3, 6, 2, 1, 1}
Output: Missing = 5, Repeating = 1

-----------------------------------------------------------
In-Place and Sum Formula

Calculate the sum of the first size natural numbers. Traverse the array. While traversing, use the absolute value of every element as an index and make the value at this index negative to mark it visited and subtract this value from the missing variable. If something is already marked negative, then this is the repeating element. After traversing, the ‘missing’ variable holds the value of the missing element.

void printTwoElements(vector<int>& arr)
{
    int n = arr.size();
    int missing = (n * (n + 1)) / 2; 
    cout << "Repeating ";

    for (int i = 0; i < n; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
        {
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            missing -= abs(arr[i]); // subtract unique elements
        }
        else
            cout << abs(arr[i]) << "\n";
    }

    cout << "Missing " << missing;
}

int main()
{
    vector<int> arr = { 7, 3, 4, 5, 5, 6, 2 };
    printTwoElements(arr);
}
