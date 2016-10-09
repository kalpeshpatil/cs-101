/* demo12-functions.cpp, written for cs101 */

#include <iostream>
#include <cmath>
using namespace std;

void fun1 (int x) {
	cout << "Entering fun1, x is: " << x << endl;
	x = 10; 
	cout << "Inside fun1, x is: " << x << endl;
}

void fun2 (int &x) {
	cout << "Entering fun2, x is: " << x << endl;
	x = 20; 
	cout << "Inside fun2, x is: " << x << endl;
}

void fun3 (int *x) {
	cout << "Entering fun3, *x is: " << *x << endl;
	*x = 30; 
	cout << "Inside fun3, x is: " << x << endl;
	cout << "Inside fun3, *x is: " << *x << endl;
}


int main() {
  int x = 5, *y; char flag;
  cout << "In main, before fun1, x is: " << x << endl;
  fun1 (x);
  cout << "In main, after fun1, x is: " << x << endl;
  
  cin >> flag; // Read a dummy char from input to pause the program here.
  
  cout << "In main, before fun2, x is: " << x << endl;
  fun2 (x);
  cout << "In main, after fun2, x is: " << x << endl;

  cin >> flag; // Read a dummy char from input to pause the program here.
  
  y = &x; *y = 15;
  cout << "In main, before fun3, x is: " << x << endl;
  fun3 (y);
  cout << "In main, after fun3, x is: " << x << endl;
  
return 0;
}
