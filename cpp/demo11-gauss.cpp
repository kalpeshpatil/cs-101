/* demo11-gauss.cpp, written for cs101 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int i, j, k, n;
  float MatA[100][100], MatB[100], X[100];
  float Divisor, Factor, sum;
  cin >> n; 
  for(i=0; i< n; i++){ //reading matrix A
	for(j=0; j < n; j++) cin >> MatA[i][j];
  }
  for(i=0; i< n; i++){ //reading matrix B
	cin >> MatB[i];
  }
  //Gauss elimination
  for (i=0; i< n; i++){
// divide each row by the coeffs on the diagonal
	Divisor = MatA[i][i];
	MatA[i][i] = 1.0;
// Now recalcualte all coefficients in that row
	for (j = i+1; j < n; j++){
	MatA[i][j] = MatA[i][j]/Divisor;
	}
	//normalize the corresponding rhs element
	MatB[i] = MatB[i]/Divisor;
	// now replace subsequent rows, by subtracting the appropriate portion of the ith equation from it
	if (i+1 < n) {
		for (k=i+1; k<n; k++){
			Factor = MatA[k][i];
			MatA[k][i] = 0.0;
			for (j = i+1; j < n; j++){
				MatA[k][j] = MatA[k][j] -Factor * MatA[i][j];
			}
			MatB[k] = MatB[k] -Factor * MatB[i];
		}
	}
  }
// back substitution starting with last variable
  X[n-1] = MatB[n-1];
  for (i = n-2; i>=0; i--){ // Sum up ith row using values of X already determined
	sum = 0.0;
	for (j = i+1; j < n; j++){
		sum = sum + MatA[i][j] * X[j];
	}
	X[i] = MatB[i] -sum;
  }
//output the results
  for(i=0;i< n;i++){
	for (j = 0; j < n; j++) {
		cout << MatA[i][j] << " ";
	}
	cout << " " << MatB[i] << endl;
  }
  for (i=0; i<n; i++){
	cout << "X[" << i << "] is: " ;
	cout << X[i] << endl;
  }
return 0;
}
