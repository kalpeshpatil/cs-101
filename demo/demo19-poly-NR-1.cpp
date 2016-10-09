// Extend demo18-poly.cpp to 
// add a function to compute derivative
// modify main program to find the root using Newton-Raphson method.

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

int main() {
  poly p,q;
  float x,tol,fval,der; 
  int count=0;

  cout << "Enter degree followed by coefficients: " ;
  p.ReadIn();
  p.print();

  cout << "Enter point at which to evaluate polynomial: ";  
  cin >> x;  
  cout << "@" << x << " = " << p.eval(x) <<"\n";
  
  cout << "Enter tolerance: ";  
  cin >> tol;
  
  fval=p.eval(x);
  q=p.diff();
  while ((fabs(fval)>tol) && (count<1000)) {
     der=q.eval(x);
     x=x-fval/der;
     count=count+1;
     fval=p.eval(x);
cout << "Iteration " << count << ": x = " << x << ", f(x) = " << fval <<"\n"; //print-debug
  };
  cout << "Root is: " << x <<"\n";  
  cout << "No of iterations: " << count <<"\n";  
}
