#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int cq[MAX];
int front=-1,rear=-1;
void enqueue(int data){
	if((rear+1)%MAX==front){
		printf("Queue is FULL\n");
		return;
	}
	if(front==-1){
		front=0;
		rear++;
		cq[rear]=data;
	}
	else{
		rear=(rear+1)%MAX;
		cq[rear]=data;
	}
	printf("%d is inserted\n",data);
}
void dequeue(){
	if(front==-1){
		printf("Queue is Empty\n");
		return;
	}
	int t=front;
	if(front==rear){
		
		front=-1;
		rear=-1;
	}
	else{
		front=(front+1)%MAX;
	}
	printf("%d is Deleted\n",cq[t]);
}
void display(){
	if(front==-1){
		printf("Queue is Empty\n");
		return;
	}
	int temp = front;
	printf("Queue elements: ");
	do {
		printf(" %d |", cq[temp]);
		temp = (temp + 1) % MAX;
	}
	while(temp != (rear + 1) % MAX);
	printf("\n");
}
int main(){
	int data,ch;
	do{
		printf("\n===CIRCULAR QUEUE USING ARRAY===");
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:{
				printf("Enter Number : ");
				scanf("%d",&data);
				enqueue(data);
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