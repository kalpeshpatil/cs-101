// Definition of class Point

#include <iostream>
using namespace std;

class Point {
  public:
    Point (int x = 0, int y = 0);      // default constructor
    void setPoint (int x, int y);      // set coordinates
    void printPoint(); // print the coordinates
    int getX () { return x; }  // get x coordinate
    int getY () { return y; }  // get y coordinate
  protected:        // accessible to derived classes
   int x, y;      // coordinates of the point
}; // end class Point

// Constructor for class Point
Point::Point (int a, int b) { setPoint (a, b); }
// Set the x and y coordinates
void Point::setPoint (int a, int b) { x = a; y = b; }
// Output the Point
void Point::printPoint() { cout << x << "," << y; }
