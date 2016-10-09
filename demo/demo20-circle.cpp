// Main program for class Circle

#include <iostream>
using namespace std;

#include "demo20-circle.h"

int main() {
  Circle c( 2.5, 37, 43 );
	cout << "X coordinate is " << c.getX()
		<< "\nY coordinate is " << c.getY()
		<< "\nRadius is " << c.getRadius();
	
	c.setRadius(4.25);
	c.setPoint(2, 2); 
	cout << "\n\nThe new location and radius of c are\n";
	c.printCircle(); 
	cout << "\nArea " << c.area() << '\n';
   return 0;
}
