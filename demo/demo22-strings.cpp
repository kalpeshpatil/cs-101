// demo22-strings.cpp - cs101
// Tutorial problem on strings

#include<iostream>
#include<string>
#include<string.h> // Required only when using C string library instead of C++ string class
using namespace std;

bool isSubstring (string s1, string s2) { 

  if (s2.length() > s1.length()) return false; 
  for (int i=0; i <= s1.length()-s2.length(); i++) 
	if (s1.substr(i,s2.length()) == s2) return true;

return false; 
}

// Substring without using C++ string class but using C string library functions

bool substring1(char str1[],char str2[]) {
  int l1, l2;
  char *c;
  
  l1=strlen(str1); l2=strlen(str2);
  if (l2 > l1) return false;

  c = strstr (str1, str2); //Ptr to start of substring or null pointer if not present
  if(c == NULL) return false; 
  else return true;
}

// Substring without using either C++ string class or C string library functions
bool substring2(char *s,char *t) {
   int i, j, k;

   for (i = 0; s[i]; i++) {
		for (j = i, k = 0; t[k] && s[j] == t[k]; j++, k++) ; // No action
		if (k > 0 && !t[k]) return true;
   }
 return false;
}

int main() { // Main program for testing

	cout << endl << isSubstring("endsem", "dse") << endl; //print 1 if true
	cout << endl << substring1("endsem", "dse") << endl; //print 1 if true
	cout << endl << substring2("endsem", "dse") << endl; //print 1 if true
}
