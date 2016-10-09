/* demo09-array-mod1.cpp, written for cs101 */
// create an array of random numbers, print the array; find the min and max

#include <iostream>
#include <stdlib.h>
//#include <time.h>
using namespace std;

#define MAX 9
int main() {
  int vn = MAX;
  int va[vn];
// generate a random number in [0..99] and insert it into array
//  srand (time (NULL));  //Required to change the seed for each run
  for (int vx = 0; vx < vn; vx++) va[vx] = rand() % 100;
// print the array
  for (int vx = 0; vx < vn; vx++) cout << va[vx] << ", ";
  cout << endl;  
// find the min and max
  int min = 99, max = 0;  
  for (int vx = 0; vx < vn; vx++) {
	int elem = va[vx];
	min = (elem < min)? elem : min;
	max = (elem > max)? elem : max;
  }
  cout << "min is: " << min << " and max is: " << max << endl;
return 0;
}
