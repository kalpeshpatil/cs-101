/* demo14-sorting.cpp, written for cs101 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void swap (int *x, int *y) { // Function to swap values in locations pointed to by x and y
	int z = *x;
	*x = *y; 
	*y = z;
}

void generateArray (int A[], int n) { // Generates an unsorted array of random integers in [0..100], of size n
	srand (time (NULL)); // Initialize seed of random number generator
	for (int i = 0; i < n; i++) A[i] = rand() % 100;
}

void printArray (int A[], int n) { // Prints array A, size n
	cout << "[ ";
	for (int i = 0; i < n; i++) cout << A[i] << " ";
	cout << "]" << endl;
}

void copyArray (int A[], int B[], int n) { // Copies array A into array B, size n
	for (int i = 0; i < n; i++) B[i] = A[i];
}

void insertionSort (int A[], int n) { // Insertion Sort
	cout << "Performing Insertion Sort" << endl;
	printArray (A, n);
	for (int i=1; i<n; i++) { 
		for (int j=i; j>0; j--) {
			if (A[j] < A[j-1]) swap (A[j], A[j-1]); 
		} // Move current item to its right place in the sorted sub-array
		printArray (A, n);
	}	
	cout << "Completed Insertion Sort" << endl;
}

void selectionSort (int A[], int n) { // Selection Sort
	cout << "Performing Selection Sort" << endl;
	printArray (A, n);
	for (int i=0; i<n-1; i++) {
		int lowindex=i;
		for (int j=n-1; j>i; j--) { 
			if (A[j] < A[lowindex]) lowindex=j; // Find smallest item in unsorted sub-array
		}
		swap(A[i], A[lowindex]); // Swap item with first item of unsorted sub-array
		printArray (A, n);
	}
	cout << "Completed Selection Sort" << endl;
}

void bubbleSort (int A[], int n) { // Bubble Sort
	cout << "Performing Bubble Sort" << endl;
	printArray (A, n);
	for (int i=0; i<n-1; i++) {
		for (int j=n-1; j>i; j--) {
			if  (A[j] < A[j-1]) swap (A[j], A[j-1]); 
		} //Move smallest item to top of unsorted sub-array
		printArray (A, n);
	}
	cout << "Completed Bubble Sort" << endl;
}

void merge(int *a, int low, int high, int mid) { //Function used by mergeSort to merge sub-arrays
	cout << "Performing merge of sub-arrays: [ "; 
	for (int x = low; x <= mid; x++) cout << a[x] << " "; 
	cout << "] and [ ";
	for (int x = mid+1; x <= high; x++) cout << a[x] << " "; cout << "]" << endl;
//  Above 4 lines are not required for merge. They are only for you to follow the process
	
    int i, j, k, c[20]; //c is a temporary array used for storing the merged array
    i = low; // i runs on first sub-array, A[low to mid]
    j = mid + 1; // j runs on second sub-array, A[mid+1 to high]
    k = low; // k runs on merged array, C[low to high]

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) { //item from first sub-array goes to merged array
            c[k] = a[i];
            k++; i++;
        }
        else { //item from second sub-array goes to merged array
            c[k] = a[j];
            k++; j++;
        }
    }
    
// In case one of the sub-arrays is empty, one of the two while loops below will be executed, 
    while (i <= mid) { 
        c[k] = a[i];
        k++; i++;
    }
    while (j <= high) {
        c[k] = a[j];
        k++; j++;
    }
    
    for (i = low; i < k; i++) a[i] = c[i]; //copy C[] back into A[] for returning to caller
} // End of function merge

void mergeSort (int A[], int low, int high) { // Merge Sort
	cout << "Performing Merge Sort of sub-array: [ ";
	for (int x = low; x <= high; x++) cout << A[x] << " "; cout << "]" << endl;
//  Above 2 lines are not required for mergeSort. They are only for you to follow the process

    int mid;
    if (low < high) {
        mid=(low+high)/2;
        mergeSort(A,low,mid);
        mergeSort(A,mid+1,high);
        merge(A,low,high,mid);
    }
    
   	cout << "Completed Merge Sort of sub-array: [ "; // Print the array to follow the process
	for (int x = low; x <= high; x++) cout << A[x] << " "; cout << "]" << endl;
	char flag; cin >> flag; // Reading a dummy char to pause and study the output
// Above three lines are not required for mergeSort. They are only for you to follow the process
    return;
}

int main () {
  int n = 10;
  int A[n], B[n];
  char flag = 'y', choice = 'i';

  generateArray (A, n); // Generates an unsorted array of random integers in [0..100], of size n
  printArray(A, n);  // Prints the entries in A, upto index n-1
	
  while (flag != 'n') {
    copyArray(A, B, n); // Copy A into B, so that we can use the same input for different sorting algos
	cout <<"Which Sort? i for Insertion; s for Selection; b for Bubble; m for Merge: "; cin >> choice;
	switch (choice) { // This a compact way of writing multiple if-else statements
	case 'i' : 
      insertionSort (B, n);
      break;
	case 's' : 
      selectionSort (B, n);
      break;
	case 'b' : 
      bubbleSort (B, n);
      break;
	case 'm' : 
      mergeSort (B, 0, n-1);
      break;
   default :
      cout << "Unrecognized Input" << endl;
   }
   cout << "Sort again, Y/N?"; cin >> flag;
  }
}
