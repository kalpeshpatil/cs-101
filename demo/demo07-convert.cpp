 #include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;
int arraydup(int a[],int &n){
	
	int i,j,k;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
		if(a[i]==a[j]){
			cout<<"duplicate found for "<<a[i]<<endl;;
			for(k=j;k<n;k++){
				a[k]=a[k+1];
			}
			n--;j--;
			
}
}
}
return n;
}

int main(){
	int arr1[10] = {1, 1, 5, 2, 3, 4, 5, 3, 9, 9};
	int n=10;
	n=arraydup(arr1,n);
	int i;
	for(i=0;i<n;i++){
		cout<<arr1[i]<<" ";
	}
	return 0;
}
/*
using namespace std;
bool substrng(string s1,string s2){
	if (s1.size()<s2.size() )return 0;
	else{
	int m=s2.size();
	cout<<m<<endl;
	string temp;
	int n=s1.size();
	cout<<n<<endl;
	for (int i=0;i<n-m;i++){
		temp=s1.substr(i,i+m);
		cout<<temp<<endl;
		temp=temp+'\0';
		cout<<temp<<endl;
		if(s2==temp){return 1;}
		
	}
	return 0;
}
}
int main(){
	string s1,s2;
	int m=s2.size();
	int n=s1.size();
	cin>>s1;
	cin>>s2;
	cout<<s1.substr();
	string temp;
	//cout<<substrng(s1,s2);
	for(int i=0;i<n-m;i++){
      temp=s1.substr(i,i+m);
	cout<<temp;}
	
return 0;
}

/*
class a{
	public:
	a(){cout<<"a:default";}
	a(int a){cout<<"a:para";}
	protected:
	int x;
};
class b:public a{
	protected:
	int y;
	public:
	b(){cout<<"b:default";}
	b(int p, int q):a(p)
	{y=q;
		cout<<"b para";}
};

int main(){
	a a1;
	b b1;
	a a2(2);
	b b2(3,4);
	return 0;
}
	
/*struct node{
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
	while(curr!=0){
		while(prev!=0){
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
			p->num=rand()%10;
			p->next=head;
			
			
			head=p;
			
		}
		cout<<"kal";
		show(head);
		head=sort(head);
		show(head);
		return 0;
	}
			
			

/*int f; 
float c;
cout<< "give the fahrenheit value: "; cin >> f;
c = 5 * (f-32)/9;
cout << " the centigrade value is: " << c << endl;
cout << "Done! \n";
return 0;
}

// See what happens when you type a character instead of number for f
// What is the bug fix?
*/
