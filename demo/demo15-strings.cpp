/* demo15-strings.cpp, written for cs101 */
// Use of 'C' strings and 'C++ string data type

#include <iostream>
#include <cstring> // C library of string processing functions
#include <string> // C++ string class
using namespace std;

void printString1() {  //Function to print strings stored in char array
  char s1[10] = {'H', 'e', 'l', 'l', 'o', '\0', 'a', 'b', 'c', 'd'}; //Size of array s1 is 10.
  char s2[] = "Hello"; //Size of array s2 is decided based on string being initialized
  char *s3 = "Hello"; //This is similar to s2[]; both forms should be avoided
  
  cout << s1 << " " << s2 << " " << s3 << endl; //s1 prints only Hello because of \0.
  cout << s1[1] << " " << s2[1] << " " << s3[1] << endl;
  cout << *s1 << " " << *s2 << " " << *s3 << endl;
  
  for (int i = 0; i < 10; i++) cout << s1[i]; cout << endl; //s1 is printed as an array
} //End printString1()

void inputString() {  //Function to illustrate input of string using C and C++ styles
  	char s1[10] = "$$$$$$$$$"; //dummy initialization to observe output
	cin >> s1; // Will read a single WORD from input into the array and insert \0 automatically at end
	cout << s1 << endl;
	for (int i = 0; i < 10; i++) cout << s1[i]; cout << endl; //chars beyond \0 are garbage
	
// Try: What happens if the word given as input is longer than 10 chars?
// Try: What happens if multiple words are typed?

	cin >> s1; //s1 can be overwritten by new input
	cout << s1 << endl;
	for (int i = 0; i < 10; i++) cout << s1[i]; cout << endl; //chars beyond \0 are garbage
  
	string str1; //C++ declaration; system automatically keeps track of size
	cin >> str1; //Will read upto the first blank space
	cout << str1 << endl;

	cin >> str1; //str1 can be overwritten by new input
	cout << str1 << endl;

//Try: What happens when new input is longer than old, s1 and str1?
} //End inputString()

void printString2() { //Function to illustrate use of C++ strings
  char s1[] = "Hello";
  char s2[] = {'H', 'e', 'l', 'l', 'o', '\0'};
  
  string str1, str2;
  str1 = s1; str2 = s2;
 
  
  cout << str1 << " " << str2 << endl;
  if (s1 == s2) cout << "s1 == s2" << endl; else cout << "s1 != s2" << endl;
  if (str1 == str2) cout << "str1 == str2" << endl; else cout << "str1 != str2" << endl;
  
} //End printString2()

void reverseString() { //Function to reverse a string without using any libraries
   char s1[20], temp;
   int i = 0, j = 0; 
	
	cout<<"Enter a string (without spaces): "; cin >> s1;
	for (j = 0; s1[j] != '\0'; j++) ; //Find length of string in j
	
	while (i < j/2) {
	  temp=s1[i]; s1[i]=s1[j-i-1]; s1[j-i-1]=temp; i++;
  }

// Code below uses for loop as alternative to while loop above
//	for (i=0, j=j-1; i < j; i++, j--) {
//      temp=s1[i]; s1[i]=s1[j]; s1[j]=temp; 
//   }
 
   cout<<"Reverse string is: "<< s1 << endl;
} //End reverseString()

void concatString() { //Function to illustrate use of C string libraries
   char s1[10], s2[10], s3[20];
   int i, j, k; 
	
	cout<<"Enter string1 and string2: "; cin >> s1 >> s2;
	i = strlen(s1); 
	j = strlen(s2); //Find length of string
	cout<<"string1: " << s1 << " length: " << i << " string2: " << s2 << " length: " <<j <<endl;
	
	strcpy(s3, s1); //copy s1 to s3
	strcat(s3, s2); //append s2 at the end of s3

	k = strlen(s3);
	cout<<"string3: "<< s3 << " length: " << k << endl;

	k = strcmp(s1, s2);
	if (k < 0) cout << "k is " << k << ":" << s1 << " less than " << s2;
	else if (k > 0) cout << "k is " << k << ":" << s1 << " greater than " << s2;
	else cout << "k is " << k << ":" << s1 << " equal " << s2;
	cout << endl;
} //End concatString()

void compareString() { //Function to illustrate use of C++ string class methods
	string msg1, msg2;
	int i, j, k;

	cout<<"Enter string1 and string2: "; cin >> msg1 >> msg2;
	i = msg1.size() -1;
	j = msg2.size() -1;
	cout<<"string1: " << msg1 << " length: " << i << " string2: " << msg2 << " length: " <<j <<endl;

	k = msg1.compare(msg2); //compares relative position of msg1 and msg2 in a dictionary
	if (k < 0) cout << msg1 << " occurs before " << msg2 << endl;
	else if (k>0) cout << msg2 << " occurs before " << msg1 << endl;
	else cout << "Strings are identical \n"; // k = 0
	
	string c1, c2;
	c1 = msg1.substr(0, 3); //c1 is the substring from msg[0] to msg[3]
	c2 = msg2.substr(2, 5); //c2 is the substring from msg[2] to msg[5]
	cout<<"substring1: " << c1 << " substring2: " << c2 << endl;
	
	c1+= c2;
	cout<<"Concatenation of substrings is: " << c1 << endl;
} //End compareString()

int main() {
  int choice;
  char flag = 'n';
  
  while (flag != 'y') {
  cout << "Which function to call? Give a number in [1..9]: "; cin >> choice;
  switch (choice) {
	case 1 :
	  cout << "Calling printString1()" << endl;
	  printString1();
	  break;
  	case 2 :
	  cout << "Calling inputString()" << endl;
	  inputString();
	  break;
	case 3 :
	  cout << "Calling printString2()" << endl;
	  printString2();
	  break;
	case 4 :
	  cout << "Calling reverseString()" << endl;
	  reverseString();
	  break; 
	case 5 :
	  cout << "Calling concatString()" << endl;
	  concatString();
	  break;
	case 6 :
	  cout << "Calling compareString()" << endl;
	  compareString();
	  break;
	default :
	  cout << "Are you sure you want to exit (y/n)";
	  cin >> flag;
  }
 }
} //End main()
