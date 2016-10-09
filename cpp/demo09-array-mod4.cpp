/* demo09-array-mod1.cpp, written for cs101 */
// create an array of random numbers, print the array; 
// perform exchange sort; print the array; loop till flag.

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define MAX 9
int main() {
  int vn = MAX;
  int va[vn];
  char flag = 'n';
while (1) {
// generate a random number in [0..99] and insert it into array
  srand (time (NULL));
  for (int vx = 0; vx < vn; vx++) va[vx] = rand() % 100;
// print the array
  for (int vx = 0; vx < vn; vx++) cout << va[vx] << ", ";
  cout << endl;  

// outer loop for exchange sort
  for (int i = 0; i < vn; i++) {
	 cout << "Iteration:" << i << endl;
// inner loop to find min of remaining array and swap with index i
  int min = 99, low = -1; 
  for (int vx = i; vx < vn; vx++) {
	int elem = va[vx];
	if (elem < min) {min = elem; low = vx;}
  }
  cout << "The current min is: " << min << " at index: " << low << endl;
  
// swap min with current index i
  int tmp = va[i]; va[i] = min; va[low] = tmp;
}
// print the array
  for (int vx = 0; vx < vn; vx++) cout << va[vx] << ", ";
  cout << endl;  

cout << "Once more (y/n): "; cin >> flag;
if (flag != 'y') break;
}
return 0;
}
