#include <iostream>
using namespace std;
// NOTE - Not working with a manual input taking 

/*COUNTING SORT 
Time Complexity - O(n+k) where n is the number of elements in input array and k is the range of input. 
what does it do?
Counting sort is a sorting technique based on keys between a specific range. 
It works by counting the number of objects having distinct key values (kind of hashing). 
Then doing some arithmetic to calculate the position of each object in the output sequence.
*/
void countSort(int arr[], int n) {
  
  int arr1[10];
  int count_arr[10];
  int x = arr[0];

  for (int i = 1; i < n; i++) {
    if (arr[i] > x)
      x = arr[i];
  }

  for (int i = 0; i <= x; ++i) {
    count_arr[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    count_arr[arr[i]]++;
  }

  for (int i = 1; i <= x; i++) {
    count_arr[i] += count_arr[i - 1];
  }


  for (int i = n - 1; i >= 0; i--) {
    arr1[count_arr[arr[i]] - 1] = arr[i];
    count_arr[arr[i]]--;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = arr1[i];
  }
}

void display(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
   int arr[] = {4, 2, 2, 8, 3, 3, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  countSort(arr, n);
  display(arr, n);
}
