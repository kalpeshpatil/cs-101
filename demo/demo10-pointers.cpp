/* demo10-pointers-mod1.cpp, written for cs101 */

#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
int a = 1, b = 2, c = 3;
int* p; int* q;
char flag = 'n';

p = &a; q = &b;
cin >> flag; // This statement is only to make the program pause here.
cout << "a is: " << a << " b is: " << b << " c is: " << c << endl;
cout << "p is: " << p << " *p is: " << *p << endl;
cout << "q is: " << q << " *q is: " << *q << endl;
cin >> flag; // This statement is only to make the program pause here.

c = *p; 
cout << "a is: " << a << " b is: " << b << " c is: " << c << endl;
cout << "p is: " << p << " *p is: " << *p << endl;
cout << "q is: " << q << " *q is: " << *q << endl;
cin >> flag; // This statement is only to make the program pause here.

p = q;
cout << "a is: " << a << " b is: " << b << " c is: " << c << endl;
cout << "p is: " << p << " *p is: " << *p << endl;
cout << "q is: " << q << " *q is: " << *q << endl;
cin >> flag; // This statement is only to make the program pause here.

*p = 13;
cout << "a is: " << a << " b is: " << b << " c is: " << c << endl;
cout << "p is: " << p << " *p is: " << *p << endl;
cout << "q is: " << q << " *q is: " << *q << endl;
return 0;
}
