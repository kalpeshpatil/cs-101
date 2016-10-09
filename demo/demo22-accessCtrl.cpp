// cs101 - Inheritance access control mechanisms

#include <iostream>
using namespace std;

class X {
	int priv;  // private data   
   protected :
	int prot;  // protected data
   public :
	int pub;   // public data
    X(); // default constructor
    X(int x, int y, int z); // Constructor
	void f();  // public member function
};

X::X() { // default constructor
  priv = 0; prot = 0; pub = 0; 
  cout << " default constructor of X \n";
  cout << " Initial values of data : priv = " << priv  << " prot = " << prot << " pub = " << pub << endl;
}

X::X(int x, int y, int z) { // Constructor
  priv = x; prot = y; pub = z; 
  cout << " Constructor of X \n";
  cout << " Initial values of data : priv = " << priv  << " prot = " << prot << " pub = " << pub << endl;
}

void X::f() 
{
  priv++; prot++; pub++;
  cout << " in function f() of X \n";
  cout << " priv = " << priv << " prot = " << prot << " pub = " << pub << endl;
}

class Y : public X { // Y is derived class of X
  public :
    Y() : X() { // use default constructor of X itself
		cout << " default constructor of y\n";
		cout << " Initial values of data : priv = not accessible." << " prot = " << prot << " pub = " << pub << endl;
	}
	Y(int x, int y, int z) : X (x, y, z) { // use constructor of X, only way to set priv=x from Y
		cout << " Constructor of Y \n";
//		cout << " Initial values of data : priv = " << priv  << " prot = " << prot << " pub = " << pub << endl;
		cout << " Initial values of data : priv = not accessible." << " prot = " << prot << " pub = " << pub << endl;
	}
    void fy();
};

void Y::fy() {
//      priv = 4;  // not accessible - compilation error
	cout << " Applying fy() to object of Y " << endl;
    prot *= 2;
	pub  *= 2;
        cout << " prot = " << prot << " pub = " << pub << endl;
        
        cout << " Applying f() of X to object of Y " << endl;
        X::f(); // Y cannot access priv directly but can do so only through X::f()
}

int main() {
  char flag;
  X x1;
  cin >> flag; // pause the program here and predict output of next line
  
  X x2(1,2,3);
  cin >> flag; // pause the program here and predict output of next line
  
  x1.f();
  x2.f(); 
  cin >> flag; // pause the program here and predict output of next line
  
  Y y1;
  cin >> flag; // pause the program here and predict output of next line

  Y y2(1, 2, 3);
  cin >> flag; // pause the program here and predict output of next line
  
  y1.fy();
  y2.fy();
}
