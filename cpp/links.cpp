#include<iostream>
using namespace std;
struct node{
	int number;
	node* next;
};
node* insert(node* head, int item){
	node* curr=head;
	head=new node;
	head->number=item;
	head->next=curr;
return head;
}
void append(node*head,int item){
	node* p=new node;
	p->number=item;
	p->next=0;
	
	node*curr=head;
	node*prev=head;
	while(curr!=0){
		prev=curr;
		curr=curr->next;
	
	}prev->next=p;
	
	
}
void show(node*head){
	node*curr=head;
	cout<<"number are\n";
	while(curr!=0){
		cout<<curr->number<<" ";
		curr=curr->next;
	}
	cout<<endl;
}
node* remove(node * head, int item, node * curr=0,node * prev=0){
	curr=head;
	prev=head;
	cout<<"Fl1";
	if(head==0){
		cout<<"empty lsit\n ";
	}
	int flag=0;
	if(head->number==item){
		head=head->next;
		flag=1;delete prev;return head;
	
}
curr=head->next;
    while(curr!=0){
		if(curr->number==item){flag=1;
		 prev->next=curr->next;delete curr;
		  return head; 
	 }
	 prev=curr;
	 curr=curr->next;
 }
if (flag==1){cout<<item<<" deleted\n";}
else cout<<item<<" not found in list ";
return head;
}
/*
node* remove(node* head, int item) {//delete the first occurrence of item from the list
	node* curr = head;
	node* prev = head;
	
	if (head == 0) {cout << "List is empty\n"; return head; }
	if (head->number == item) { //List is not empty and item is the first node
		head = head->next; //change the head of the list to the next item
		delete curr; //release the space
		return head;
	}
	else { //traverse the list to find the item
		curr = head->next;
		while (curr != 0) { //end not reached
			if (curr->number == item) { //item found
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
}*/
node*findSmallest(node*head){
	node*smallest=head;
	node*current=head;
	while(current!=0){
		if(current->number < smallest->number){
			smallest=current;
		}
		current=current->next;
	}
return smallest;
		
}		
		
int main(){
	node a,b,c;
 node* head=&a;
 a.number=1;b.number=2;c.number=3;
 a.next=&b;b.next=&c;c.next=0;
 int n;
 while(1){
 cout<<"use function ?";
 cin>>n;
 node last;node*lastfinder=head;
 while(lastfinder->next!=0){
	 lastfinder=lastfinder->next;
 }
 last=*lastfinder;
 switch(n){
	 case 1:
	 cout<<"give item to inser at first place\n ";
	 int item;
	 cin>>item;
	 head=insert(head,item);
	cout<< insert(head,item)->number;break;

case 2:
cout<<"give item to append\n";
cin>>item;
append(head,item);
break;


case 3:
show(head);break;
case 4:
cout<<"give item to remove\n ";
cin>>item;
head=remove(head,item);break;
case 5:
cout<<"smallest is "<<findSmallest(head)->number;break;
case 6:
cout<<lengthRecurse(head);
break;
default:
cout<<"fuck u\n ";
}
}
return 0;
}
 

