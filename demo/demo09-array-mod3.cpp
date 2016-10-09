/* demo09-array-mod1.cpp, written for cs101 */
// create an array of random numbers, print the array; 
// find the min and max, and their positions; loop till required

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
// find the min and max
  int min = 99, max = 0, low = -1, high = -1; 
  for (int vx = 0; vx < vn; vx++) {
	int elem = va[vx];
	if (elem < min) {min = elem; low = vx;}
	if (elem > max) {max = elem; high = vx;}
  }
  cout << "min is: " << min << " at index: " << low << endl;
  cout << "max is: " << max << " at index: " << high << endl;
cout << "Once more (y/n): "; cin >> flag;
if (flag != 'y') break;
}
return 0;
}
