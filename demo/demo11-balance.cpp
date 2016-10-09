/* demo11-balance.cpp, written for cs101 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
   int A[100], B[100], M, N;
   int sumA, sumB, y, i, j, diff, foundcount=0;

/* Input section*/
   cout << "Give number of packages in first truck: "; cin >> M;
   cout << endl << "give weights of individual packages: ";
	for (i=0; i<M; i++) {cin >> A[i]; cout << A[i]<< " ";}
   cout << endl << "Give number of packages in second truck: "; cin >> N;
   cout << endl << "give weights of individual packages: ";
	for (i=0; i<N; i++){ cin >> B[i]; cout << B[i] << " ";}
   cout << endl << endl;	
	
// Find sum of elements of each array, find the difference of sums
   sumA = 0; for (i=0; i<M; i++) sumA += A[i];
   sumB = 0; for (i=0; i<N; i++) sumB += B[i];
   cout << "sum of load in each of two trucks: ";
   cout << sumA <<" "<< sumB << endl;
   diff = abs (sumA-sumB);
	if (diff%2 !=0) {
		cout << "Difference of sums is not even" << endl;
		cout << "Desired pair of packages does not exist" << endl;
	return 1;
	}

	for (i=0; i < M; i++){
		y = (sumA -sumB)/2 +A[i] ; // Find a possible y
		for (j=0; j < N; j++){ // Search for y in array B ... Sequential search
			if (B[j] == y){
				foundcount++;
				cout << A[i] <<" to be exchanged with " << B[j] << endl;
			}
		}
	}
   if (foundcount == 0) cout << "Sorry, balancing not possible" << endl;
return 0;
}
// A- 12, 26, 7, 80; B- 34, 22, 53
