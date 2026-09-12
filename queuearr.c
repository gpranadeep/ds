#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1;
void enqueue(int data){
	if(rear==MAX-1){
		printf("Queue Overflow\n");
		return;
	}
	if(front==-1){
		rear++;
		queue[rear]=data;
		front=rear;
	}
	else{
		rear++;
		queue[rear]=data;
	}
	printf("%d is inserted\n",data);
}
void dequeue(){
	if(front==-1){
		printf("Queue Underflow\n");
		return;
	}
	if(front==rear){
		printf("%d is deleted\n",queue[front]);
		front=-1;
		rear=-1;
	}
	else{
		printf("%d is deleted\n",queue[front]);
		front++;
	}
}
void display(){
	if(front==-1){
		printf("Queue Underflow\n");
		return;
	}
	printf("QUEUE : ");
	int temp=front;
	while(temp!=rear){
		printf(" %d |",queue[temp]);
		temp++;
	}
	printf(" %d ",queue[temp]);
}
int main(){
	int data,ch;
	do{
		printf("\n===QUEUE USING ARRAYS===");
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
