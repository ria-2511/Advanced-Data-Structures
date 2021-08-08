// Optimized implementation of Bubble sort
#include <iostream>
using namespace std;

/*BUBBLE SORT
Time Complexity - Best - O(n) (when array is already sorted); Worst,Avg - O(n^2)
What Does it do?
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
'j' keeps on decreasing from n-- and the largest element gets placed at the last through the first iteration and then the second largest gets placed 
after the next iteration and so on. */

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
int i, j;
bool swapped;
for (i = 0; i < n-1; i++)
{
	swapped = false;
	for (j = 0; j < n-i-1; j++)
	{
		if (arr[j] > arr[j+1])
		{
		swap(&arr[j], &arr[j+1]);
		swapped = true;
		}
	}

	// IF no two elements were swapped by inner loop, then break
	if (swapped == false)
		break;
}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
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
	cout<<"Sorted Array Is - ";
	printArray(arr, n);
	return 0;
}
