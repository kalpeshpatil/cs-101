// Definition of class Circle; Inherits from class Point

#include <iostream>
using namespace std;

#include "demo20-point.h"

class Circle : public Point {
 public:
     Circle( double r = 0.0, int x = 0, int y = 0 ); // default constructor
     void setRadius( double );    // set radius
     double getRadius();    // return radius
     double area();         // calculate area
     void printCircle(); // print the circle center and radius
 protected:          // accessible to derived classes
     double radius;   // radius of the Circle         
}; // end class Circle

// Constructor for Circle calls constructor for Point  
// with a member initializer and initializes radius    
Circle::Circle( double r, int a, int b ) 
	: Point( a, b )       // call base-class constructor
	{ setRadius( r ); }                                    
// Set radius
void Circle::setRadius( double r ) { radius = ( r >= 0 ? r : 0 ); }
// Get radius
double Circle::getRadius() { return radius; }
// Calculate area of Circle
double Circle::area() { return 3.14159 * radius * radius; }
// Output a circle in the form: Center = [x, y]; Radius = r
void Circle:: printCircle() {
	cout << "Center = ["; printPoint();
	cout << "]; Radius = " << radius << endl;
}
