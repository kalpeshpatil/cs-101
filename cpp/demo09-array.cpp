/* demo09-array.cpp, written for cs101 */
// create and print an array; predict the output activity

#include <iostream>
using namespace std;

int main() {
  int vn = 9;
  int va[vn];	// Declaration of the array
  for (int vx = 0; vx < vn; vx++) {  //Loop for creating the array
    va[vx] = vx  * (vn - 1 - vx); //Given formula for generating array items
  }
// Do hand-execution code-tracing of above loop; verify with answers below
  for (int vx = 0; vx < vn; vx++) {
    cout << va[vx] << ", ";
    char a; // variable used for pausing the print after each item
    cin >> a; // read char input and discard it
  }
cout << endl;
return 0;
}
