// demo18-queue.cpp - written for cs 101
// simulate a queue of taxis and passengers at an airport

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void allinOne() { //single function that does the entire simulation
	const int n = 5; // Max number of taxis allowed at the stand
	int driverID[n]; // Array for holding taxi numbers waiting
	int nWaiting = 0, front = 0; // Number of taxis waiting
	int i, j, k, x; // temporary variables
	char flag = 'y';
	
	srand (time (NULL)); // Initialize seed of random number generator	
	
	while(flag != 'n') { // Continue simulation till user gets bored
		for (i = 0; i < 10; i++) { // Do one round of 10 arrivals and departures
		  j = rand() % 2; // Toss a coin - If heads, Taxi arrives, else customer arrives
		  switch (j) {
		case 0 : // driver arrives
			cout << "Taxi arrives: ";
			if(nWaiting >= n) cout << "Sorry, Taxi Queue is full.\n";
			else {
				k = rand() % 100; // Generate the taxi number
				cout << " Taxi number: " << k << " added to Q\n";
				driverID[(front + nWaiting) % n] = k; // Using a circular Q
// driverID[nWaiting] = k;
				nWaiting++;
			}
			break;
		case 1 : // customer arrives
			cout << "Customer arrives: ";
			if(nWaiting <= 0) cout << " No Taxis, Go away\n";
			else {
				cout << " Take taxi number: " << driverID[front] << endl;
				nWaiting--; front = (front+1)%n; // Remember the circular Q
			}
			break;
		default: break;
		}
	}
	cout << "#Taxis available now is: " << nWaiting << endl;
	cout << "Taxis numbers in Q are: ";
	for (x=0; x<nWaiting; x++) cout << driverID[(front+x)%n] << " ";
	cout << "\n Continue simulation? Y/N: "; cin >> flag;
}
}

class Queue { // Defining a class Q with private variables and public functions
  private:
  static const int n = 5; // maximum number of taxis
   int front;
   int nWaiting;
   int driverID[n]; // n = 5 defined earlier
   
  public:
	Queue(); // Constructor - initializes variables when a Q object is created
	bool insert(int); // Insert a taxi into the Q
	int remove(); // Remove a taxi from the Q
	void status(); // Check status of Q
};

Queue::Queue() {
	front = 0; nWaiting = 0;
}
	
bool Queue::insert (int value) { // insert a taxi number into Q
      if(nWaiting == n) return false; // queue is full
      driverID[(front + nWaiting) % n] = value; 
      nWaiting++; return true;
}
   
int Queue::remove() { // remove the first taxi from Q
      if(nWaiting == 0) return -1; // queue is empty
      int driver = driverID[front];
      front = (front + 1) % n; 
      nWaiting--; return driver;
}

void Queue::status() { // output status of the Q
	cout << "#Taxis available now is: " << nWaiting << endl;
	cout << "Taxis numbers in Q are: ";
	for (int x=0; x<nWaiting; x++) cout << driverID[(front+x)%n] << " ";
	cout << endl;
}
   
int main() {
	cout << "Calling allinOne()\n";
	allinOne();

//version of simulator that uses struct Queue
	Queue q; // Create a Queue object and name it 'q'
	
	int i, j, k; // temporary variables
	char flag = 'y';
	
	srand (time (NULL)); // Initialize seed of random number generator	
	
	while(flag != 'n') { // Continue simulation till user gets bored
		for (i = 0; i < 10; i++) { // Do one round of 10 arrivals and departures
		  j = rand() % 2; // Toss a coin - If heads, Taxi arrives, else customer arrives
		  switch (j) {
		case 0 : // driver arrives
			cout << "Taxi arrives: ";
			k = rand() % 100; // Generate the taxi number
			if(!q.insert(k)) cout << "Sorry, Taxi Queue full.\n";
			else cout << " Taxi number: " << k << " added to Q\n";
			break;
		case 1 : // customer arrives
			cout << "Customer arrives: ";
			k = q.remove();
			if(k == -1) cout << "No Taxis, Go away\n";
			else cout << " Take taxi number: " << k << endl;
			break;
		default: break;
		  }
		}
	q.status();
	cout << "Continue simulation? Y/N: "; cin >> flag;
	}	
}//EOF
