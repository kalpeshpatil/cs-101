// cs101: class for Rational number operations

#include <iostream>
#include <stdlib.h>
using namespace std;

class Rational {
   private:
    int numerator, denominator;
   	void reduce(); // Reduces a rational number to its lowest form
   public:
    Rational (); // Default Constructor
    Rational (int a, int b); // Constructor
	void setNumerator(int);
	void setDenominator(int);
    Rational Add(Rational a);
    Rational Subtract(Rational a);
    Rational Multiply(Rational a);
    Rational Divide(Rational a);
    void print() {cout << "The number is " << numerator << "/" << denominator << endl;}
};

//Assumes that denominator will not be specified as a negative number
Rational::Rational() { numerator = 0; denominator = 1;}
Rational::Rational(int a, int b) { numerator = a; denominator = b; reduce();}
void Rational::setNumerator(int a) { numerator = a;}
void Rational::setDenominator(int b) { denominator = b;}

void Rational::reduce() { //Use GCD program - see demo12 (iterative) or demo13 (recursive)
  int x, y, large, small, remainder;
  
  x = abs(numerator); y = abs(denominator);
  if (x > y) {large = x; small = y;}
  else if (y > x) {large = y; small = x;}
  else {return;}

  while (true) {
	remainder = large % small;
	if (remainder == 0) break;
	large = small;
	small = remainder;
  }
  numerator = numerator/small;
  denominator = denominator/small;
return;
}
	
Rational Rational::Add(Rational a) {
	Rational c;
//this-> is used to explicit refer to variable of object whose Add is called
	c.numerator = (this->numerator * a.denominator) + (this->denominator * a.numerator);
	c.denominator = this->denominator * a.denominator;

//directly using the variable implicitly assumes this->, so code below will also work
//	c.numerator = (numerator * a.denominator) + (denominator * a.numerator);
//	c.denominator = denominator * a.denominator;
	c.reduce();
	return c;
}

Rational Rational::Subtract(Rational a) {
	Rational c;
	c.numerator = (numerator * a.denominator) - (denominator * a.numerator);
	c.denominator = denominator * a.denominator;
	c.reduce();
	return c;
}

Rational Rational::Multiply(Rational a) {
	Rational c;
	c.numerator = numerator * a.numerator;
	c.denominator = denominator * a.denominator;
	c.reduce();
	return c;
}

Rational Rational::Divide(Rational a) {
	Rational c;
	c.numerator = numerator * a.denominator;
	c.denominator = denominator * a.numerator;
	if (c.numerator < 0 && c.denominator < 0) {
		c.numerator = abs(c.numerator); c.denominator = abs(c.denominator);
	}
	else if (c.denominator < 0) {
		c.numerator = -(c.numerator); c.denominator = abs(c.denominator);
	}
	c.reduce();
	return c;
}

int main() { 
  Rational p (1, 2);
  Rational q, r; 
  
  p.print(); q.print();
  q.setNumerator(3);
  q.setDenominator(4);
  
  r = p.Add(q);
  r.print();
  
  r = p.Subtract(q);
  r.print();
  
  r = p.Multiply(q);
  r.print();
  
  r = p.Divide(q);
  r.print();
}
