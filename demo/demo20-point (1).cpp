// Main program for class Point

#include <iostream>
using namespace std;

#include "demo20-point.h" // The file is in the same folder as main

int main() {

  Point p(72, 115);   // initialize Point object p, using the constructor
// protected data of Point is not accessible to main, so use getX and getY
  cout << "X coordinate is " << p.getX() << "\nY coordinate is " << p.getY();
  p.setPoint(10, 10);
  cout << "\n\nThe new location of p is "; 
  p.printPoint(); cout << endl;
  
  Point q; // No intial values specified, so default constructor is used
  cout << "The location of q is: ";
  q.printPoint(); cout << endl;
  return 0;
}
