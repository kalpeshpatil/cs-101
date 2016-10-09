/* midsem-numSequence.cpp, written for cs101 Midsem*/
// Given a number, generate a number which is the product of its digits
// Repeat the process with the new number till you get to a single digit

#include <iostream>
using namespace std;

int main() {
int num, d[10], newN;
int size, i;

	cout << "Give a number (upto 10 digits): "; cin >> num;
do {
	cout << "The number is: " << num << endl;
	i = 0;
	while (num > 0) {
		d[i] = num % 10; i++;
		num /= 10;
	}
	size = i;
//	cout << size << endl;	//print-debug
	newN = 1;
	for (i = 0; i < size; i++) newN = newN * d[i];
	cout << "The product of its digits is: " << newN << endl;
	num = newN;
} while (newN/10 > 0);

return 0;
}
