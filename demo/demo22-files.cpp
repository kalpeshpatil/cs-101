// demo22-files.cpp - cs 101
// Tutorial problem on file handling

#include <iostream>
#include <fstream>
#include <string> // C++ fstream classes
using namespace std;

int main () {
  fstream file;
  long begin, end;  
  int nwords = 0;
  string word;

  file.open ("demo22-xyz.txt", fstream::in); // Assuming file exists, not performing error check

//Find the number of bytes in the file  
    begin = file.tellg();
    file.seekg (0, file.end);
    end = file.tellg();    
    cout << endl << "Size of the File is: " << end-begin << " bytes." << endl;

//Count the number of words in the file 
  file.seekg (0, file.beg);
  while (file >> word) ++nwords; // While loop exits when file ends
  cout << "Number of words in the File is = " << nwords << endl;

  file.close();
}
