#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;
struct node{
	int num;
	node* next;
};

node *create(node*head){
	srand(time(NULL));
	node *p;
	
	p=new node;
	head=p;
	p->num=rand()%100;
	p->next=0;
	
	for(int i=1;i<5;i++){
		p=new node;
		p->num=rand()%100;
		p->next=head;
		head=p;
	}

return head;
}
node*sort(node*head){
	int temp;
	node *curr,*prev;
	curr=head;prev=head;
	if(head->next==0){return head;}
	else{
	while(curr->num!=0){
		while(prev->num!=0){
			prev=curr->next;
			if(prev->num<curr->num){
				temp=prev->num;
				curr->num=temp;
				prev->num=curr->num;
			
			}
			prev=prev->next;
		}
		curr=curr->next;
	}
	return head;
}
}
void show(node*head){
	node *p=head;
	while(p!=0){
		cout<<p->num<<" ->";
		p=p->next;}
	}
	
	int main(){
		node*head;
		node*p;
		srand(time(NULL));
		
		head=new node;
		head->next=0;
		
		head->num=rand()%10;
		for(int i=0;i<5;i++){
			p=new node;
			p->next=head;
			head=p;
			p->num=rand()%100;
			
		}
		cout<<"kal";
		show(head);
		head=sort(head);
		show(head);
		return 0;
	}
			
			

	
