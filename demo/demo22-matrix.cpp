// demo22-matrix.cpp -cs 101
// Tutorial problem on handling matrices

#include <iostream>
using namespace std;

bool evenM(int M[3][3]);

int main() { // Sample input for testing is in - demo22-matrix-input.txt - Use I/O redirection
int M[9][9], N[9][9];

// Read M
srand(time(NULL));
  for(int i=0; i<9; i++)
	for(int j=0; j<9; j++) M[i][j]=rand()%10;

// Transpose M into N
  

// Print N
  for(int i=0; i<9; i++) {
	for(int j=0; j<9; j++) cout << M[i][j] << " "; 
	cout << endl;
  }
  cout << endl; // For visual formatting; Not required for program

// Determining the even subarrays by calling function evenM for 3x3
  int subRow, subCol, L[3][3];
  int row = 0, col = 0, i=0, j=0, k= 0, l=0; //loop control variables

  for (subRow = 0; subRow < 3; subRow++) { //For each row of subarrays
	for (subCol = 0; subCol < 3; subCol++) { // For each col in a row of subarrays

	  for(i=row, k=0; k<3; i++, k++) { //Copy each subarray into L
		for(j=col, l=0; l<3; j++, l++) L[k][l] = M[i][j];
	  }
	  
	  for (int x=0; x<3; x++) { //print-debug: verify if L is correct; Not required for program
		for (int y=0; y<3; y++) cout << L[x][y] <<" ";
		cout << "\n";
	  } //print-debug: end
	  
	  if (evenM(L)) cout << "s[" << subRow << subCol << "]is even \n";
	  col += 3;
	  cout << "\n"; // For visual formatting; Not required for program
	}
  col = 0; // Dont forget to reset col before incrementing row!
  row += 3;
  }
}

bool evenM(int P[3][3]) {
  bool even = true;
  for(int i=0; i<2; i++)
	for(int j=0; j<2; j++) if (P[i][j] %2 != 0) even = false;
  return even;
} 
