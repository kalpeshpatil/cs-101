/* demo06-convert.cpp, written for cs101 */
#include <iostream>
using namespace std;
int main() {
float f, c;
cout<< "give the fahrenheit value: "; cin >> f;
c = 5 * (f-32)/9;
cout << " the centigrade value is: " << c << endl;
cout << "Done! \n";
return 0;
}

// See what happens when you type a character instead of number for f
// What is the bug fix?
