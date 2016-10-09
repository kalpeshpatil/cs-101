// midsem-reverseWord.cpp

#include<iostream>
using namespace std;

int main() { 
char arr[30];
int i = 0, length;

cout << "Give the word: ";
while (1) {
	cin >> arr[i];	// cin will ignore blankspace, so check for .
	if (arr[i] == '.') {length = i; break;} 
	else i++;
}

cout << endl;
for (i = length-1; i >= 0; i--) cout << arr[i];
cout << endl;
  
return 0;
}
