/* midsem-perrinNum.cpp - Written for cs101 Midsem */

#include<iostream>
using namespace std;

int main(){
int perrin[50];
int low, high;
int index=2, even=0, odd=0;

cout << "Enter the values of a and b:";
cin >> low >> high;
cout << endl;

if(low >= 0 && low < high) {
	perrin[0] = 3; perrin[1] = 0; perrin[2] = 2;
//   perrin[index] = perrin[index-2] + perrin[index-3];
   while(perrin[index] <= high) {
	if(perrin[index] >= low) {
		cout << perrin[index] << endl;
		if(perrin[index]%2 == 0) even++;
		else odd++;
    }
    index++;
    perrin[index] = perrin[index-2] + perrin[index-3];
   }
   cout<<"Even count: "<< even << endl;
   cout <<"Odd count: "<< odd << endl;
}
else cout<<"Range given is not correct";
return 0;
}
