/* demo09-array-mod1.cpp, written for cs101 */
// create and print an array; also find the min and max

#include <iostream>
using namespace std;

int main() {
  int vn = 9;
  int va[vn];
  for (int vx = 0; vx < vn; vx++) {
    va[vx] = vx  * (vn - 1 - vx);
  }

  for (int vx = 0; vx < vn; vx++) {
    cout << va[vx] << ", ";
  }
  cout << endl;
  
  int min = 99, max = 0;  
  for (int vx = 0; vx < vn; vx++) {
	int elem = va[vx];
	min = (elem < min)? elem : min;
	max = (elem > max)? elem : max;
  }
  cout << "min is : " << min << " and max is : " << max << endl;
return 0;
}
