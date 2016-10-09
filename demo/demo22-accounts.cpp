// demo22-accounts.cpp - cs101
// Tutorial problem on writing derived classes

#include <iostream>
#include <string>
using namespace std;

class account {
protected:
  string name; // Name of the customer
  int  accNo; // Account number
  char accType; // Use 's' for savings, 'c' for current account
  float balance; // Balance in the account
public:
   void input_accinfo() {
       cout<<"\n Enter Customer Name: "; cin >> name;
       cout<<" Enter Account Number: ";  cin >> accNo;
       cout<<" Enter Account Type: ";    cin >> accType;
   }
   void display_accinfo() {
       cout<<"\nCustomer Name: "<< name;
       cout<<"\nAccount Number: "<< accNo;
       cout<<"\nAccount Type: "<< accType;
       cout<<"\nBalance: "<< balance;
   }
   void show_balance() {
      cout<<"\nBalance: "<< balance;
   }
};

class cur_acct : public account {
  public:
    void deposit(float d) { balance += d; }
    void withdraw(float w) {
      float penalty;
      cout<<"\nBalance is: "<< balance;
      if(w >= balance) cout<<"\n\nYou need permission for Overdraft\n";
      else if (balance < 500) {
	  		penalty=0.02*balance;
			balance=(balance-w)-penalty;
			cout<<"\nBalance after deducting penalty: "<<balance;
      }
      else cout<<"\nBalance after withdrawal: "<<balance;
     }
};

class sav_acct : public account {
  public:
    void deposit() {
      float deposit,interest;
      cout<<"\nEnter amount to Deposit :- ";  cin>>deposit;      
      balance += deposit;
      interest=balance*(2/100);
      balance += interest;
    }
    void withdraw() {
      float withdraw;
      cout<<"\nBalance is: "<<balance;
      cout<<"\nEnter amount to withdraw:";   cin>>withdraw;
      if(withdraw > balance) cout<<"\nYou need permission for Overdraft\n";
      else {
      balance -= withdraw;
      cout<<"\nAfter Withdrawl your Balance is : "<<balance;
     }
    }
};

int main() { // For testing the above classes
 cur_acct c1;
 sav_acct s1;

c1.input_accinfo();
c1.deposit(200.0);
c1.show_balance();
c1.withdraw(50);
c1.display_accinfo();

s1.input_accinfo();
s1.deposit();
s1.show_balance();
s1.withdraw();
s1.display_accinfo();

}
