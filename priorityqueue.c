#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct queue{
	int data;
	int pr;
};
struct queue arr[MAX];
int c=0;
void enqueue(int data,int pr){
	if(c==MAX){
		printf("queue is full\n");
		return;
	}
	c++;
	arr[c].data=data;
	arr[c].pr=pr;
	printf("%d is inserted\n",arr[c].data);
	
}
void dequeue(){
	if(c==0){
		printf("Queue is empty\n");
		return;
	}
	int hig=0;
	for(int i=0;i<=c;i++){
		if(arr[i].pr>arr[hig].pr){
			hig=i;
		}
	}
	printf("\n%d with priority %d is deleted\n",arr[hig].data,arr[hig].pr);
	for (int i=hig;i<=c;i++){
		arr[i]=arr[i+1];
	}
	c--;
}
void display(){
	if(c==0){
		printf("Queue is empty\n");
		return;
	}
	printf("DATA\tPRIORITY\n");
	for(int i=0;i<=c;i++){
		printf("%d\t%d\n",arr[i].data,arr[i].pr);
	}
}
int main(){
	int data,ch,pr;
	do{
		printf("\n===PRIORITY QUEUE===");
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:{
				printf("Enter Number : ");
				scanf("%d",&data);
				printf("Enter Priority : ");
				scanf("%d",&pr);				
				enqueue(data,pr);
				break;
			}
			case 2:{
				dequeue();
				break;
			}
			case 3:{
				display();
				break;
			}
			case 4:{
				printf("Exiting......\n");
				break;
			}
		}
	}
	while(ch!=4);
	return 0;
	
}
