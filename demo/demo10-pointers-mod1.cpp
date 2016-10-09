
/* demo10-pointers-mod1.cpp, written for cs101 */

#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
char x[3] = {'a', 'b', 'c'};
char* y = x; //same as saying y = &x[0];
char flag;

cout << *y << endl;
cin >> flag;
cout << *(y+1) << endl;
cout << *y + 1 << endl;
cin >> flag;
cout << *(y+=2) << endl;
// cout << *(--y) << endl;
cout << *(y--) << endl;
cin >> flag;
//cout << *(y++) << endl;
//cout << *y++ << endl;
cout << *(y+=1)<< endl;
cin >> flag;
cout << *y << endl;
cin >> flag;
cout << *(y+1) << endl;
cin >> flag;

int m[3] = {10, 20, 30};
int* p = &m[0];  //p = m;

cout << *p << endl;
// cout << *(p++) << *p << *(p+=1) << endl; // warning: operation on 'p' may be undefined
cout << *(p++); cout << *p; cout << *(p+=1) << endl;
return 0;
}
