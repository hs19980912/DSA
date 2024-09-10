Rearrange array in alternating positive & negative items with O(1) extra space

If we are allowed to change order of appearance, we can solve this problem in O(n) time and O(1) space.
The idea is to process the array and shift all negative values to the end in O(n) time. After all negative values are shifted to the end, we can easily rearrange array in alternating positive & negative items. We basically swap next positive element at even position from next negative element in this step. 

#include <bits/stdc++.h>
using namespace std;


void rearrange(int arr[], int n)
{
	int i = 0, j = n-1;

	// shift all negative values to the end
	while (i < j) {
		while (i <= n - 1 and arr[i] > 0)
			i += 1;
		while (j >= 0 and arr[j] < 0)
			j -= 1;
		if (i < j )
			swap(arr[i], arr[j]);
	}

	// i has index of leftmost
	// negative element
	if (i == 0 || i == n)
		return;

	// start with first positive
	// element at index 0

	// Rearrange array in alternating
	// positive &
	// negative items
	int k = 0;
	while (k < n && i < n ) {
		// swap next positive
		// element at even position
		// from next negative element.
		swap(arr[k], arr[i]);
		i = i + 1;
		k = k + 2;
	}
}

// Utility function to print an array
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
	int arr[] = { 2, 3, -4, -1, 6, -9 };

	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, n);

	rearrange(arr, n);

	cout << "Rearranged array is \n";
	printArray(arr, n);

	return 0;
}
