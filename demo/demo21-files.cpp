/* demo21-files.cpp, written for cs101 */
// File handling in C++ and difference from C file handling

#include <iostream>
#include <fstream> // For C++ file handling
#include <string>
#include <cstdio> // For C file handling (optional topic)
using namespace std;

void cFile(); // Function to demo C file handling; called at the end of main - Optional topic 

void f1() { // Open a new file, write a line in it, then print the first word and then print the entire line
  fstream myfile; //myfile is a variable of type fstream
  string word1, line1;
  char a;

  myfile.open ("demo21-f1.txt", fstream::out); //Previous contents discarded
//Other flags are: in (input), ate (at end), app (append mode)
  myfile << "ofstream example\n";
  myfile.close();

	cin >> a; // Pause the program to view the file in text editor
  myfile.open ("demo21-f1.txt", fstream::in); //Open existing file for input  
  myfile >> word1; //Read the first string (single word)
  cout << "I have read: " << word1 << endl;

	cin >> a; // Pause the program
	char h;
  myfile.seekg (0, myfile.beg); //Rewind the file
// seek => go to position specified (in this case - offset 0 from beg of file);
// seekg => get (read) from this position; seekp => put (write) into file from this position
  getline (myfile,line1, '\n'); // Read the first line; use '$' to specify till end of file
  cout << "I have read: " << line1 << endl;
  myfile.close();
}

void f2() { // Open an existing file, add 3 lines to it and print the lines.
  fstream myfile;
  string name, line1;
  int marks, posp, posg;
  char a;

  myfile.open ("demo21-f1.txt", fstream::in | fstream::out); //Open existing file for i/o
  myfile.seekp(0, myfile.end); //Go to end of file (for appending)
// Note the use of seekp instead of seekg - p is for put (write), g is for get (read)
//  myfile.seekg(0, myfile.beg); //Go to beginning of file (for reading)  

// The functions tellp and tellg can be used to know our current location in the file.
// Here is an example
		posp = myfile.tellg(); posg = myfile.tellp();
		cout << " p = " << posp << " g = " << posg << endl;
  
   for (int n=0 ; n<3 ; n++)   { // Write two lines into the file
	 cout << "Enter name: ";
     cin >> name;
     myfile << name << " "; //print the string into the file, add a space before entering marks
     cout << "Enter marks: ";
     cin >> marks;
     myfile << marks << endl; //print the marks into the file
   }
   		posp = myfile.tellg(); posg = myfile.tellp();
		cout << " p = " << posp << " g = " << posg << endl;

	cin >> a; // Pause the program, before we start output

  myfile.seekg (0, myfile.beg); //Rewind for reading, so use seekg
  while (!myfile.eof()) { // Continue till the end of the file
	getline (myfile, line1, '\n'); // Read a line; '\n' specifies end of line char
	cout << "I have read: " << line1 << endl;
  } // Some non-text character is getting inserted into myfile after the last endl
// This is causing an extra iteration after the '\n' on the last line has been read.
  myfile.close();
}

void f3() { // Open an existing file and count the number of lines in it
  fstream myfile;
  string line1;
  int i;

  myfile.open ("demo21-f1.txt", fstream::in | fstream::out); //Open existing file for i/o
  myfile.seekg (0, myfile.beg); //Rewind
  i = 0; // count the number of lines
  while (!myfile.eof()) { // Continue till the end of the file
	getline (myfile, line1, '\n'); // Read a line; '\n' specifies end of line char
	i++;
  } // As in f2(), some non-text character after the '\n' on the last line is causing an extra iteration
// So a blank line is getting counted before myfile.eof() becomes true
  cout << "The number of lines in the file is: " << i << endl;
  myfile.close();
}

void f4() { // Open an existing file and update the marks of first entry
  fstream myfile, tfile;
  string name, line1;
  int marks;

  myfile.open ("demo21-f1.txt", fstream::in); //Open existing file for input
  tfile.open("demo21-f2.txt", fstream::out); // Open temporary file for output

  myfile.seekg (0, myfile.beg); //Rewind
  getline (myfile, line1, '\n'); // Ignore the first line as it does not have any marks data
  tfile << line1 << endl;

  while (!myfile.eof()) {
	myfile >> name; myfile >> marks; // Read the name and the marks
	marks = marks * 2; // Double the marks
	tfile << name << " " << marks << endl; // Write the name and the marks to the temp file
  } // There is a problem with use of eof(); It is processing the last line twice.

  myfile.close();
  tfile.close();
}

int main() {
	char a;
	
	f1(); 
	cin >> a; // Pause the program

	f2(); 
	cin >> a; // Pause the program

	f3(); 
	cin >> a; // Pause the program

	f4(); 
	cin >> a; // Pause the program

//	cFile(); // Uncomment this line for demo of C file handling
}

void cFile() { // Demo of C file handling - in case you are interested - optional topic

  FILE * pFile;
  pFile = fopen ("demo21-f2.txt","w"); //w: Creates an empty file; Previous contents discarded
//Other flags are: r (read), a (append), r+ (read and update), w+ (new empty file for update)
  if (pFile!=NULL) {
    fputs ("fopen example", pFile);
    fclose (pFile);
  }
  
// More operations on a C file
  char name [80], str1[80], str2[80];

   pFile = fopen ("demo21-f2.txt","r+"); //Input and Output on existing file
   fseek (pFile, 0, SEEK_END); // Set file ptr to 0 bytes from end of file (to append data)
// Other options: SEEK_CUR (from current position), SEEK_SET (from beginning)

   for (int n=0 ; n<3 ; n++)   {
     puts ("Enter a name: ");
     gets (name);
     fprintf (pFile, "%s\n", name); //print the string into the file
   }
   
  rewind (pFile); // Set file pointer to beginning of file
  fscanf (pFile, "%s", str1); // Read the first string
  printf ("I have read: %s \n",str1);

  fgets (str2, 20, pFile); // Get the next 20 characters into str2
  puts (str2); //print on terminal
  
  fseek ( pFile, 6, SEEK_SET); // reset fptr to 6 Char from beginning of file
  fputs ("rewritten", pFile);
  
  fseek ( pFile, -9, SEEK_CUR);
  fgets (str2, 10, pFile); // Get the next 10 characters into str2
  puts (str2); //print on terminal
  
fclose (pFile);
}
