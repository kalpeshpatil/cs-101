/* demo12-gcd-lcm.cpp, written for cs101 */

#include <iostream>
#include <cmath>
using namespace std;

int gcd (int Large, int Small); //Function declaration

int lcm (int m, int n) { return m*n/gcd(m,n); } 

int gcd (int Large, int Small) {  // Function definition
  int Remainder;
  while(true) {
	  cout << "Inside gcd, m is: " << Large << " n is: " << Small << endl;
    Remainder = Large % Small;
    if (Remainder == 0) break;
    Large = Small;
    Small = Remainder;
  }
  return Small;
}

int main () { 
  int x1, y1, z1, x2, y2, z2;
  
  cout << "Give the values of x1 and y1: ";
  cin >> x1 >> y1;
  z1 = gcd (x1, y1);
  cout << "The gcd is: " << z1 << endl;

  cout << "Give the values of x2 and y2: ";  
  cin >> x2 >> y2;
  z2 = gcd (x2, y2);
  cout << "The gcd is: " << z2 << endl;
  
  cout << endl << "Finding lcm of " << z1 << " and " << z2 << endl;
  cout << "The lcm is: " << lcm(z1, z2) << endl;

return 0;
}
