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
node* remove(node*head, int item){
	node*curr=head;
	node*prev=head;
	if(head==0){
		cout<<"empty lsit\n ";
	}
	int flag=0;
	if (head->next==0){if(head->number==item){
		head=head->next;
		flag=1;delete curr; return head;
	}
}
else
curr=head->next;
    while(curr!=0){
		if(curr->number==item){flag=1;
		 prev->next=curr->next;
		 delete curr; return head; 
	 }
	 prev=curr;
	 curr=curr->next;
 }
if (flag==1){cout<<item<<" deleted\n";}
else cout<<item<<" not found in list ";
return head;
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
default:
cout<<"fuck u\n ";
}
}
return 0;
}
 

