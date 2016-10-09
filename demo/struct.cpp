#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#define max 5

struct contact{
	string name;
	int number;
	string email;
};


void read(contact phonebook[]){
	contact person;int i=0;char flag='y';
	while ((i<max) &&( flag=='y')){
	cout<<" name of contct\n ";
	cin>>person.name;
	cout<<" number\n";
	cin>>person.number;
	cout<<" email\n";
	cin>>person.email;
	phonebook[i]=person;
	i++;
	cout<<"continue?\n ";
	cin>>flag;
}
}
void write(contact phonebook[]){
	int i=0;cout<<"contacts are :\n ";
	while(i<max){
		cout<<phonebook[i].name<<" ("<<phonebook[i].number<<") ["<<phonebook[i].email<<"]\n";
		i++;
	}
}
int find(contact phonebook[],string name){
   int index; int n=-1;
  for(n=0;n<max;n++){
	   if(phonebook[n].name==name){
		   index=n;
}
}
return index;
}
contact lookup(contact phonebook[],string name1){
	int p=find(phonebook,name1);
	if (p==-1){
		cout<<" "<<name1<<" not found\n";
	}
	else
	{return phonebook[p];}
}
contact update(contact phonebook[],string name2){
	int u=find(phonebook,name2);
	if(u!=-1){
	cout<<"edit "<<name2<<"\n";
	cin>>phonebook[u].name;
	cin>>phonebook[u].number;
	cin>>phonebook[u].email;
	cout<<" updated! \n";
}
}
contact remove(contact phonebook[],string name3){
	int m=find(phonebook,name3);
	contact p={"chutiya",173314,"sedd"};
	if (m!=-1){
		phonebook[m]=p;
	}
}

int main(){
	contact phonebook[max],j,m;
	char response;
	while(1){
	cout<<"function to call? r=read, w=write, l=lookup, d=remove, u=update";
	cin>>response;string x;
	switch(response){
		case 'r':
		read(phonebook);break;
		case 'w':
		write(phonebook);break;
		case 'l':
		
		cout<<"look for?\n";
		cin>>x;
		m=lookup(phonebook,x);
		cout<<m.name<<" "<<m.number<<" "<<m.email<<endl;break;
		case 'd':
		cout<<"type the name to remove\n";
		cin>>x;
		m=remove(phonebook,x);
		cout<<m.name<<" "<<m.number<<" "<<m.email<<endl;
		break;
		case 'u':
		cout<<"type the name to update\n";
		cin>>x;
		j=update(phonebook,x);
		cout<<j.name<<" "<<j.number<<" "<<j.email<<endl;
		break;
		default:
		cout<<"fuck u\n";
		break;
	}
}
	return 0;
}
		
	

	

		
	 
