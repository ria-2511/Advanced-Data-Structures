// Recursive C++ program for insertion sort
#include <iostream>
using namespace std;

/*INSERTION SORT 
Time Complexity - best O(n) , Worst & Avg O(n^2) 
What Does it do?
The array is virtually split into a sorted and an unsorted part. 
Values from the unsorted part are picked and placed at the correct position in the sorted part.
Algorithm 
To sort an array of size n in ascending order: 
1: Iterate from arr[1] to arr[n] over the array. 
2: Compare the current element (key) to its predecessor. 
3: If the key element is smaller than its predecessor, compare it to the elements before. 
Move the greater elements one position up to make space for the swapped element.*/

void insertionSortRecursive(int arr[], int n)
{
	// Base case
	if (n <= 1)
		return;

	// Sort first n-1 elements
	insertionSortRecursive( arr, n-1 );

	// Insert last element at its correct position
	// in sorted array.
	int last = arr[n-1];
	int j = n-2;

	/* Move elements of arr[0..i-1], that are
	greater than key, to one position ahead
	of their current position */
	while (j >= 0 && arr[j] > last)
	{
		arr[j+1] = arr[j];
		j--;
	}
	arr[j+1] = last;
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
	for (int i=0; i < n; i++)
		cout << arr[i] <<" ";
}

/* Driver program to test insertion sort */
int main()
{
	int n ; 
	cin>>n;
	int arr[n];
	for(int i =0;i<n;i++)
	{
		cin>>arr[i];
	}
	insertionSortRecursive(arr, n);
	printArray(arr, n);

	return 0;
}
