1/* demo14-binSearch.cpp, written for cs101 */

#include <iostream>
using namespace std;

int sequentialSearch (int A[], int n, int x) { //Sequential search
	int pos = -1;
	cout << "In sequentialSearch, before loop: [x, pos] are: " << x << "," << pos << endl;
	for (int i = 0; i < n; i++) {
		cout << "In sequentialSearch, inside loop: [i, pos] are: " << i << "," << pos << endl; 
		if (x == A[i]) { pos = i; break; }
		if (x < A[i]) break; // Array is sorted in ascending order, so loop only if x > A[i]
	}
	cout << "In sequentialSearch, after loop: [x, pos] are: " << x << "," << pos << endl;
return pos;
}

int binSearch1 (int A[], int n, int x) { // Iterative version
// A is the array, n is the size of array, x is the number to find

   int low = 0, high = n-1, mid = -1;
   cout << "In binSearch1, before loop: [low, high, mid] are: " << low << "," << high << "," << mid << endl; 
   while (high > low) {
      mid = (low+high)/2;
      cout << "Inside loop: [low, high, mid] are: " << low << "," << high << "," << mid << endl; 
      if (A[mid] < x) low = mid + 1;
      else high = mid;
   }
   cout << "In binSearch1, after loop: [low, high, mid] are: " << low << "," << high << "," << mid << endl; 
   if (A[low] == x) return low; else return -1;
}

int binSearch2(int a[], int begin, int end, int item) { // Recursive version
//Using different variable names, for illustration

	int mid = (begin + end)/2;
	cout << "Entered binSearch2: [begin, end, mid] are: " << begin << "," << end << "," << mid << endl;
	if(begin==end) {  // Recursion termination condition
		cout << "Terminating recursion" << endl;
		if(a[begin] == item) return begin; else return -1;
	}
	else {
//	if(a[mid] == item) return mid;	//This is an optimization to reduce the number of calls
	if(a[mid] < item) binSearch2(a,mid+1,end,item); //Recursive search on upper half
	else binSearch2(a,begin,mid,item);                 // Recursive search on lower half
	}
}

int main () {
  int A[10] = {100172, 100245, 100391, 100486, 100638, 100853, 100965, 101195, 101273, 101679};
  int x, y;

  cout << "Give the value of x: "; cin >> x;
  cout << "Calling sequential search" << endl;
  y = sequentialSearch (A, 10, x);
  cout << x << " is at index: " << y << endl; // -1 indicates not found
  
  cout << "Give the value of x: "; cin >> x;
  cout << "Calling iterative binary search" << endl;
  y = binSearch1 (A, 10, x);
  cout << x << " is at index: " << y << endl; // -1 indicates not found
  
  cout << "Give the value of x: "; cin >> x;
  cout << "Calling recursive binary search" << endl;
  y = binSearch2 (A, 0, 9, x);
  cout << x << " is at index: " << y << endl; // -1 indicates not found

return 0;
}
