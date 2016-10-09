// Extend demo18-poly.cpp to 
// demostrate the use of constructors

#include <iostream>
#include <math.h>
using namespace std;

class poly {
   private:
    float coefs[10];
    int   degree;
   public:
    poly(int i, float cfs[]); // Constructor
    poly(); // Constructor - See note below.
    void ReadIn(void);
    int  deg(void);
    float eval(float);
    void print();
};

poly::poly(int i, float cfs[]) {
    degree=i;
    for(int j=0; j<=i; j++)
        coefs[j] = cfs[j];
}

// The following is required if a variable is declared as
//     poly p;
// As long as there is no constructor defined, there is a 
// default constructor that does nothing, but once 
// a constructor is defined for poly above, the constructor
// below has to be explicitly defined.
poly::poly() {
   degree=0;
}

void poly::ReadIn(void) {
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

int main() {
  poly p;
  double point;
  
  cout << "Enter degree followed by coefficients: " ;
  p.ReadIn();
  p.print();
  
  cout << "Enter point at which to evaluate polynomial: ";
  cin >> point;
  cout << "@" << point << " = " << p.eval(point) <<"\n";

  float cfs[]={1.0, 2.0, 3.0};
  poly p2(2, cfs);
  cout << "Polynomial initialized using constructor:" ;
  p2.print();
}
