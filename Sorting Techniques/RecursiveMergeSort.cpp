#include<iostream>
using namespace std;

/*ITERATIVE MERGE SORT
based on the DIVIDE and CONQUER technique
Time Complexity = nlog(n) - In all Best , worst and Avg Case*/

void merge(int *a,int s,int e)
{
    int mid = (s+e)/2;
    
    int i = s;
    int j = mid+1;
    int k = s;
    
    int temp[100];
    
    while(i<=mid && j<=e)
    {
        if(a[i] < a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++] = a[i++];
    }
    while(j<=e)
    {
        temp[k++]  = a[j++];
    }
    
    //We need to copy all element to original arrays
    for(int i=s;i<=e;i++)
    {
        a[i] = temp[i];
    }
    
    
}

void mergeSort(int a[],int s,int e)
{
    //Base case - 1 or 0 elements
    // that is array is empty 
    if(s>=e)
    {
        return;
    }
    
    //Follow 3 steps
    //1. Divide
    int mid = (s+e)/2;
    
    //Recursively the arrays - s,mid and mid+1,e
    mergeSort(a,s,mid); // first half of the array , we keep on dividing it until only one cell each is there
    mergeSort(a,mid+1,e); // second half of the array 
    
    //Merge the two parts
    merge(a,s,e);

}
    
int main()
{

	int a[100];
	int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	// apply merge sort on array 'a' from the index 0 to n-1
	mergeSort(a,0,n-1);
	
	for(int i=0;i<n;i++)
	{
	    cout<<a[i]<<" , ";
	}

}
