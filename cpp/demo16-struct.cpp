/* demo16-struct.cpp, written for cs101 */
// create and manipulate a database of contacts

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

typedef int Num;  //giving a new name to int - Num
typedef int Marks; //3-parts - typedef, old type, new name
Num roll[100];

typedef 
	struct contact { //Struct definition
		string name;
		int number;
		string email;
	}
	CONTACTS; //Giving it a new name using typedef
	
#define MAX 5

void read(CONTACTS person[]); // Read the contact info from stdin into memory
void write(CONTACTS person[]); // Print the contact info from memory to stdout

int find (CONTACTS person[], string name1); // Find index of name1 in person[]
CONTACTS lookup (CONTACTS person[], string name1); // Find contact info for name1
void update (CONTACTS person[], string name1, CONTACTS p1); // Update contact info for name1 with p1
void remove (CONTACTS person[], string name1); // Delete info of name1 from contacts

int main() {
  CONTACTS friends[MAX], tmp;
  string str;
  char flag = 'y', choice = 'i';

// Direct initialization for demo. Comment these lines out for file input
	friends[0].name = "TA";
	friends[0].number = 12345;
	friends[0].email = "xyz@iitb.ac.in";
	cout << friends[0].name << " " << friends[0].number << " " << friends[0].email << endl;
	
	for (int n=0; n<MAX; n++) { //Reset all the entries to null values
		friends[n].name = "$$$";
		friends[n].number = -1;
		friends[n].email = "***";
	}

	while (flag != 'n') {
	  cout << "Which function?\n r for Read, w for Write, l for Lookup, u for Update, d for Remove: ";
	  cin >> choice;
	  switch (choice) {
		case 'r' : 
			read(friends);
			break;
		case 'w' : 
			write(friends);
			break;
		case 'l' :
			cout << "Give the name of contact to lookup: ";
			cin >> str;
			tmp = lookup (friends, str);
			cout << "Contact info is: " << tmp.name << " " << tmp.number << " " << tmp.email << endl; 
			break;
		case 'u' :
			cout << "Give the name of contact to update: ";
			cin >> str;
			cout << "Give the new info - name, number, email: ";
			cin >> tmp.name >> tmp.number >> tmp.email;
			update (friends, str, tmp);
			break;
		case 'd' :
			cout << "Give the name of contact to delete: ";
			cin >> str;
			remove (friends, str);
			break;
		default :
			cout << "Unrecognized Input" << endl;
   }
   cout << "Continue processing, Y/N?"; cin >> flag;
  }
return 0;
}

void read(CONTACTS person[]) { // writing (CONTACTS *person) is correct but avoid
//Manual input; Comment out the cout lines for i/o redirection from file
	int n=0; char flag = 'y';
	cout << "Read in contacts (upto MAX):\n";
	while (n<MAX && flag != 'n') {
		cout << "Give the Name, Number and Email: ";
		cin >> person[n].name;
		cin >> person[n].number;
		cin >> person[n].email;
		n++;
		cout << "Read one more contact? Y/N: "; cin >> flag;
  }
}

void write (CONTACTS person[]) {  
// Terminal output; Comment out the cout below for i/o redirection to file
  cout << "Printing your contacts:\n";
  for (int n=0; n<MAX; n++) {
  cout << person[n].name;
  cout << " (" << person[n].number << ")";
  cout << " [" << person[n].email << "] \n";
  }
}

int find (CONTACTS person[], string name1) { // Find index of name1 in person[]
   int idx = -1;
   for (int n=0; n<MAX; n++) {
	   if (person[n].name == name1) {
//		   cout << "Found contact at index " << n; 
		   idx = n; break; 
	   }
   }
   return idx;
}

CONTACTS lookup (CONTACTS person[], string name1) { // Find contact info for name1
   CONTACTS p1 = {"$$$", -1, "***"}; // Null initialization
   int id;
   
   id = find (person, name1);
   if (id != -1) p1 = person[id]; //name, number, email from person[id] are copied into p1
   return p1;
}

void update (CONTACTS person[], string name1, CONTACTS p1) { // Update contact info for p1
	int id = find (person, name1);
	if (id != -1) {
		person[id] = p1; // Copy all values from p1 to person[id]
		cout << "Updated info is: " << person[id].name << " " << person[id].number << " " << person[id].email << endl;
	}
	else cout << "Contact not found\n"; 
}

void remove (CONTACTS person[], string name1) { // Delete name1 info from contact info
	CONTACTS p1 = {"$$$", -1, "***"}; // Null initialization
	int id = find (person, name1);
	if (id != -1) {
		person[id] = p1; // Delete by replacing with junk. 
		cout << "Contact for " << name1 << " removed\n";
	}
	else cout << "Contact not found\n"; 
}
// EOF
