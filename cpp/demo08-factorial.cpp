/* demo08-factorial.cpp, written for cs101 */
#include <iostream>
using namespace std;
int main() {
int num, nFactorial = 1;
	cout<< "give the value of num: "; cin >> num;
	for (int i = 1; i <= num; i++) {
		nFactorial *= i; 
	}
	cout<< " nFactorial is: " << nFactorial <<endl;
return 0;
}
