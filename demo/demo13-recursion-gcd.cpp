/* demo13-recursion-gcd.cpp, written for cs101 */

#include <iostream>
#include <cmath>
using namespace std;

int gcd1 (int m, int n) {
  int r;
  while(true) {
	cout << "Inside gcd, m is: " << m << " n is: " << n << endl;
    r = m % n;
    if (r == 0) break;
    m = n; n = r;
  }
  return n;
}

int gcd2 (int m, int n) {
   if (n == 0) return m;
   else {
	   cout << "calling gcd, m is: " << m << " n is: " << n << endl;
	   return gcd2 (n, m % n);
   }
}

int main () { 
  int x1, y1, z1, x2, y2, z2;
  
  cout << "Give the values of x1 and y1: ";
  cin >> x1 >> y1;
  z1 = gcd1 (x1, y1);
  cout << "The gcd is: " << z1 << endl;

  cout << "Give the values of x2 and y2: ";  
  cin >> x2 >> y2;
  z2 = gcd2 (x2, y2);
  cout << "The gcd is: " << z2 << endl;

return 0;
}
