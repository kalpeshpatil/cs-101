/* demo13-recursion-fibonacci.cpp */

#include <iostream>
#include <ctime>
//#include <time.h>	//This statement can also be used instead of #include <ctime> above.	
using namespace std;

void fib1 (long n) {  //Simple iterative version
long h1, h2, h3;
   cout << "Inside fib1, generating fibonacci numbers from 1 to " << n << endl; 
   
   h1 = 1; h2 = 1; h3 = 2; 
   cout << h1 << " " << h2 << " "; 

   while (h3 < n) { 
	   if ((h1 + h2) > n) break; 
	   else { 
		  h3 = h1 + h2;	
		  cout << h3 << " "; 
		  h1 = h2;
		  h2 = h3;
	  }
   }
   cout << "fib1 Done!" << endl;
}

int fib2 (long n) { //Recursive version; Draw the call tree to follow the output
   cout << "Inside fib2, n = " << n << endl;
   if (n < 2) return 1;
//   if (n < 2) { cout << "Inside fib2, inside if" << endl; return 1; }
   else return fib2 (n-1) + fib2 (n-2);
}

int main() {
	long n; char flag;
	clock_t t1, t2;
   cout << "Give the value of N: "; 
   cin >> n;

   cout << "Generate fibonacci numbers by iteration?"; cin >> flag;
   t1 = clock();
   fib1(n);
   t1 = clock() - t1;
   
   cout << "Generate fibonacci numbers by recursion?"; cin >> flag;
   t2 = clock();
   fib2(n);
   t2 = clock() - t2;
   
   cout << "Timings are: " << ((float) t1)/CLOCKS_PER_SEC << " and " << ((float) t2)/CLOCKS_PER_SEC << endl;
return 0;
}
