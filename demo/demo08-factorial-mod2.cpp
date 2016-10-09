/* demo08-factorial-mod2.cpp, written for cs101 */
//bug-fixed version of demo08-factorial-mod1.cpp

#include <iostream>
using namespace std;
int main() {
int num = 0; float nFactorial; char flag = 'y';
do {
	nFactorial = 1;
	cout<< "give the value of num: "; cin >> num; 
	cout<< "The given value of num is: " << num <<endl;
//	if (num < 0) {cout << "negative number. exiting!" <<endl; break;}
	if (num < 0) {cout << "give non-negative number!" <<endl; continue;}
	for (int i = 1; i <= num; i++) nFactorial *= i; 
	cout<< " the nFactorial value is: " << nFactorial <<endl;
	cout<< " give another number (y/n): "; cin >> flag;
} while (flag == 'y');
return 0;
}
// See what happens at input values of 9 and 10
// Fractions input => Number is truncated and cin >> flag is corrupted
// How to fix - later class; For now, dont give invalid input!
// Give 2 y 5 y 8 y as input to see working of cin
