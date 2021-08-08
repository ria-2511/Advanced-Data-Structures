// C/C++ program for recursive implementation
// of Bubble sort
#include <bits/stdc++.h>
using namespace std;

/*BUBBLE SORT
Time Complexity - Best - O(n) (when array is already sorted); Worst,Avg - O(n^2)
What Does it do?
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
'j' keeps on decreasing from n-- and the largest element gets placed at the last through the first iteration and then the second largest gets placed 
after the next iteration and so on. */

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
	// Base case
	if (n == 1)
		return;

	// One pass of bubble sort. After
	// this pass, the largest element
	// is moved (or bubbled) to end.
	for (int i=0; i<n-1; i++)
		if (arr[i] > arr[i+1])
			swap(arr[i], arr[i+1]);

	// Largest element is fixed,
	// recur for remaining array
	bubbleSort(arr, n-1);
}

/* Function to print an array */
void printArray(int arr[], int n)
{
	for (int i=0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{
	int n ; 
	cin>>n;
	int arr[n];
	for(int i =0;i<n;i++)
	{
		cin>>arr[i];
	}
	bubbleSort(arr, n);
	printf("Sorted array : \n");
	printArray(arr, n);
	return 0;
}
