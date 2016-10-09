// demo22-linklist.cpp - cs101
// Tutorial problem on linked lists

#include <iostream>
using namespace std;

void eliminate_duplicates (int a[], int & n) { // eliminate duplicates from given array
  int i;
  int last_unique = 0; // Keep track of the end of the subarray of unique entries

// print-debug: Verify input array
  cout << "\nArray given for eliminate_duplicates is: \n";
  for (i = 0; i < n; ++i) cout << a[i] << " ";
  cout << endl;

// Eliminating duplicates
  for (i = 1; i < n; ++i) { // Start i at the second entry
// Determine whether a[i] is already present among the integers in a[0],...,a[last_unique]. 
	int j = 0; 
	while (j <= last_unique && a[i] != a[j]) ++j;
	 
	if (j > last_unique) a[++last_unique] = a[i]; //else ignore duplicate 
  }
	n = last_unique + 1; // Modify n to hold the number of distinct integers in the array 
}

struct node { // node structure for linked list version
	int num;
	node * next;
};

void show(node *head) { // print all the items of a linked list
	node * p = head;
	cout << "\nThe items in the list are: ";
	while (p != 0) {
		 cout <<  p->num << " "; 
		 p = p->next;
	}
	cout << endl;
}

int main () {
  int len = 10; // Number of integers in input
  int arr1[10] = {1, 1, 5, 2, 3, 4, 5, 3, 9, 9}; // Modify these values and recompile to test for different inputs
  int arr2[10] = {1, 1, 5, 2, 3, 4, 5, 3, 9, 9}; // keeping two copies, one for array version, one for linked list
  
// Call the array version
  eliminate_duplicates (arr1, len);
  cout << "Length of de-dup Array is: " << len << "\nDe-duplicated Array is: ";
  for (int i = 0; i < len; i++) cout << arr1[i] << " ";
  cout << endl;

// Linked list version, writing code in main itself instead of creating functions
	node *head, *p, *prev, *curr;

// Create the head node
	head = new node;
	head->num = arr2[0];
	head->next = NULL;
	
// Create the rest of the list by appending at the tail
	prev = head;
	for (int i=1; i<10; i++) {
		p = new node;
		p->num = arr2[i]; 
		p->next = NULL;
		prev->next = p;
		prev = p;
	}
	show(head); // Print the linked list to verify

// Eliminate duplicates
// We will use three pointers - curr for current node, prev for prev node, 
// p for scanning from head till curr to see if there is any duplicate

	prev = head;
	curr = head->next;
  do {
	bool dup = false; // Boolean variable is set to true when a duplicate is found
	p = head;
	while (p != curr) { // Scan the part of the list from head to curr
//	cout << "pvalue= " << p->num << "currVal= " << curr->num << "prevVal= " << prev->num << endl;
		if (curr->num == p->num) { dup = true; break; } // current entry already exists
		else p = p->next;
	}
	if (dup) { // delete the current node, advance the pointers
		cout << "deleting: " << curr->num << endl; //print for debugging
		prev->next = curr->next; 
		curr = curr->next;
	}
	else { // simply advance
	prev = curr;
	curr = curr->next;
	}
  } while (curr != NULL); // Repeat until entire list has been scanned

	show(head); // Print the linked list to verify
} //EOF
