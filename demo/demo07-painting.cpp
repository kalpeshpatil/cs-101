/* demo07-painting.cpp, written for cs101 */
// psuedo-code logic:
// Inputs : radius, height, numTanks, pricePaint
// Outputs: cost
// Computation: 
//		1. Calculate area of each cylinder 
// 		2. Calculate the cost
// Assumptions: 
// (i) All tanks are identical, 
// (ii) Same paint is used for each tank,
// (iii) No additional labour cost.

#include <iostream>
using namespace std;
int main() {
float r, h, price, area;
const float pi = 3.14159; int Ntanks; float cost;
cout<< "give the radius and height of cylinder: "; cin >> r >> h;
cout<< "give number of tanks: "; cin >> Ntanks;
cout<< "give price per sq meter for painting: "; cin >> price;
area = (2 * pi * r * h + pi *r *r);
cost = price * Ntanks* area;
cout<< "Cost of painting is: " << cost << endl;
return 0;
}
