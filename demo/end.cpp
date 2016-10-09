#include <iostream>
#include <stdlib.h>
#include <time.h>
class Queue {
	private:
	#define n 5
	int nWaiting;
	int front;
	int driverID[n];
	public:
	Queue (int nWaiting=0, int front=0);
	int insert(int);
	int remove();
	void status();
};
int Queue::insert(int k){
	int p=k;
	if(nWaiting>=n){
		return -1;
	}
	else{
	driverID[(front+nWaiting)%n]=k;
	nWaiting++;
	return p;
}
}
int Queue::remove(){
	if (nWaiting==0){
		return -1;
	}
	else{
		int temp=front;
		front=(front++)%n;
    return driverID[temp];
}
}
void Queue::status(){
	cout<<"taxis in the list are : "<<endl;
	for(int i=front;i<=nWaiting;i++){
		cout<<driverID[i];
	}
}

int main(){
	Queue q;
	char flag='y'; 
	int i,j,k;
	srand(time(NULL));
	while(flag!='n'){
		j=rand()%2;
		for (int i=0;i<10;i++){
		switch (j){
			case 0:
			cout<<"driver arrives "<<endl;
			k=rand()%100;
			int p;
			p=q.insert(k);
			if (p==-1) cout<<"queue is full "<<endl;
			else cout <<p<< "added to the list"<<endl;
		    break;
		    case 1:
		    cout<<"customer arrives"<<endl;
		    int m;
		    m=q.remove();
		    if(m==-1)cout<<"no taxi available"<<endl;
		    else cout<<m<< "alloted to the customer "<<endl;
		}
		q.status();
	}
	cout<<"continue simulatipn ?"<<endl;
	cin>>flag;
}
return 0;
}
