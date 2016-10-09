// Modify demo18-poly-NR-1.cpp to 
// convert NR computation in main program to a method (function) and
// demostrate the use of "this" pointer.

#include <iostream>
#include <math.h>
using namespace std;

class poly {
   private:
    float coefs[10];
    int   degree;
   public:
    void ReadIn();
    int  deg();
    float eval(float);
    poly diff(void);
    float root(float, float);
    void print();
};

void poly::ReadIn() {
   cin>> degree;
   if (degree >9)
      cout << "degree bounded by 9";
   for (int i=0;i<=degree;i=i+1)
      cin >> coefs[i];
}
   
int poly::deg(void) {
   return degree;
}

float poly::eval(float x) {
   float r;
   r=0;
   for (int i=0;i<=degree;i=i+1)
     r=r+pow(x,i)*coefs[i];
   return r;
}

void poly::print() {
   cout << coefs[0];
   for (int i=1;i<=degree;i=i+1) {
      cout << " + " << coefs[i] << " x^" << i ;
   }
   cout << endl;
}

poly poly::diff(void) {
   poly q;
   q.degree=degree-1;
   for (int i=0;i<=q.degree;i=i+1)
        q.coefs[i]=(i+1)*coefs[i+1];
   return q;
}

float poly::root(float x, float tol) {
	float fval, der;
	int count=0;
	poly q;

// In version NR-1, we had written p.eval(x) in the main() program.
// Now we have made root as a method within class poly, 
// so how do we call p.eval(x) from within root()? 
// "this" is a special variable representing address of current object.

  fval=this->eval(x);
  q=this->diff();
//  fval=eval(x); q= diff(); //In some compilers, this-> is implicit, so fval=eval(x) also works.

  while ((fabs(fval)>tol) && (count<1000)) {
     der=q.eval(x);
     x=x-fval/der;
     count=count+1;
     fval=this->eval(x);
//     fval=eval(x);
cout << "Iteration " << count << ": x = " << x << ", f(x) = " << fval <<"\n"; //print-debug
  };
return x;
}

int main() {
  poly p;
  float x,tol; 

  cout << "Enter degree followed by coefficients: " ;
  p.ReadIn();
  p.print();

  cout << "Enter point at which to evaluate polynomial: ";  
  cin >> x;  
  cout << "@" << x << " = " << p.eval(x) <<"\n";
  
  cout << "Enter tolerance: ";  
  cin >> tol;
  x = p.root(x, tol);
  cout << "Root is: " << x <<"\n"; 
}
