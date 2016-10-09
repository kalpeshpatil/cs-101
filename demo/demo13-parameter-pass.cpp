/* demo13-parameter-pass.cpp, written for cs101 */

#include <iostream>
#include <cmath>
using namespace std;

void fun1 (double *x, double *y) {
	cout << "Entering fun1, *x is: " << *x << " *y is: " << *y << endl;
	cout << "Entering fun1, x is: " << x << " y is: " << y << endl;
    if (*x > *y) {
      double z = *x;
      *x = *y; *y = z;
   }
   	cout << "Exiting fun1, *x is: " << *x << " *y is: " << *y << endl;
}

void fun2 (double &x, double &y) {
	cout << "Entering fun2, &x is: " << &x << " &y is: " << &y << endl;
	cout << "Entering fun2, x is: " << x << " y is: " << y << endl;
    if (x > y) {
      double z = x;
      x = y; y = z;
   }
   	cout << "Exiting fun2, x is: " << x << " y is: " << y << endl;
}

int main() {
	double x, y;
	
	cout << "Give the values of x and y: ";
	cin >> x >> y;
   	cout << "In main, before fun1, x is: " << x << " y is: " << y << endl;
   	cout << "In main, before fun1, &x is: " << &x << " &y is: " << &y << endl;
	fun1 (&y, &x);
   	cout << "In main, after fun1, x is: " << x << " y is: " << y << endl;
   	cout << "In main, after fun1, &x is: " << &x << " &y is: " << &y << endl;
   	
   	char flag;
   	cin >> flag;
   	
   	cout << "In main, before fun2, x is: " << x << " y is: " << y << endl;
   	cout << "In main, before fun2, &x is: " << &x << " &y is: " << &y << endl;
	fun2 (y, x);
   	cout << "In main, after fun2, x is: " << x << " y is: " << y << endl;
   	cout << "In main, after fun2, &x is: " << &x << " &y is: " << &y << endl;
   	
   	double z;
	cout << "Give the values of x, y and z: ";
	cin >> x >> y >> z;
   	cout << "In main, before multiple fun2, x is: " << x << " y is: " << y << " z is: " << z << endl;
   	fun2 (x, y); fun2 (y, z); fun2 (x, y);
   	cout << "In main, after multiple fun2, x is: " << x << " y is: " << y << " z is: " << z << endl;
   	
return 0;
}
