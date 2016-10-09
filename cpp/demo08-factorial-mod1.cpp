/* demo08-factorial-mod1.cpp, written for cs101 */
// nested loop version of demo08-factorial.cpp
#include <iostream>
using namespace std;
int main() {
int num;
float nFactorial = 1; char flag = 'y';
while (1) {  //infinite loop - condition always true
	cout<< "give the value of num: "; cin >> num;
	nFactorial = 1;
	for (int i = 1; i <= num; i++) { nFactorial *= i; }
	cout<< " the nFactorial value is: " << nFactorial <<endl;
	cout<< " give another number (y/n): "; cin >> flag;
	if (flag == 'n') break;
//	if (flag != 'y') break;
}
return 0;
}
// See what happens at input values of 4 and 5

// Fix bug and see what happens at input values of 16 and 17
// Fix bug and see what happens when you give a number for flag 
// Fix bug and run for negative nos, fractions, 'a' insead of integer
// bugs - nFactorial init in while missing; int overflow; flag check;
// bugs - standard error checks for invalid input not done
