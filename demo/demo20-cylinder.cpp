// Main program for class Cylinder

#include <iostream>
using namespace std;

#include "demo20-cylinder.h"

int main() {
  Cylinder cyl( 5.7, 2.5, 12, 23 );

// use get functions to display the Cylinder
	cout << "X coordinate is " << cyl.getX()
		<< "\nY coordinate is " << cyl.getY()
		<< "\nRadius is " << cyl.getRadius()
		<< "\nHeight is " << cyl.getHeight() << "\n\n";

// use set functions to change the Cylinder's attributes
	cyl.setHeight( 10 );  
	cyl.setRadius( 4.25 );
	cyl.setPoint( 2, 2 ); 

	cout << "The new location, radius, and height of cyl are:\n";
	cyl.printCylinder();
	cout << "The area of cyl is:\n" << cyl.area() << '\n';
	cout << "The volume of cyl is:\n" << cyl.volume() << '\n';
   return 0;
}
