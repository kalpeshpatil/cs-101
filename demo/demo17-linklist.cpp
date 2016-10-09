/* demo17-linklist.cpp, written for cs101 */
// create and manipulate a linked list of items

#include <iostream>
using namespace std;

struct node { //you can have many items inside the struct, such as in CONTACTS - from demo16-struct.cpp
	int num;
	node * next; //pointer to a node
};

node* insert (node *head, int item) { // insert at the head of the list
// A new element is inserted as the new first element of the list and address of the new list is returned
	node* p;
	p = new node; //new is used to get the memory for a new node
	if (p == 0) cout << "fatal error: no space " << endl;
	else {
		p->num = item;
		p->next = head; // connects new node to head of old list
		head = p;
	}
	return head;
}

void show(node *head) { // print all the items of a list
	node * p = head;
	cout << "The items in the list are:\n";
	while (p != 0) {
		 cout << "[num:" << p->num << ", next:" << p->next << "] -> "; 
		 p = p->next;
	}
	cout << "NULL" << endl;
}

void append(node *head, int item) { //append an item at the end of the list
	node* p = new node; // get memory for the struct (12 bytes) and save its address
   if (p != 0) {
	p->num = item; // initialize its val part
	p->next = 0;  // initialize its next address part (end of list hence null) 
	
	if (head == 0) head = p; // list was empty, now it has one item
	else { //traverse the list to find the end
		node* curr = head; // address of the current list node
		node* prev = head; // address of the previous list node
		while (curr != 0) { //end not found
			prev = curr;    // save address of curr node in prev 
			curr = curr->next; // move curr to the next node
		}
		prev->next = p; // prev holds the address of last node
	}
   }
   else cout << "fatal error: no space " << endl;
} //append does not need to return anything because pointer to head of list is not changed.

node* remove(node* head, int item) {//delete the first occurrence of item from the list
	node* curr = head;
	node* prev = head;
	
	if (head == 0) {cout << "List is empty\n"; return head; }
	if (head->num == item) { //List is not empty and item is the first node
		head = head->next; //change the head of the list to the next item
		delete curr; //release the space
		return head;
	}
	else { //traverse the list to find the item
		curr = head->next;
		while (curr != 0) { //end not reached
			if (curr->num == item) { //item found
				prev->next = curr->next;
				delete curr; // release the space
				return head;
			}
			prev = curr; 
			curr = curr->next;
		}
		cout << "Item to be deleted is not found, List unchanged\n"; 
		return head;
	}
}

int length (node * head) { //returns the number of nodes in a list
	node * p = head;
	int count = 0;
	while (p != 0) { count++; p = p->next; }
return count;
}

//Tutorial Q1 - call this from main to see its output
void tutorialQ1() {
 node *p, *q, *r;
   p = new node;
   r = p;
   for (int i=0; i<3; i++) {
      q = new node; 
      q->num = i; q->next = 0;
      p->num = i*2; p->next = q;
      p = q;
   }
   cout << p->num << " " << q->num << " " << r->num;
   show(r); //print the entire linked list to verify drawing
}

//Tutorial Q2 - call this from main to see its output
int findSmallest(node* head) {//returns smallest item in the list
	node* curr = head; // address of the current list node
	int smallest = head->num; // start with first item
	
	while (curr != 0) { //end not reached
		if (curr->num < smallest) smallest = curr->num;
		curr = curr->next; // move curr to the next node
//		else curr = curr->next; // This is also correct, but will take more iterations
	}
	return smallest;
}

//Tutorial Q3 - call this from main to see its output
node* find(node* head, int item) {//returns the address of the item
	node* curr = head; // address of the current list node
	while (curr != 0) { //end not reached
		if (curr->num == item) break; //item found
		else curr = curr->next; // move curr to the next node
	}
	return curr;  //If item is not found, curr will be NULL
}
	
void demo1() { //Inefficient way of creating a linked list
//Here 3 nodes having values 1, 2, 3, are created and head points to the first node
	node a, b, c; //You have to know how many nodes you need and allot space for them!
	a.num = 1;
	a.next = &b;
	b.num = 2;
	b.next = &c;
	c.num = 3;
	c.next = 0;
	
	node* p = &a;
	show(p); //function to display the linked list
//The above is not a good way to manage a linked lists
//It is better to allot space as and when required, as shown in main()
}

int main () {
	node *head;
	int val;
	char flag = 'y', choice = 'i', pause;

	demo1();
	cin >> pause; //Dummy read to pause the program here.
	
//Direct initialization
	head = new node; //Get a new memory block for the struct node
	head->num = 10; //Initialize the number to 10
	head->next = 0; //Initialize the pointer to 0 (NULL)
	show(head); //function to display the linked list

	cin >> pause; //Dummy read to pause the program here.
//Typical way of creating a linked list
// Here 3 nodes having values 11, 12, 13, are attached after head
	node *ptr1, *ptr2;
	ptr1 = head;
	for (int i=11; i<14; i++) {
		ptr2 = new node;
		ptr1->next = ptr2;
		ptr2->num = i;
		ptr2->next = 0;
		ptr1 = ptr2;
	}
	show(head); //function to display the linked list

//Some commonly used functions on linked lists	
	while (flag != 'n') {
	  cout << "Which function to call?\n s for Show, i for Insert, a for Append, r for Remove: ";
	  cin >> choice;
	  switch (choice) {
		case 's' :
			show(head);
			break;
		case 'i' :
			cout << "Give the item (int) to Insert: "; cin >> val;
			head = insert(head, val);
			break;
		case 'a' :
			cout << "Give the item (int) to Append: "; cin >> val;
			append(head, val);
			break;
		case 'r' :
			cout << "Give the item (int) to Remove: "; cin >> val;
			head = remove(head, val);
			break;
		case 'l' :
			cout << "Length of the list is: " << length(head) << endl;
			break;
		case 'f' :
			cout << "Give the item (int) to Find: "; cin >> val;
			ptr1 = find(head, val);
			cout << "Address of node for item " << val << " is " << ptr1 << endl;
			break;
		case 't' :
			cout << "Smallest item in the list is: " << findSmallest(head) << endl;
			break;
		default :
			cout << "Unrecognized Input" << endl;
   }
   cout << "Continue processing, Y/N?"; cin >> flag;
  }
return 0;
} //EOF
