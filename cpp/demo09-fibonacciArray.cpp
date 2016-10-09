/* demo09-fibonacciArray.cpp, written for cs101 */

#include <iostream>
using namespace std;

#define MAX 100
int main() {
long n; char flag;
float numArray [MAX];
	numArray[0] = 1; numArray[1] = 1;
	
// Generating the first 100 (MAX) fibonacci numbers 
	for (int i = 2; i < MAX; i++) numArray[i] = numArray[i-1] + numArray[i-2];

	while (1) {
		cout << "Give the value of n (should be less than 10^10): "; cin >> n;
// for larger n, change type of n from long to float

// Printing values from numArray from 1 till n
		cout << "The fibonacci number upto " << n << " are:\n";
		for (int i = 0; numArray[i] < n; i++) cout << numArray[i] << ",";
		
		cout << "\nOnce more (y/n): "; cin >> flag;
		if (flag == 'n') break;
	}
return 0;
}
